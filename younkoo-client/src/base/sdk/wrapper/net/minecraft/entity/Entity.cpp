#include "Entity.h"

#include "wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h"
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/Entity.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/Entity.h>
void Wrapper::Entity::setGlowing(bool value)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		entity.setGlowingTag(value);
		return;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		entity.setGlowingTag(value);
		return;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		//TODO：1.8.9好像没有
		return;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		entity.setGlowing(value);
		return;
	}
	return;
}

Math::Vector3D Wrapper::Entity::getPosition()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.position.get().toVector3();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return Math::Vector3D(entity.posX.get(), entity.posY.get(), entity.posZ.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.position.get().toVector3();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Entity entity = this->getObject();
		return Math::Vector3D(entity.posX.get(), entity.posY.get(), entity.posZ.get());
	}
	return Math::Vector3D();
}

Math::Vector3D Wrapper::Entity::getPosition(float tickDetla)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.xOld.get() + (entity.getX() - entity.xOld.get()) * static_cast<double>(tickDetla),
			entity.yOld.get() + (entity.getY() - entity.yOld.get()) * static_cast<double>(tickDetla),
			entity.zOld.get() + (entity.getZ() - entity.zOld.get()) * static_cast<double>(tickDetla)
		);
	}
	else  if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.prevPosX.get() + (entity.posX.get() - entity.prevPosX.get()) * static_cast<double>(tickDetla),
			entity.prevPosY.get() + (entity.posY.get() - entity.prevPosY.get()) * static_cast<double>(tickDetla),
			entity.prevPosZ.get() + (entity.posZ.get() - entity.prevPosZ.get()) * static_cast<double>(tickDetla)
		);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.xOld.get() + (entity.getX() - entity.xOld.get()) * static_cast<double>(tickDetla),
			entity.yOld.get() + (entity.getY() - entity.yOld.get()) * static_cast<double>(tickDetla),
			entity.zOld.get() + (entity.getZ() - entity.zOld.get()) * static_cast<double>(tickDetla)
		);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.prevPosX.get() + (entity.posX.get() - entity.prevPosX.get()) * static_cast<double>(tickDetla),
			entity.prevPosY.get() + (entity.posY.get() - entity.prevPosY.get()) * static_cast<double>(tickDetla),
			entity.prevPosZ.get() + (entity.posZ.get() - entity.prevPosZ.get()) * static_cast<double>(tickDetla)
		);
	}
	return Math::Vector3D();
}

Math::Vector3D Wrapper::Entity::getLastTickPos()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.xOld.get(),
			entity.yOld.get(),
			entity.zOld.get()
		);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.prevPosX.get(),
			entity.prevPosY.get(),
			entity.prevPosZ.get()
		);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.xOld.get(),
			entity.yOld.get(),
			entity.zOld.get()
		);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return Math::Vector3D(
			entity.prevPosX.get(),
			entity.prevPosY.get(),
			entity.prevPosZ.get()
		);
	}
	return Math::Vector3D();
}

static V1_18_1::Component V1_18_1_getDisplayName(V1_18_1::Entity& entity) {
	return entity.getDisplayName();
}

static V1_20_1::Component V1_20_1_getDisplayName(V1_20_1::Entity& entity) {
	return entity.getDisplayName();
}

static V1_8_9::IChatComponent V1_8_9_getDisplayName(V1_8_9::Entity& entity) {
	return entity.getDisplayName();
}

static V1_12_2::ITextComponent V1_12_2_getDisplayName(V1_12_2::Entity& entity) {
	return entity.getDisplayName();
}
std::string Wrapper::Entity::getDisplayName()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		auto name = entity.getDisplayName();
		if (name.object_instance)
		{
			auto nameStr = name.getString();
			if (nameStr.object_instance)
			{
				return nameStr.toString();
			}
		}
		return "NULL";
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		auto name = entity.getName();
		if (name.object_instance)
		{
			return name.toString();
		}
		return "NULL";
	}
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		auto name = entity.getDisplayName();
		if (name.object_instance)
		{
			auto nameStr = name.getString();
			if (nameStr.object_instance)
			{
				return nameStr.toString();
			}
		}
		return "NULL";
		return V1_20_1_getDisplayName(entity).getString().toString();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		auto name = entity.getName();
		if (name.object_instance)
		{

			return name.toString();

		}
		return "NULL";
	}
	return std::string();
}

Wrapper::Style Wrapper::Entity::getDisplayName_Style()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return V1_18_1_getDisplayName(entity).getStyle();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return V1_20_1_getDisplayName(entity).getStyle();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return V1_12_2_getDisplayName(entity).getStyle();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Entity entity = this->getObject();
		return V1_8_9_getDisplayName(entity).getChatStyle();
	}
	return Style();
}

