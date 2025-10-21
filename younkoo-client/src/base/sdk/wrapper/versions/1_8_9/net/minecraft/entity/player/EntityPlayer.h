#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/entity/EntityLivingBase.h>
#include <wrapper/versions/1_8_9/net/minecraft/inventory/Container.h>
#include <wrapper/versions/1_8_9/net/minecraft/entity/player/InventoryPlayer.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF_EX(EntityPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), EntityLivingBase)
JNI::Field<Container, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), "openContainer")
)> openContainer{ *this };/* Lnet/minecraft/inventory/Container; */

JNI::Method<JNI::Array<ItemStack>, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/EntityPlayer", "getInventory", "()[Lnet/minecraft/item/ItemStack;").first
)> getInventory{ *this };

JNI::Field<InventoryPlayer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), "inventory")
)> inventory{ *this };/* Lnet/minecraft/entity/player/InventoryPlayer; */
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/EntityPlayer", "jump", "()V").first
)> jump{ *this };


END_KLASS_DEF();
END_1_8_9
