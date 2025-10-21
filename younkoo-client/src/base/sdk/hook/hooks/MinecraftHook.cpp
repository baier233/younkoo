#include "MinecraftHook.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/Minecraft.h>
#include <../features/modules/ModuleManager.h>
#include <../features/modules/common/CommonData.h>
static void detour_tick(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel)
{
	JNI::set_thread_env(thread->get_jni_environment());

	CommonData::get().onUpdate();
	ModuleManager::get().ProcessUpdate();

	//LOG("onTick");

}

static void detour_loadlevel(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel)
{
	JNI::set_thread_env(thread->get_jni_environment());
	LOG("onLoadLevel");
}

void MinecraftHook::hook(const HookManagerData& container)
{
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for Minecraft ");
	auto& methods_being_hooked = container.methods_being_hooked;
	auto& klasses_dont_compile = container.klasses_dont_compile;
	auto& methods_dont_compile = container.methods_dont_compile;
	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::Minecraft::get_name());
	JVM::get().jvmti->RetransformClasses(1, &klass);

	{
		/*auto mid = (jmethodID)V1_18_1::Minecraft::static_obj().tick.init();
		const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
		Ripterms::JavaHook::hook(mid, detour_tick);*/
	}
	{
		auto mid = (jmethodID)V1_18_1::Minecraft::static_obj().loadLevel.init();
		const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
		Ripterms::JavaHook::hook(mid, detour_loadlevel);
	}

	(void)JNI::get_env()->PopLocalFrame(nullptr);
}
