﻿#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/Item.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/Rarity.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(ItemStack, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/ItemStack"))

JNI::Method<Item, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "getItem", "()Lnet/minecraft/world/item/Item;").first
)> getItem{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "getDestroySpeed", "(Lnet/minecraft/world/level/block/state/BlockState;)F").first
), BlockState> getDestroySpeed{ *this };

JNI::Method<Rarity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "getRarity", "()Lnet/minecraft/world/item/Rarity;").first
)> getRarity{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "isEmpty", "()Z").first
)> isEmpty{ *this };

END_KLASS_DEF();
END_1_18_1;