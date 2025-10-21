#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include "ItemStack.h"
BEGIN_WRAP
class ItemArmor :public Object {
public:
	static jclass klass();
	int getColor(Wrapper::ItemStack& stack);
};

END_WRAP