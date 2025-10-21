#include "ContainerChest.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/inventory/ChestMenu.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/inventory/ChestMenu.h>
#include <Wrapper/versions/1_8_9/net/minecraft/inventory/ContainerChest.h>
#include <Wrapper/versions/1_12_2/net/minecraft/inventory/ContainerChest.h>

jclass Wrapper::ContainerChest::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::ChestMenu::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		static auto klass = V1_8_9::ContainerChest::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::ChestMenu::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		static auto klass = V1_12_2::ContainerChest::static_obj().init();
		return klass;
	}
	return jclass();
}

Wrapper::IInventory Wrapper::ContainerChest::lowerChestInventory()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ChestMenu obj = this->getObject();
		return obj.container.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::ContainerChest obj = this->getObject();
		return obj.lowerChestInventory.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ChestMenu obj = this->getObject();
		return obj.container.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::ContainerChest obj = this->getObject();
		return obj.lowerChestInventory.get();
	}
	return IInventory();
}

int Wrapper::ContainerChest::windowId()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ChestMenu obj = this->getObject();
		return obj.containerId.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ChestMenu obj = this->getObject();
		return obj.containerId.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::ContainerChest obj = this->getObject();
		return obj.windowId.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::ContainerChest obj = this->getObject();
		return obj.windowId.get();
	}
	return -1;
}
