#include "BlockPos.h"
#include <wrapper/versions/1_18_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_20_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/BlockPos.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/BlockPos.h>

Wrapper::BlockPos::BlockPos(const Math::Vector3D pos)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		this->instance = std::make_shared<JNI::EmptyMembers>(V1_18_1::BlockPos::create(pos));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		this->instance = std::make_shared<JNI::EmptyMembers>(V1_20_1::BlockPos::create(pos));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		this->instance = std::make_shared<JNI::EmptyMembers>(V1_8_9::BlockPos::create(pos));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		this->instance = std::make_shared<JNI::EmptyMembers>(V1_12_2::BlockPos::create(pos));
	}
}

Wrapper::BlockPos Wrapper::BlockPos::copy(BlockPos other)
{
	BlockPos result{};
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		result.instance = std::make_shared<JNI::EmptyMembers>(V1_18_1::BlockPos(other.getObject(), true));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		result.instance = std::make_shared<JNI::EmptyMembers>(V1_20_1::BlockPos(other.getObject(), true));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		result.instance = std::make_shared<JNI::EmptyMembers>(V1_8_9::BlockPos(other.getObject(), true));
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		result.instance = std::make_shared<JNI::EmptyMembers>(V1_12_2::BlockPos(other.getObject(), true));
	}
	return result;
}
