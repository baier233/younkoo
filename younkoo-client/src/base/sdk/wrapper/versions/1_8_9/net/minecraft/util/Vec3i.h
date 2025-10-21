#pragma once

#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(Vec3i, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3i"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3i"), "x")
)> x{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3i"), "y")
)> y{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3i"), "z")
)> z{ *this };/* I */
JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/Vec3i", "getX", "()I").first
)> getX{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/Vec3i", "getY", "()I").first
)> getY{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/Vec3i", "getZ", "()I").first
)> getZ{ *this };

END_KLASS_DEF();
END_1_8_9
