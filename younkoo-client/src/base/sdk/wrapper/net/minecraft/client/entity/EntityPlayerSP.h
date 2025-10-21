﻿#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>
#include <wrapper/net/minecraft/util/MovementInput.h>

BEGIN_WRAP
class EntityPlayerSP :public EntityPlayer {
public:
	using EntityPlayer::EntityPlayer;
	Wrapper::MovementInput getMovementInput();
	static  jclass klass();
	void setSprinting(bool sprinting);
	bool wasSprinting();
};

END_WRAP