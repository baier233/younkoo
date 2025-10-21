#pragma once

#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(TextFormatting, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/text/TextFormatting"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/text/TextFormatting"), "colorIndex")
)> colorIndex{ *this };/* I */

END_KLASS_DEF();
END_1_12_2