#pragma once
#include <wrapper/Object.h>
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/Container.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/Container.h>
#include <wrapper/net/minecraft/item/ItemStack.h>
BEGIN_WRAP;
class IInventory : public Object
{
public:
	using Object::Object;
	int getSizeInventory();
	Wrapper::ItemStack getStackInSlot(int index);
};
END_WRAP;
