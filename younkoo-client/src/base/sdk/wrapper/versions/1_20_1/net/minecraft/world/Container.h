#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF(Container, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/Container"))

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/Container", "getContainerSize", "()I").first
)> getContainerSize{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/Container", "getItem", "(I)Lnet/minecraft/world/item/ItemStack;").first
), jint> getItem{ *this };

END_KLASS_DEF();

END_1_20_1