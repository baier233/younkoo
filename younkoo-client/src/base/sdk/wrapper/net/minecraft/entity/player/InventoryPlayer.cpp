#include "InventoryPlayer.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Inventory.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/player/Inventory.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/player/InventoryPlayer.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/player/InventoryPlayer.h>

Wrapper::ItemStack Wrapper::InventoryPlayer::getArrmorItem(int index)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Inventory inventory = this->getObject();
		auto arrmors = inventory.armor.get().list.get().toArray().to_vector();
		return arrmors.at(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Inventory inventory = this->getObject();
		auto arrmors = inventory.armor.get().list.get().toArray().to_vector();
		return arrmors.at(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::InventoryPlayer inventory = this->getObject();
		auto arrmors = inventory.armorInventory.get().to_vector();
		return arrmors.at(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		//TODO:不会
		V1_12_2::InventoryPlayer inventory = this->getObject();
		auto arrmors = inventory.armorInventory.get().toArray();
		return arrmors.get(index);
	}
	return ItemStack();
}

Wrapper::ItemStack Wrapper::InventoryPlayer::getStackInSlot(int index)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.getItem(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::InventoryPlayer inventory = this->getObject();
		return inventory.getStackInSlot(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Inventory inventory = this->getObject();
		return inventory.getItem(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::InventoryPlayer inventory = this->getObject();
		return inventory.getStackInSlot(index);
	}
	return ItemStack();
}

void Wrapper::InventoryPlayer::setCurrentItem(int index)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.selected.set(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::InventoryPlayer inventory = this->getObject();
		return inventory.currentItem.set(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Inventory inventory = this->getObject();
		return inventory.selected.set(index);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::InventoryPlayer inventory = this->getObject();
		return inventory.currentItem.set(index);
	}
}

int Wrapper::InventoryPlayer::getCurrentSlot()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.selected.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::InventoryPlayer inventory = this->getObject();
		return inventory.currentItem.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Inventory inventory = this->getObject();
		return inventory.selected.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::InventoryPlayer inventory = this->getObject();
		return inventory.currentItem.get();
	}
	return 0;
}

Wrapper::ItemStack Wrapper::InventoryPlayer::getCurrentItem()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.getSelected();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Inventory inventory = this->getObject();
		return inventory.getSelected();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::InventoryPlayer inventory = this->getObject();
		return inventory.getCurrentItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::InventoryPlayer inventory = this->getObject();
		return inventory.getCurrentItem();
	}
	return ItemStack();
}
