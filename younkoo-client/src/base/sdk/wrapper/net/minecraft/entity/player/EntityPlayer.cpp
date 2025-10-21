#include "EntityPlayer.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/player/Player.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/player/EntityPlayer.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/player/EntityPlayer.h>
bool Wrapper::EntityPlayer::isSameTeam(EntityPlayer& other)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		if (!this->getObject() || this->isNULL()) return false;
		if (!other.getObject() || other.isNULL()) return false;
		V1_18_1::Player player = this->getObject();
		V1_18_1::Player another = other.getObject();
		if (!another.is_instance_of<V1_18_1::Player>()) return false;
		return !player.canHarmPlayer(another);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		//by Codeium
		if (!this->getObject() || this->isNULL()) return false;
		if (!other.getObject() || other.isNULL()) return false;
		V1_8_9::EntityPlayer player = this->getObject();
		V1_8_9::EntityPlayer another = other.getObject();
		if (!another.is_instance_of<V1_8_9::EntityPlayer>()) return false;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		if (!this->getObject() || this->isNULL()) return false;
		if (!other.getObject() || other.isNULL()) return false;
		V1_20_1::Player player = this->getObject();
		V1_20_1::Player another = other.getObject();
		if (!another.is_instance_of<V1_18_1::Player>()) return false;
		return !player.canHarmPlayer(another);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		//by Codeium
		if (!this->getObject() || this->isNULL()) return false;
		if (!other.getObject() || other.isNULL()) return false;
		V1_12_2::EntityPlayer player = this->getObject();
		V1_12_2::EntityPlayer another = other.getObject();
		if (!another.is_instance_of<V1_12_2::EntityPlayer>()) return false;
	}
	return false;
}

jclass Wrapper::EntityPlayer::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::Player::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::Player::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		static auto klass = V1_12_2::EntityPlayer::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		static auto klass = V1_8_9::EntityPlayer::static_obj().init();
		return klass;
	}
	return jclass();
}
//TODO:1.12.2 1.8.9
jmethodID Wrapper::EntityPlayer::attack_id()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto id = V1_18_1::Player::static_obj().attack.init();
		return id;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto id = V1_20_1::Player::static_obj().attack.init();
		return id;
	}
	return jmethodID();
}

Wrapper::InventoryPlayer Wrapper::EntityPlayer::getInventory()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Player player = this->getObject();
		return player.getInventory();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityPlayer player = this->getObject();
		return player.inventory.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Player player = this->getObject();
		return player.getInventory();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityPlayer player = this->getObject();
		return player.inventory.get();
	}
	return InventoryPlayer();
}

void Wrapper::EntityPlayer::jump()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Player player = this->getObject();
		player.jumpFromGround();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Player player = this->getObject();
		player.jumpFromGround();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::EntityPlayer player = this->getObject();
		player.jump();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::EntityPlayer player = this->getObject();
		player.jump();
	}
}

Wrapper::Container Wrapper::EntityPlayer::getOpenContainer()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Player player = this->getObject();
		return player.containerMenu.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityPlayer player = this->getObject();
		return player.openContainer.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Player player = this->getObject();
		return player.containerMenu.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::EntityPlayer player = this->getObject();
		return player.openContainer.get();
	}
	return Container();
}
