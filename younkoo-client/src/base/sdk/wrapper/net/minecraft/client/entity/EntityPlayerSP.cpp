#include "EntityPlayerSP.h"
#include "wrapper/net/minecraft/util/MovementInput.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/entity/EntityPlayerSP.h>
#include <wrapper/versions/1_12_2/net/minecraft/client/entity/EntityPlayerSP.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/player/LocalPlayer.h>

Wrapper::MovementInput Wrapper::EntityPlayerSP::getMovementInput()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LocalPlayer player = this->getObject();
		return player.input.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityPlayerSP player = this->getObject();
		return player.movementInput.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::LocalPlayer player = this->getObject();
		return player.input.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::EntityPlayerSP player = this->getObject();
		return player.movementInput.get();
	}
	assert("unimplemented version");
	return MovementInput();
}

jclass Wrapper::EntityPlayerSP::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::LocalPlayer::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::LocalPlayer::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		static auto klass = V1_12_2::EntityPlayerSP::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		static auto klass = V1_8_9::EntityPlayerSP::static_obj().init();
		return klass;
	}
	return jclass();
}

void Wrapper::EntityPlayerSP::setSprinting(bool sprinting)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::EntityPlayerSP player = this->getObject();
		player.setSprinting(sprinting);
	}
	else  if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::EntityPlayerSP player = this->getObject();
		player.setSprinting(sprinting);
	}
	assert("unimplemented version");
}

bool Wrapper::EntityPlayerSP::wasSprinting()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::LocalPlayer player = this->getObject();
		return player.wasSprinting.get();
	}
	assert("unimplemented version");
	return false;
}
