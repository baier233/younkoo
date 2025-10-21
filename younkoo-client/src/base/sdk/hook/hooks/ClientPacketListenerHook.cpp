﻿#include "ClientPacketListenerHook.h"


#include <JVM.hpp>

#include <hotspot/java_hook.h>
#include <hotspot/break/byte_code_info.h>
#include <hotspot/classes/compile_task.h>

#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientPacketListener.h>
#include <base/Younkoo.hpp>
#include <base/event/Events.h>
#include <format>
#include <base/features/api/chunk/ChunkSharedFlag.h>
#include <log/LOG.h>
static java_hotspot::method* ResolveHandleChunkBlocksUpdate(jmethodID mid) {

	LOG("\nHooking HandleChunkBlocksUpdate");
	auto method = HookUtils::GenericResolve(mid);

	const auto constants_pool = method->get_const_method()->get_constants();

	auto const_method = method->get_const_method();

	auto bytecodes = const_method->get_bytecode();
	const size_t bytecodes_length = bytecodes.size();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());

	std::vector<BytecodeInfo> method_block;
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
			auto length = opcodes.get_length();

			for (int i = 0; i < length - 1; ++i) {
				int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
				current_bytecode.operands.push_back(operand);
				LOG_N((i == 0 ? "" : " , ") << operand);
			}

			method_block.push_back(current_bytecode);

			LOG("}");
			bytecodes_index += length;
			});
	}

	constexpr int hook_index = 11;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes[hook_index]);
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	LOG("holder_klass :" << holder_klass->get_name());


	auto& bc_info = method_block.back();
	auto* info_2 = jvm_internal::breakpoint_info::create(method, bc_info.index);
	info_2->set_orig_bytecode(bc_info.opcode);
	info->set_next(info);
	holder_klass->set_breakpoints(info_2);

	(void)JNI::get_env()->PopLocalFrame(nullptr);


	LOG(std::format("Original code :{}", static_cast<int>(bytecode)));

	jvm_break_points::set_breakpoint_with_original_code(method, bc_info.index, static_cast<std::uint8_t>(bc_info.opcode), [](break_point_info* bp) -> void {
		//Ret Point
		auto o_state = bp->java_thread->get_thread_state();
		bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);
		static int p_105070_slot = 1;

		static std::once_flag flag{};
		std::call_once(flag, [bp] {
			{
				JNI::set_thread_env(bp->java_thread->get_jni_environment());
				const auto c_m = bp->method->get_const_method();
				const auto entries = c_m->get_local_variable_entries();
				for (auto& entry : entries)
				{
					LOG(std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
						entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot));
					if (entry.name == "p_105070_") p_105070_slot = entry.slot;
				}
			}
			});


		auto packet_obj = (jobject)bp->get_parameter(p_105070_slot);
		V1_18_1::ClientboundSectionBlocksUpdatePacket packet(packet_obj, true);

		auto chunk = packet.sectionPos.get().chunk();

		Younkoo::get().EventBus->fire_event(EventUpdateChunk{ chunk.x.get(),chunk.z.get() });
		ChunkSharedFlag::updating = false;
		packet.clear_ref();
		chunk.clear_ref();

		bp->java_thread->set_thread_state(o_state);
		});


	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [](break_point_info* bp) -> void
		{
			ChunkSharedFlag::updating = true;
		});
	return method;
}

