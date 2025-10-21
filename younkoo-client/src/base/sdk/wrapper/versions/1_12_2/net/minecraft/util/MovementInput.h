#pragma once
#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(MovementInput, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"))

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovementInput"), "moveForward")
)> moveForward{ *this };/* F */

END_KLASS_DEF()
END_1_12_2