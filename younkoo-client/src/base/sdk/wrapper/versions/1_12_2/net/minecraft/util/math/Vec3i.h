#pragma once
#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(Vec3i, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3i"))
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3i"), "x")
)> x{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3i"), "y")
)> y{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3i"), "z")
)> z{ *this };/* I */
END_KLASS_DEF()
END_1_12_2