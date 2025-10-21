#pragma once
#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(Timer, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/Timer"))

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Timer"), "renderPartialTicks")
)> renderPartialTicks{ *this };/* F */

END_KLASS_DEF();
END_1_8_9