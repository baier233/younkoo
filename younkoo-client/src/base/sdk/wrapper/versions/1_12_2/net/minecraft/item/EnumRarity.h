#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/util/text/TextFormatting.h>
BEGIN_1_12_2
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

JNI::Field<TextFormatting, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/item/EnumRarity"), "rarityColor")
)> rarityColor{ *this };/* Lnet/minecraft/util/text/TextFormatting; */

END_KLASS_DEF()
END_1_12_2