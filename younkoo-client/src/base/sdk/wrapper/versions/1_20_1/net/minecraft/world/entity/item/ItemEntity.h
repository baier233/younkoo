#pragma once

#include <SDK.hpp>


#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(ItemEntity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/item/ItemEntity"))

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/item/ItemEntity", "getItem", "()Lnet/minecraft/world/item/ItemStack;").first
)> getItem{ *this };

END_KLASS_DEF()
END_1_20_1