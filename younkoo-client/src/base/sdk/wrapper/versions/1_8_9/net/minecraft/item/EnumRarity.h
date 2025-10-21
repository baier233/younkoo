#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/util/EnumChatFormatting.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF(EnumRarity, return SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"))

JNI::Field<EnumRarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"), "UNCOMMON")
)> UNCOMMON{ *this };/* Lnet/minecraft/item/EnumRarity; */

JNI::Field<EnumRarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"), "RARE")
)> RARE{ *this };/* Lnet/minecraft/item/EnumRarity; */

JNI::Field<EnumRarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"), "EPIC")
)> EPIC{ *this };/* Lnet/minecraft/item/EnumRarity; */

JNI::Field<EnumChatFormatting, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"), "rarityColor")
)> rarityColor{ *this };/* Lnet/minecraft/util/EnumChatFormatting; */

END_KLASS_DEF();
END_1_8_9