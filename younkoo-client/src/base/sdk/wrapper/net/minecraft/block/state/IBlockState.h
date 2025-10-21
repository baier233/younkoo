#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/block/Block.h>

BEGIN_WRAP
class IBlockState :public Object {
public:
	using Object::Object;
	Block getBlock();
};

END_WRAP