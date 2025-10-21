#pragma once
#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(EnumChatFormatting, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/EnumChatFormatting"))
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/EnumChatFormatting"), "colorIndex")
)> colorIndex{ *this };/* I */
END_KLASS_DEF();
END_1_8_9