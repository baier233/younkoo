#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/inventory/ClickType.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/inventory/ClickType.h>
BEGIN_WRAP
class ClickType :public Object {
public:
	using Object::Object;
	static ClickType QUICKMOVE();
};

END_WRAP