#include "EntityHook.h"

#include <ripterms/javahook/JavaHook.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>
#include <base/Younkoo.hpp>
#include <base/event/Events.h>
#include <base/features/modules/common/CommonData.h>

static void detour_move_relative(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	JNI::set_thread_env(thread->get_jni_environment());

	auto player = Wrapper::Minecraft::getMinecraft().getPlayer();
	auto world = Wrapper::Minecraft::getMinecraft().getWorld();
	if (player.isNULL()) return;
	if (world.isNULL()) return;

	auto entity_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 0);
	if (!entity_obj) return;
	auto friction = Ripterms::JavaHook::get_primitive_param_at<jfloat>(frame, 1);
	auto p_19922_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 2);
	if (!p_19922_obj) return;
	V1_18_1::Entity entity_wrap(entity_obj, true);
	if (entity_wrap.isNULL() || !entity_wrap.is_instance_of<V1_18_1::LocalPlayer>())
		return;
	V1_18_1::Vec3 vec3(p_19922_obj, true);
	if (vec3.isNULL()) return;


	Wrapper::Entity entity(entity_wrap);

	auto yaw = entity.getAngles().yRot;
	auto event = EventStrafe{ .forward = (float)vec3.z.get(),.strafe = (float)vec3.x.get(),.friction = friction, .yaw = yaw };
	Younkoo::get().EventBus->fire_event(event);
	vec3.z.set(event.forward);
	vec3.x.set(event.strafe);
	entity_wrap.setYRot(event.yaw);

}
void EntityHook::hook(const HookManagerData& container)
{

	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for Entity ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;



	(void)JNI::get_env()->PushLocalFrame(66);
	{
		jclass klass = JNI::find_class(V1_18_1::Entity::get_name());

		JVM::get().jvmti->RetransformClasses(1, &klass);
		{

			auto mid = (jmethodID)V1_18_1::Entity::static_obj().moveRelative.init();
			Ripterms::JavaHook::hook(mid, detour_move_relative);
		}
	}
	(void)JNI::get_env()->PopLocalFrame(nullptr);


	return;
}
