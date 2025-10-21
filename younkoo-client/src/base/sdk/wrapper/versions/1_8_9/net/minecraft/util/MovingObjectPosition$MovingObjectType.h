#pragma once
#include <SDK.hpp>

BEGIN_1_8_9
BEGIN_KLASS_DEF(MovingObjectPosition$MovingObjectType, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition$MovingObjectType"))
JNI::Field<MovingObjectPosition$MovingObjectType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition$MovingObjectType"), "MISS")
)> MISS{ *this };/* Lnet/minecraft/util/MovingObjectPosition$MovingObjectType; */

JNI::Field<MovingObjectPosition$MovingObjectType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition$MovingObjectType"), "BLOCK")
)> BLOCK{ *this };/* Lnet/minecraft/util/MovingObjectPosition$MovingObjectType; */

JNI::Field<MovingObjectPosition$MovingObjectType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition$MovingObjectType"), "ENTITY")
)> ENTITY{ *this };/* Lnet/minecraft/util/MovingObjectPosition$MovingObjectType; */
END_KLASS_DEF()
END_1_8_9