#include "MovingObjectPosition.h"

#include <wrapper/net/minecraft/entity/Entity.h>
#include "wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h"
#include "wrapper/versions/1_18_1/net/minecraft/world/phys/EntityHitResult.h"
#include "wrapper/versions/1_18_1/net/minecraft/world/phys/BlockHitResult.h"

#include "wrapper/versions/1_20_1/net/minecraft/world/phys/HitResult.h"
#include "wrapper/versions/1_20_1/net/minecraft/world/phys/EntityHitResult.h"
#include "wrapper/versions/1_20_1/net/minecraft/world/phys/BlockHitResult.h"

#include "wrapper/versions/1_8_9/net/minecraft/util/MovingObjectPosition.h"

#include "wrapper/versions/1_12_2/net/minecraft/util/math/RayTraceResult.h"

std::string Wrapper::MovingObjectPosition::getType()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::HitResult mouseOver = this->getObject();
		auto type = mouseOver.getType();
		if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().BLOCK.get()))
		{
			return "BLOCK";
		}
		else if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().MISS.get())) {
			return "MISS";
		}
		else if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().ENTITY.get())) {
			return "ENTITY";
		}
		return "NULL";
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::HitResult mouseOver = this->getObject();
		auto type = mouseOver.getType();
		if (type.is_same_object(V1_20_1::HitResult$Type::static_obj().BLOCK.get()))
		{
			return "BLOCK";
		}
		else if (type.is_same_object(V1_20_1::HitResult$Type::static_obj().MISS.get())) {
			return "MISS";
		}
		else if (type.is_same_object(V1_20_1::HitResult$Type::static_obj().ENTITY.get())) {
			return "ENTITY";
		}
		return "NULL";
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::MovingObjectPosition mouseOver = this->getObject();
		auto type = mouseOver.typeOfHit;
		if (type.get().is_same_object(V1_8_9::MovingObjectPosition$MovingObjectType::static_obj().BLOCK.get())) {
			return "BLOCK";
		}
		else if (type.get().is_same_object(V1_8_9::MovingObjectPosition$MovingObjectType::static_obj().MISS.get())) {
			return "MISS";
		}
		else if (type.get().is_same_object(V1_8_9::MovingObjectPosition$MovingObjectType::static_obj().ENTITY.get())) {
			return "ENTITY";
		}
		return "NULL";
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::RayTraceResult mouseOver = this->getObject();
		auto type = mouseOver.typeOfHit;
		if (type.get().is_same_object(V1_12_2::RayTraceResult$Type::static_obj().BLOCK.get())) {
			return "BLOCK";
		}
		else if (type.get().is_same_object(V1_12_2::RayTraceResult$Type::static_obj().MISS.get())) {
			return "MISS";
		}
		else if (type.get().is_same_object(V1_12_2::RayTraceResult$Type::static_obj().ENTITY.get())) {
			return "ENTITY";
		}
		return "NULL";
	}
	return "";
}

bool Wrapper::MovingObjectPosition::isTypeOfBlock()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_18_1::HitResult$Type::static_obj().BLOCK.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::MovingObjectPosition mouseOver = this->getObject();
		return mouseOver.typeOfHit.get().is_same_object(V1_8_9::MovingObjectPosition$MovingObjectType::static_obj().BLOCK.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_20_1::HitResult$Type::static_obj().BLOCK.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::RayTraceResult mouseOver = this->getObject();
		return mouseOver.typeOfHit.get().is_same_object(V1_12_2::RayTraceResult$Type::static_obj().BLOCK.get());
	}
	return false;
}

bool Wrapper::MovingObjectPosition::isTypeOfEntity()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_18_1::HitResult$Type::static_obj().ENTITY.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_20_1::HitResult$Type::static_obj().ENTITY.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::MovingObjectPosition mouseOver = this->getObject();
		return mouseOver.typeOfHit.get().is_same_object(V1_8_9::MovingObjectPosition$MovingObjectType::static_obj().ENTITY.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::RayTraceResult mouseOver = this->getObject();
		return mouseOver.typeOfHit.get().is_same_object(V1_12_2::RayTraceResult$Type::static_obj().ENTITY.get());
	}
	return false;
}

Wrapper::Entity Wrapper::MovingObjectPosition::getEntity()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::EntityHitResult mouseOver = this->getObject();
		return mouseOver.getEntity();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::EntityHitResult mouseOver = this->getObject();
		return mouseOver.getEntity();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::MovingObjectPosition mouseOver = this->getObject();
		return mouseOver.entityHit.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::RayTraceResult mouseOver = this->getObject();
		return mouseOver.entityHit.get();
	}
	return Entity();
}

Wrapper::BlockPos Wrapper::MovingObjectPosition::getBlockPos()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::BlockHitResult mouseOver = this->getObject();
		return mouseOver.getBlockPos();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::MovingObjectPosition mouseOver = this->getObject();
		return mouseOver.blockPos.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::BlockHitResult mouseOver = this->getObject();
		return mouseOver.getBlockPos();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::RayTraceResult mouseOver = this->getObject();
		return mouseOver.getBlockPos();
	}
	return BlockPos();
}
