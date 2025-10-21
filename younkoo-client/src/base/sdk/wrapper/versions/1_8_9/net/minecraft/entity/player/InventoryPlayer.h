#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/entity/EntityLivingBase.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF(InventoryPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"))
JNI::Field<JNI::Array<ItemStack>, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"), "mainInventory")
)> mainInventory{ *this };/* [Lnet/minecraft/item/ItemStack; */

JNI::Field<JNI::Array<ItemStack>, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"), "armorInventory")
)> armorInventory{ *this };/* [Lnet/minecraft/item/ItemStack; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/InventoryPlayer"), "currentItem")
)> currentItem{ *this };/* I */

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/InventoryPlayer", "getStackInSlot", "(I)Lnet/minecraft/item/ItemStack;").first
), jint> getStackInSlot{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/InventoryPlayer", "getCurrentItem", "()Lnet/minecraft/item/ItemStack;").first
)> getCurrentItem{ *this };

END_KLASS_DEF();
END_1_8_9
