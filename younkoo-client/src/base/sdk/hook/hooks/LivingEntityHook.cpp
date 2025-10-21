#include "LivingEntityHook.h"

#include <ripterms/javahook/JavaHook.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>
#include <wrapper/versions/1_18_1/net/minecraftforge/common/ForgeHooks.h>
#include <base/Younkoo.hpp>
#include <base/event/Events.h>
#include <base/features/modules/common/CommonData.h>

static void detour_jump_from_ground(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	if (!thread || !frame) return;
	JNI::set_thread_env(thread->get_jni_environment());

	auto player = Wrapper::Minecraft::getMinecraft().getPlayer();
	auto world = Wrapper::Minecraft::getMinecraft().getWorld();
	if (player.isNULL()) return;
	if (world.isNULL()) return;

	auto entity_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 0);

	V1_18_1::LivingEntity entity_wrap(entity_obj, true);

	if (entity_wrap.isNULL())
		return;
	Wrapper::EntityLivingBase entity(entity_wrap);

	if (entity.isNULL() || player.isNULL() || entity.getEntityID() != player.getEntityID())
		return;

	auto angle = entity.getAngles().yRot;
	auto event = EventJump{ .yaw = angle };
	Younkoo::get().EventBus->fire_event(event);
	angle = event.yaw;
	LOG("On Jump :" << angle);
	double d0 = (double)entity_wrap.getJumpPower() + entity_wrap.getJumpBoostPower();
	auto vec3 = entity_wrap.getDeltaMovement();
	entity.setMotion({ vec3.x.get(), d0, vec3.z.get() });
	if (entity_wrap.isSprinting())
	{
		float f = angle * 0.017453292F;

		entity.setMotion(entity.getMotion() + Math::Vector3D{ (double)(-std::sin(f) * 0.2F), 0.0, (double)(std::cos(f) * 0.2F) });
	}
	entity_wrap.hasImpulse = true;
	V1_18_1::ForgeHooks::static_obj().onLivingJump(entity_wrap);
	*cancel = true;

	//LOG("on channel read 0 ");
}
void LivingEntityHook::hook(const HookManagerData& container)
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

			auto mid = (jmethodID)V1_18_1::LivingEntity::static_obj().jumpFromGround.init();
			Ripterms::JavaHook::hook(mid, detour_jump_from_ground);
		}
	}
	(void)JNI::get_env()->PopLocalFrame(nullptr);


	return;
}
