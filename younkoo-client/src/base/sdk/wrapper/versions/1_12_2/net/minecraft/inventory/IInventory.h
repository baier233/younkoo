#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemStack.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF(IInventory, return SRGParser::get().getObfuscatedClassName("net/minecraft/inventory/IInventory"))

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/inventory/IInventory", "getSizeInventory", "()I").first
)> getSizeInventory{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/inventory/IInventory", "getStackInSlot", "(I)Lnet/minecraft/item/ItemStack;").first
), jint> getStackInSlot{ *this };

END_KLASS_DEF();
END_1_12_2