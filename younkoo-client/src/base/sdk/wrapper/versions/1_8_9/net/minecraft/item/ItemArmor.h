#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemStack.h>

BEGIN_1_8_9
BEGIN_KLASS_DEF(ItemArmor, return SRGParser::get().getObfuscatedClassName("net/minecraft/item/ItemArmor"))
JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/item/ItemArmor", "getColor", "(Lnet/minecraft/item/ItemStack;)I").first
), ItemStack> getColor{ *this };
END_KLASS_DEF();
END_1_8_9