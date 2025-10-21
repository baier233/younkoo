#pragma once

#include <SDK.hpp>
BEGIN_1_8_9

BEGIN_KLASS_DEF(MovementInput, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"))
JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"), "moveStrafe")
)> moveStrafe{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"), "moveForward")
)> moveForward{ *this };/* F */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"), "jump")
)> jump{ *this };/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"), "sneak")
)> sneak{ *this };/* Z */



END_KLASS_DEF();
END_1_8_9