static java_hotspot::method* ResovleHandleForgeLevelChunk(jmethodID mid) {

	LOG("\nHooking HandleForgeLevelChunk");


	auto method = HookUtils::GenericResolve(mid);

	const auto constants_pool = method->get_const_method()->get_constants();

	auto const_method = method->get_const_method();
	*(std::uint8_t*)(const_method->get_bytecode_start()) = static_cast<std::uint8_t>(java_runtime::bytecodes::_fast_aload_0);

	auto bytecodes = const_method->get_bytecode();
	const size_t bytecodes_length = bytecodes.size();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());

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
			auto length = opcodes.get_length();

			for (int i = 0; i < length - 1; ++i) {
				int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
				current_bytecode.operands.push_back(operand);
				LOG_N((i == 0 ? "" : " , ") << operand);
			}

			LOG("}");
			bytecodes_index += length;
			});
	}

	constexpr int hook_index = 0;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes.at(hook_index));
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);
	LOG("holder_klass :" << holder_klass->get_name());

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	LOG(std::format("Original code :{}", static_cast<int>(bytecode)));
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [](break_point_info* bp) -> void
		{
			auto o_state = bp->java_thread->get_thread_state();
			bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			static std::once_flag flag{};
			std::call_once(flag, [bp] {
				{
					const auto c_m = bp->method->get_const_method();
					const auto entries = c_m->get_local_variable_entries();
					for (auto& entry : entries)
					{
						LOG(std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot));
					}
				}
				});


			auto packet_obj = (jobject)bp->get_parameter(1);
			V1_18_1::ClientboundForgetLevelChunkPacket packet(packet_obj, true);

			Younkoo::get().EventBus->fire_event(EventUnloadChunk{ packet.x.get() ,packet.z.get() });

			bp->java_thread->set_thread_state(o_state);
		});
	return method;
}
static java_hotspot::method* ResolveHandleLevelChunkWithLight(jmethodID mid) {

	LOG("\nHooking HandleLevelChunkWithLight");
	auto method = HookUtils::GenericResolve(mid);

	const auto constants_pool = method->get_const_method()->get_constants();

	auto const_method = method->get_const_method();
	*(std::uint8_t*)(const_method->get_bytecode_start()) = static_cast<std::uint8_t>(java_runtime::bytecodes::_fast_aload_0);

	auto bytecodes = const_method->get_bytecode();
	const size_t bytecodes_length = bytecodes.size();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());

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
			auto length = opcodes.get_length();

			for (int i = 0; i < length - 1; ++i) {
				int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
				current_bytecode.operands.push_back(operand);
				LOG_N((i == 0 ? "" : " , ") << operand);
			}

			LOG("}");
			bytecodes_index += length;
			});
	}

	constexpr int hook_index = 0;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes.at(hook_index));
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);
	LOG("holder_klass :" << holder_klass->get_name());

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	LOG(std::format("Original code :{}", static_cast<int>(bytecode)));
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [](break_point_info* bp) -> void
		{
			static std::once_flag flag{};
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			std::call_once(flag, [bp] {
				{

					const auto c_m = bp->method->get_const_method();
					const auto entries = c_m->get_local_variable_entries();
					for (auto& entry : entries)
					{
						LOG(std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot));
					}
				}
				});

			auto o_state = bp->java_thread->get_thread_state();
			bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);
			auto packet_obj = (jobject)bp->get_parameter(1);
			V1_18_1::ClientboundLevelChunkWithLightPacket packet(packet_obj, true);

			Younkoo::get().EventBus->fire_event(EventLoadChunk{ packet.getX(),packet.getZ() });

			bp->java_thread->set_thread_state(o_state);

		});
	return method;
}

void ClientPacketListenerHook::hook(const HookManagerData& container)
{
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for BedRenderer ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;

	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::ClientPacketListener::get_name());



	JVM::get().jvmti->RetransformClasses(1, &klass);
	//klasses_dont_compile.push_back(java_hotspot::instance_klass::get_instance_class(V1_18_1::BedRenderer::static_obj().init()));

	{
		auto mid = (jmethodID)V1_18_1::ClientPacketListener::static_obj().handleChunkBlocksUpdate;
		auto method = ResolveHandleChunkBlocksUpdate(mid);
		methods_being_hooked.emplace_back(method);
	}

	{
		auto mid = (jmethodID)V1_18_1::ClientPacketListener::static_obj().handleForgetLevelChunk;
		auto method = ResovleHandleForgeLevelChunk(mid);
		methods_being_hooked.emplace_back(method);
	}

	{
		auto mid = (jmethodID)V1_18_1::ClientPacketListener::static_obj().handleLevelChunkWithLight;
		auto method = ResolveHandleLevelChunkWithLight(mid);
		methods_being_hooked.emplace_back(method);
	}

}

