#include "IInventory.h"
#include "wrapper/versions/1_8_9/net/minecraft/inventory/Container.h"
#include "wrapper/versions/1_8_9/net/minecraft/inventory/IInventory.h"
#include "wrapper/versions/1_12_2/net/minecraft/inventory/IInventory.h"
int Wrapper::IInventory::getSizeInventory() {
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Container obj = this->getObject();
		return obj.getContainerSize();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::IInventory obj = this->getObject();
		return obj.getSizeInventory();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_18_1::Container obj = this->getObject();
		return obj.getContainerSize();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::IInventory obj = this->getObject();
		return obj.getSizeInventory();
	}
	return 0;
}

Wrapper::ItemStack Wrapper::IInventory::getStackInSlot(int index) {
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Container obj = this->getObject();
		return obj.getItem(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Container obj = this->getObject();
		return obj.getItem(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::IInventory obj = this->getObject();
		return obj.getStackInSlot(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::IInventory obj = this->getObject();
		return obj.getStackInSlot(index);
	}
	return ItemStack();
}