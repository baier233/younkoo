#include "ConnectionHook.h"
#include <format>
#include <base/Younkoo.hpp>
#include <base/event/Events.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/Connection.h>

static void ResolveChannleRead0(java_hotspot::method* method) {
	const auto constants_pool = method->get_const_method()->get_constants();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());

	auto const_method = method->get_const_method();
	*(std::uint8_t*)(const_method->get_bytecode_start()) = static_cast<std::uint8_t>(java_runtime::bytecodes::_fast_aload_0);

	auto hook_index = 0;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = java_runtime::bytecodes::_fast_aload_0;
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [](break_point_info* bp) -> void
		{
			static std::once_flag flag{};
			std::call_once(flag, [bp] {
				{
					const auto c_m = bp->method->get_const_method();
					const auto entries = c_m->get_local_variable_entries();
					for (auto& entry : entries)
					{
						LOG(<< std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot));
					}
				}
				});
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			(void)JNI::get_env()->PushLocalFrame(99);
			auto o_state = bp->java_thread->get_thread_state();
			HookUtils::o_thread_map[bp->java_thread] = static_cast<JavaThreadState>(o_state);
			auto packet_obj = (jobject)bp->get_parameter(2);
			V1_18_1::Packet packet_wrap(packet_obj, true);
			Wrapper::Packet packet(packet_wrap);
			EventPacket e = EventPacket{
				.packet = packet,
				.type = RECEIVE,
				.cancel = false,
			};

			Younkoo::get().EventBus->fire_event(e);
			if (e.cancel)
			{
				bp->set_spoofed_bytecode(java_runtime::bytecodes::_ret);
			}
			packet_wrap.clear_ref();
			(void)JNI::get_env()->PopLocalFrame(nullptr);
			//LOG("On ChannelRead0" << "addr : " << std::hex << bp->bytecode_address << std::dec);
		});
}

static void ResolveSendPacket(java_hotspot::method* method) {
	const auto constants_pool = method->get_const_method()->get_constants();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());

	auto const_method = method->get_const_method();
	*(std::uint8_t*)(const_method->get_bytecode_start()) = static_cast<std::uint8_t>(java_runtime::bytecodes::_fast_aload_0);

	auto hook_index = 0;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = java_runtime::bytecodes::_fast_aload_0;
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [](break_point_info* bp) -> void
		{
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
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			(void)JNI::get_env()->PushLocalFrame(60);
			auto o_state = bp->java_thread->get_thread_state();
			HookUtils::o_thread_map[bp->java_thread] = static_cast<JavaThreadState>(o_state);
			auto packet_obj = (jobject)bp->get_parameter(1);
			V1_18_1::Packet packet_wrap(packet_obj, true);
			Wrapper::Packet packet(packet_wrap);
			EventPacket e = EventPacket{
				.packet = packet,
				.type = SEND,
				.cancel = false,
			};

			Younkoo::get().EventBus->fire_event(e);
			if (e.cancel)
			{
				bp->set_spoofed_bytecode(java_runtime::bytecodes::_ret);
			}
			packet_wrap.clear_ref();
			(void)JNI::get_env()->PopLocalFrame(nullptr);
			//LOG("On SendPacket" << "addr : " << std::hex << bp->bytecode_address << std::dec);
		});
}
#include <ripterms/javahook/JavaHook.h>
static void detour_channel_read_0(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	JNI::set_thread_env(thread->get_jni_environment());
	(void)JNI::get_env()->PushLocalFrame(99);
	auto packet_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 2);
	V1_18_1::Packet packet_wrap(packet_obj, true);
	Wrapper::Packet packet(packet_wrap);
	EventPacket e = EventPacket{
				.packet = packet,
				.type = RECEIVE,
				.thread = thread,
				.cancel = false,
	};

	Younkoo::get().EventBus->fire_event(e);
	if (e.cancel)
	{
		*cancel = true;
	}
	(void)JNI::get_env()->PopLocalFrame(nullptr);
	//LOG("on channel read 0 ");
}

static void detour_SendPacket(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	JNI::set_thread_env(thread->get_jni_environment());
	auto packet_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 1);
	V1_18_1::Packet packet_wrap(packet_obj, true);
	Wrapper::Packet packet(packet_wrap);
	EventPacket e = EventPacket{
				.packet = packet,
				.type = SEND,
				.cancel = false,
	};

	Younkoo::get().EventBus->fire_event(e);
	if (e.cancel)
	{
		*cancel = true;
	}
	//LOG("on send packet ");
}

void ConnectionHook::hook(const HookManagerData& container)
{
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for Connection ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;


	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::Connection::get_name());

	JVM::get().jvmti->RetransformClasses(1, &klass);
	{

		auto mid = (jmethodID)V1_18_1::Connection::static_obj().channelRead0.init();
		const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
		Ripterms::JavaHook::hook(mid, detour_channel_read_0);
		//methods_being_hooked.emplace_back(method);
		//HookUtils::GenericResolve(method);
		//ResolveChannleRead0(method);
	}
	{
		//(void)JNI::get_env()->PopLocalFrame(nullptr);
		//return;
	}
	{

		auto mid = (jmethodID)V1_18_1::Connection::static_obj().send.init();
		const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
		Ripterms::JavaHook::hook(mid, detour_SendPacket);
		/*auto method = HookUtils::GenericResolve(mid);
		methods_being_hooked.emplace_back(method);
		ResolveSendPacket(method);*/
	}

	(void)JNI::get_env()->PopLocalFrame(nullptr);


}
