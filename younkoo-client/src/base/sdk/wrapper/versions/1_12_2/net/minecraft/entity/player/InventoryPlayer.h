#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/util/NonNullList.h>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemStack.h>


BEGIN_1_12_2
BEGIN_KLASS_DEF(InventoryPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"))
JNI::Field<NonNullList, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"), "armorInventory")
)> armorInventory{ *this };/* Lnet/minecraft/util/NonNullList; */

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/InventoryPlayer", "getStackInSlot", "(I)Lnet/minecraft/item/ItemStack;").first
), jint> getStackInSlot{ *this };

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"), "currentItem")
)> currentItem{ *this };/* I */

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/InventoryPlayer", "getCurrentItem", "()Lnet/minecraft/item/ItemStack;").first
)> getCurrentItem{ *this };

END_KLASS_DEF();
END_1_12_2