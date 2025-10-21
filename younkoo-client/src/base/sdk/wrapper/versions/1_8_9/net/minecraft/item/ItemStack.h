#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/world/World.h>
#include <wrapper/versions/1_8_9/net/minecraft/block/Block.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/Item.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/EnumRarity.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF(ItemStack, return SRGParser::get().getObfuscatedClassName("net/minecraft/item/ItemStack"))

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/item/ItemStack", "getStrVsBlock", "(Lnet/minecraft/block/Block;)F").first
), Block> getStrVsBlock{ *this };

JNI::Method<Item, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/item/ItemStack", "getItem", "()Lnet/minecraft/item/Item;").first
)> getItem{ *this };

JNI::Method<EnumRarity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/item/ItemStack", "getRarity", "()Lnet/minecraft/item/EnumRarity;").first
)> getRarity{ *this };
END_KLASS_DEF();
END_1_8_9
