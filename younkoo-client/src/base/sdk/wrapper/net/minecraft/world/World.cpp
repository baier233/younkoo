#include "World.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>

#include <wrapper/versions/1_20_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/player/Player.h>

#include <wrapper/versions/1_8_9/net/minecraft/client/multiplayer/WorldClient.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/player/EntityPlayer.h>

#include <wrapper/versions/1_12_2/net/minecraft/client/multiplayer/WorldClient.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/player/EntityPlayer.h>

#include <wrapper/net/minecraft/util/BlockPos.h>

std::vector<Wrapper::EntityPlayer> Wrapper::World::getPlayerList()
{
	std::vector<EntityPlayer> result;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientLevel level = this->getObject();
		auto players = level.players.get();

		if (!players.object_instance) return result;

		auto vec = (/*(JNI::Array<V1_18_1::Player>)*/players.toArray()).to_vector();
		for (auto& obj : vec)
		{
			result.push_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::World world = this->getObject();
		auto players = world.playerEntities.get();
		if (players.isNULL())
		{
			return result;
		}
		auto vec = players.toArray().to_vector();
		for (auto& obj : vec) {
			result.push_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientLevel level = this->getObject();
		auto players = level.players.get();

		if (!players.object_instance) return result;

		auto vec = (/*(JNI::Array<V1_18_1::Player>)*/players.toArray()).to_vector();
		for (auto& obj : vec)
		{
			result.push_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
		return result;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::World world = this->getObject();
		auto players = world.playerEntities.get();
		auto vec = players.toArray().to_vector();
		for (auto& obj : vec) {
			result.push_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
	}
	return result;
}

std::vector<Wrapper::Entity> Wrapper::World::getEntityList()
{
	auto result = std::vector<Entity>();
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientLevel level = this->getObject();
		auto iterator = level.entitiesForRendering().iterator();
		while (iterator.hasNext()) {
			result.push_back(iterator.next());
		}
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::World world = this->getObject();
		auto players = world.loadedEntityList.get();
		auto vec = players.toArray().to_vector();
		for (auto& obj : vec) {
			result.push_back(Wrapper::Entity(JNI::EmptyMembers(obj)));
		}
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientLevel level = this->getObject();
		auto iterator = level.entitiesForRendering().iterator();
		while (iterator.hasNext()) {
			result.push_back(iterator.next());
		}
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::World world = this->getObject();
		auto players = world.loadedEntityList.get();
		auto vec = players.toArray().to_vector();
		for (auto& obj : vec) {
			result.push_back(Wrapper::Entity(JNI::EmptyMembers(obj)));
		}
	}
	return result;
}

Wrapper::BlockState Wrapper::World::getBlockState(const Math::Vector3D& pos)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Level level = this->getObject();
		V1_18_1::BlockPos blockPos = V1_18_1::BlockPos::create(pos);
		return level.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::World world = this->getObject();
		V1_8_9::BlockPos blockPos = V1_8_9::BlockPos::create(pos);
		return world.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Level level = this->getObject();
		V1_20_1::BlockPos blockPos = V1_20_1::BlockPos::create(pos);
		return level.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::World world = this->getObject();
		V1_12_2::BlockPos blockPos = V1_12_2::BlockPos::create(pos);
		return world.getBlockState(blockPos);
	}
	return BlockState();
}

Wrapper::BlockState Wrapper::World::getBlockState(const BlockPos& pos)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Level level = this->getObject();
		V1_18_1::BlockPos blockPos = pos.getObject();
		return level.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::World world = this->getObject();
		V1_8_9::BlockPos blockPos = pos.getObject();
		return world.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Level level = this->getObject();
		V1_20_1::BlockPos blockPos = pos.getObject();
		return level.getBlockState(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::World world = this->getObject();
		V1_12_2::BlockPos blockPos = pos.getObject();
		return world.getBlockState(blockPos);
	}
	return BlockState();
}
Wrapper::IBlockState Wrapper::World::getIBlockState(const BlockPos& pos)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::World world = this->getObject();
		V1_8_9::BlockPos blockPos = pos.getObject();
		return world.getBlockState(blockPos);
	}
	return IBlockState();
}
bool Wrapper::World::isAirBlock(const Math::Vector3D& pos)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::World world = this->getObject();
		V1_12_2::BlockPos blockPos = V1_12_2::BlockPos::create(pos);
		return world.isAirBlock(blockPos);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::World world = this->getObject();
		V1_8_9::BlockPos blockPos = V1_8_9::BlockPos::create(pos);
		return world.isAirBlock(blockPos);
	}
	return false;
}
//TODO:189 and 112
Wrapper::Chunk Wrapper::World::getChunk(int x, int z)
{

	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Level level = this->getObject();
		return level.getChunk(x, z);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Level level = this->getObject();
		return level.getChunk(x, z);
	}
	return Chunk();
}
