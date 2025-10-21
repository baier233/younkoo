#include "ItemStack.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/Item.h>

#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/Item.h>

#include <wrapper/versions/1_8_9/net/minecraft/item/ItemStack.h>

#include <wrapper/versions/1_12_2/net/minecraft/item/ItemStack.h>
#include <JVM.hpp>
float Wrapper::ItemStack::getStrVsBlock(const BlockState& state)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ItemStack stack = this->getObject();
		V1_18_1::BlockState blockstate = state.getObject();
		return stack.getDestroySpeed(blockstate);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ItemStack stack = this->getObject();
		V1_20_1::BlockState blockstate = state.getObject();
		return stack.getDestroySpeed(blockstate);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::ItemStack stack = this->getObject();
		V1_12_2::IBlockState blockstate = state.getObject();
		return stack.getDestroySpeed(blockstate);
	}
	return 0.0f;
}

float Wrapper::ItemStack::getStrVsBlock(const Block& block)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::ItemStack stack = this->getObject();
		V1_8_9::Block b = block.getObject();

		/*jclass klass = block.getClassBaseOnObject();
		char* signature;
		JVM::get().jvmti->GetClassSignature(klass, &signature, NULL);

		char* name;
		char* method_sign;
		JVM::get().jvmti->GetMethodName(stack.getStrVsBlock.init(), &name, &method_sign, NULL);

		LOG(signature);
		LOG(name << " desc:" << method_sign);

		return 1.f;*/
		float result = stack.getStrVsBlock(b);
		return result;
	}
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		return 1.f;
	}
	return 0.0f;
}

Wrapper::Item Wrapper::ItemStack::getItem()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ItemStack stack = this->getObject();
		return stack.getItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ItemStack stack = this->getObject();
		return stack.getItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::ItemStack stack = this->getObject();
		return stack.getItem();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::ItemStack stack = this->getObject();
		return stack.getItem();
	}
	return Item();
}


int Wrapper::ItemStack::getColorBasedOnRarity()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ItemStack stack = this->getObject();
		V1_18_1::Rarity rarity = stack.getRarity();
		auto isRare = rarity == rarity.RARE.get() || rarity == rarity.UNCOMMON.get() || rarity == rarity.EPIC.get();
		return /*isRare ?*/ rarity.color.get().color.get().intValue() /*: 0XFFFFFF*/;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ItemStack stack = this->getObject();
		V1_20_1::Rarity rarity = stack.getRarity();
		auto isRare = rarity == rarity.RARE.get() || rarity == rarity.UNCOMMON.get() || rarity == rarity.EPIC.get();
		return /*isRare ?*/ rarity.color.get().color.get().intValue() /*: 0XFFFFFF*/;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::ItemStack stack = this->getObject();
		V1_12_2::EnumRarity rarity = stack.getRarity();
		auto isRare = rarity == rarity.RARE.get() || rarity == rarity.UNCOMMON.get() || rarity == rarity.EPIC.get();
		return /*isRare ?*/ rarity.rarityColor.get().colorIndex.get() /*: 0XFFFFFF*/;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::ItemStack stack = this->getObject();
		V1_8_9::EnumRarity rarity = stack.getRarity();
		auto isRare = rarity == rarity.RARE.get() || rarity == rarity.UNCOMMON.get() || rarity == rarity.EPIC.get();
		return /*isRare ?*/ rarity.rarityColor.get().colorIndex.get() /*: 0XFFFFFF*/;
	}
	return 0;
}
//TODO: 1.8.9 1.12.2
bool Wrapper::ItemStack::isEmpty()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ItemStack stack = this->getObject();
		return stack.isEmpty();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ItemStack stack = this->getObject();
		return stack.isEmpty();
	}
	return false;
}

