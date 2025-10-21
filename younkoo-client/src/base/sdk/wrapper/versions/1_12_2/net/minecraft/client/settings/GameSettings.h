#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/client/settings/KeyBinding.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF(GameSettings, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"))
JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "fovSetting")
)> fovSetting{ *this };/* F */

JNI::Field<KeyBinding, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "keyBindSneak")
)> keyBindSneak{ *this };/* Lnet/minecraft/client/settings/KeyBinding; */

JNI::Field<KeyBinding, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "keyBindAttack")
)> keyBindAttack{ *this };/* Lnet/minecraft/client/settings/KeyBinding; */

JNI::Field<KeyBinding, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "keyBindUseItem")
)> keyBindUseItem{ *this };/* Lnet/minecraft/client/settings/KeyBinding; */

JNI::Field<KeyBinding, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "keyBindSprint")
)> keyBindSprint{ *this };/* Lnet/minecraft/client/settings/KeyBinding; */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "gammaSetting")
)> gammaSetting{ *this };/* F */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/settings/GameSettings"), "thirdPersonView")
)> thirdPersonView{ *this };/* I */

END_KLASS_DEF();
END_1_12_2