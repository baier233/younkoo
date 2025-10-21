#pragma once
#include <SDK.hpp>
#include "../EntityLivingBase.h"
#include <wrapper/versions/1_12_2/net/minecraft/inventory/Container.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/player/InventoryPlayer.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF_EX(EntityPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), EntityLivingBase)
JNI::Field<Container, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), "openContainer")
)> openContainer{ *this };/* Lnet/minecraft/inventory/Container; */
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/player/EntityPlayer", "jump", "()V").first
)> jump{ *this };

JNI::Field<InventoryPlayer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/player/EntityPlayer"), "inventory")
)> inventory{ *this };/* Lnet/minecraft/entity/player/InventoryPlayer; */

END_KLASS_DEF()
END_1_12_2