#pragma once
#include <wrapper/Object.h>
#include <SDK.hpp>
#include <wrapper/net/minecraft/inventory/IInventory.h>
BEGIN_WRAP;
class ContainerChest : public Object
{
public:
	using Object::Object;
	static jclass klass();
	Wrapper::IInventory lowerChestInventory();
	int windowId();
};
END_WRAP;