float Wrapper::Entity::getWidth()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getBbWidth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.width.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getBbWidth();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Entity entity = this->getObject();
		return entity.width.get();
	}
	return 0.0f;
}

float Wrapper::Entity::getHeight()
{
	if (this->getObject() == nullptr) return 0.0f;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{

		V1_18_1::Entity entity = this->getObject();
		return entity.getBbHeight();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.height.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getBbHeight();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Entity entity = this->getObject();
		return entity.height.get();
	}
	return 0.0f;
}

Math::Rotation Wrapper::Entity::getAngles()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		auto rotation = entity.getRotationVector();
		//Yaw is yRot,Pitch is xRot
		return { rotation.x.get(), rotation.y.get() };
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Entity entity = this->getObject();
		return Math::Rotation{ .xRot = entity.rotationPitch.get() , .yRot = entity.rotationYaw.get() };

	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{

		V1_20_1::Entity entity = this->getObject();
		auto rotation = entity.getRotationVector();
		//Yaw is yRot,Pitch is xRot
		return { rotation.x.get(), rotation.y.get() };
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		//Yaw is yRot,Pitch is xRot
		return Math::Rotation{ .xRot = entity.rotationPitch.get() , .yRot = entity.rotationYaw.get() };
	}
	return Math::Rotation();
}

void Wrapper::Entity::setAngles(Math::Vector2 angles)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		angles = { angles.y,angles.x };
		V1_18_1::Entity entity = this->getObject();
		entity.setXRot(angles.x);
		entity.setYRot(angles.y);
		entity.setYHeadRot(angles.y);
		entity.xOld = angles.x;
		entity.yOld = angles.y;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		entity.rotationPitch = angles.y;
		entity.rotationYaw = angles.x;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		angles = { angles.y,angles.x };
		V1_20_1::Entity entity = this->getObject();
		entity.setXRot(angles.x);
		entity.setYRot(angles.y);
		entity.setYHeadRot(angles.y);
		entity.xOld = angles.x;
		entity.yOld = angles.y;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		entity.rotationPitch = angles.y;
		entity.rotationYaw = angles.x;
	}
	return;
}

float Wrapper::Entity::getEyeHeight()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getEyeHeight();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.height.get() * 0.85f;
		//return entity.getEyeHeight();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getEyeHeight();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.height.get() * 0.85f;
	}
	return 0.0f;
}

bool Wrapper::Entity::isOnGround()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.isOnGround();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.onGround.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.onGround();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.onGround.get();
	}
	return false;
}

bool Wrapper::Entity::isSneaking()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.isShiftKeyDown();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.isSneaking();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.isShiftKeyDown();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.isSneaking();
	}
	return false;
}

Math::Vector3D Wrapper::Entity::getMotion()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getDeltaMovement().toVector3();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getDeltaMovement().toVector3();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return Math::Vector3D(entity.motionX.get(), entity.motionY.get(), entity.motionZ.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return Math::Vector3D(entity.motionX.get(), entity.motionY.get(), entity.motionZ.get());
	}
	return Math::Vector3D();
}

void Wrapper::Entity::setMotion(Math::Vector3D motion)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		entity.setDeltaMovement(V1_18_1::Vec3::fromVector3(motion));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		entity.setDeltaMovement(V1_20_1::Vec3::fromVector3(motion));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		entity.motionX.set(motion.x);
		entity.motionY.set(motion.y);
		entity.motionZ.set(motion.z);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		entity.motionX.set(motion.x);
		entity.motionY.set(motion.y);
		entity.motionZ.set(motion.z);
	}
}

void Wrapper::Entity::setSneak(bool value)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		entity.setShiftKeyDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		entity.setSneaking(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		entity.setShiftKeyDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		entity.setSneaking(value);
	}
}

int Wrapper::Entity::getEntityID()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getId();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getId();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.entityId.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.entityId.get();
	}
	return 0;
}

std::string Wrapper::Entity::getUUID()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getStringUUID().toString();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getStringUUID().toString();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.getUniqueID().toString().toString();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.getUniqueID().toString().toString();
	}
	return std::string();
}

Math::Box<double> Wrapper::Entity::getBoundingBox()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getBoundingBox().toBox();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Entity entity = this->getObject();
		return entity.getBoundingBox().toBox();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Entity entity = this->getObject();
		return entity.boundingBox.get().toBox();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Entity entity = this->getObject();
		return entity.boundingBox.get().toBox();
	}
	return Math::Box<double>();
}
