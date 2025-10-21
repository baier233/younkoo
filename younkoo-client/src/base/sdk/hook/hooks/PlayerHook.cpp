﻿#include "PlayerHook.h"
#include <format>
#include <base/Younkoo.hpp>
#include <base/event/Events.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
#include <log/LOG.h>
void PlayerHook::hook(const HookManagerData& container)
{
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for Player ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;


	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::Player::get_name());

	JVM::get().jvmti->RetransformClasses(1, &klass);
	auto mid = (jmethodID)V1_18_1::Player::static_obj().attack.init();
	auto method = *reinterpret_cast<java_hotspot::method**>(mid);

	method = HookUtils::GenericResolve(mid);
	methods_being_hooked.emplace_back(method);

	const auto constants_pool = method->get_const_method()->get_constants();

	auto const_method = method->get_const_method();

	auto bytecodes = const_method->get_bytecode();
	const size_t bytecodes_length = bytecodes.size();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());
	std::vector<BytecodeInfo> method_block;
	klasses_dont_compile.push_back(holder_klass);

	{
		int bytecodes_index = 0;
		auto indices = std::views::iota(size_t{ 0 }, bytecodes_length);

		std::ranges::for_each(indices, [&](auto idx) {
			if (bytecodes_index >= bytecodes_length) return;

			const auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes[bytecodes_index]);
			auto opcodes = java_runtime::bytecode(bytecodes.data() + bytecodes_index);
			BytecodeInfo current_bytecode;
			current_bytecode.opcode = bytecode;
			current_bytecode.index = bytecodes_index;

			const auto& name = java_runtime::bytecode_names[bytecode];
			LOG_N("(" << bytecodes_index << ")  " << name << " {");
			FLUSH();
			auto length = opcodes.get_length();

			for (int i = 0; i < length - 1; ++i) {
				int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
				current_bytecode.operands.push_back(operand);
				LOG_N((i == 0 ? "" : " , ") << operand);
				FLUSH();
			}
			method_block.push_back(current_bytecode);
			LOG("}");
			bytecodes_index += length;
			});
	}

	auto& bc_info = method_block.back();
	auto hook_index = bc_info.index;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = static_cast<java_runtime::bytecodes>(bc_info.opcode);
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [mid](break_point_info* bp) -> void
		{
			static std::once_flag flag{};
			std::call_once(flag, [bp] {
				{
					const auto c_m = bp->method->get_const_method();
					const auto entries = c_m->get_local_variable_entries();
					LOG("Handling Player.attack Hook");
					for (auto& entry : entries)
					{
						LOG(std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot));
					}
				}
				});
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			auto o_state = bp->java_thread->get_thread_state();
			HookUtils::o_thread_map[bp->java_thread] = static_cast<JavaThreadState>(o_state);
			//bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);
			auto entity_obj = (jobject)bp->get_parameter(1);
			V1_18_1::Entity entity(entity_obj, true);
			Wrapper::Entity wrapEntitiy(entity);
			//LOG("Fire Attack Event !");
			Younkoo::get().EventBus->fire_event(EventAttack{ wrapEntitiy });
			entity.clear_ref();
			//bp->java_thread->set_thread_state(o_state);

		});

}
