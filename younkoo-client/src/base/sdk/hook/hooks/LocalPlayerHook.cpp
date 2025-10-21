#include "LocalPlayerHook.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>
#include <base/event/Events.h>

static void detour_tick(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	Younkoo::get().EventBus->fire_event(EventUpdate{});
}

void LocalPlayerHook::hook(const HookManagerData& container)
{

	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for LocalPlayer ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;

	(void)JNI::get_env()->PushLocalFrame(66);
	{
		jclass klass = JNI::find_class(V1_18_1::LocalPlayer::get_name());

		JVM::get().jvmti->RetransformClasses(1, &klass);
		{

			auto mid = (jmethodID)V1_18_1::LocalPlayer::static_obj().tick.init();
			Ripterms::JavaHook::hook(mid, detour_tick);
		}
	}
	(void)JNI::get_env()->PopLocalFrame(nullptr);

}
