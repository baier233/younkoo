#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/world/inventory/ClickType.h>
#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>

BEGIN_WRAP
class PlayerController :public Object {
public:
	using Object::Object;
	void handleInventoryMouseClick(int k, int l, int m, ClickType arg, EntityPlayer arg2);
	bool isHittingBlock();
};

END_WRAP