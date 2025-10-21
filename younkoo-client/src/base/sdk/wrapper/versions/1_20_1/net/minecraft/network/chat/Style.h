#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/TextColor.h>
BEGIN_1_20_1
BEGIN_KLASS_DEF(Style, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/Style"))

JNI::Field<TextColor, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/Style"), "color")
)> color{ *this };/* Lnet/minecraft/network/chat/TextColor; */

END_KLASS_DEF();
END_1_20_1