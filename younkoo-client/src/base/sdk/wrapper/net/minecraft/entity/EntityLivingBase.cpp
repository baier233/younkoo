#include "EntityLivingBase.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/EntityLivingBase.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/EntityLivingBase.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/LivingEntity.h>
float Wrapper::EntityLivingBase::getHealth()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHealth();
	}
	return 0.0f;
}

Wrapper::ItemStack Wrapper::EntityLivingBase::getMainHandItemStack()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getMainHandItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getMainHandItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHeldItemMainhand();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHeldItem();
	}
	return ItemStack();
}

Wrapper::ItemStack Wrapper::EntityLivingBase::getOffhandItemStack()
{
	switch (Younkoo::get().info.major)
	{
	case MajorVersion::MAJOR_1181:
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getOffhandItem();
	}
	case MajorVersion::MAJOR_1201:
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getOffhandItem();
	}
	case MajorVersion::MAJOR_189:
	{
		//TODO:不知道是不是
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHeldItem();
	}
	case MajorVersion::MAJOR_112:
	{
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getHeldItemOffhand();
	}
	default:
		break;
	}
	return ItemStack();
}

void Wrapper::EntityLivingBase::setJumpTicks(int tick)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		livingEntity.noJumpDelay.set(tick);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		livingEntity.jumpTicks.set(tick);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		livingEntity.noJumpDelay.set(tick);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		livingEntity.jumpTicks.set(tick);
	}
}

jclass Wrapper::EntityLivingBase::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static jclass klass = V1_18_1::LivingEntity::static_obj().init();
		return klass;
	}
	return jclass();
}

//TODO: 1.12.2 1.8.9
bool Wrapper::EntityLivingBase::canAttack(const EntityLivingBase& entity)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		V1_18_1::LivingEntity other = entity.getObject();
		return livingEntity.canAttack(other);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		V1_20_1::LivingEntity other = entity.getObject();
		return livingEntity.canAttack(other);
	}

	return false;
}

bool Wrapper::EntityLivingBase::canEntityBeSeen(const Entity& entity)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		V1_18_1::Entity other = entity.getObject();
		return livingEntity.hasLineOfSight(other);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		V1_8_9::Entity other = entity.getObject();
		return livingEntity.canEntityBeSeen(other);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		V1_20_1::Entity other = entity.getObject();
		return livingEntity.hasLineOfSight(other);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		V1_12_2::Entity other = entity.getObject();
		return livingEntity.canEntityBeSeen(other);
	}
	return false;
}

float Wrapper::EntityLivingBase::getMaxHealth()
{

	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getMaxHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getMaxHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getMaxHealth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getMaxHealth();
	}
	return 0.0f;
}

float Wrapper::EntityLivingBase::getAbsorptionAmount()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getAbsorptionAmount();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getAbsorptionAmount();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getAbsorptionAmount();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.getAbsorptionAmount();
	}
	return 0.0f;
}

int Wrapper::EntityLivingBase::getHurtTime()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.hurtTime.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.hurtTime.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		return 0;
		/*V1_20_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.hurtTime.get();*/
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityLivingBase livingEntity = this->getObject();
		return livingEntity.hurtTime.get();
	}
	return 0;
}
