#pragma once
#include <SDK.hpp>

BEGIN_1_8_9
BEGIN_KLASS_DEF(KeyBinding, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/KeyBinding"))

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/KeyBinding"), "pressed")
)> pressed{ *this };/* Z */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/KeyBinding"), "keyCode")
)> keyCode{ *this };/* I */

END_KLASS_DEF();
END_1_8_9