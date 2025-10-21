#pragma once
#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(SPacketEntityVelocity, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/SPacketEntityVelocity"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/SPacketEntityVelocity"), "entityID")
)> entityID{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/SPacketEntityVelocity"), "motionX")
)> motionX{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/SPacketEntityVelocity"), "motionY")
)> motionY{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/SPacketEntityVelocity"), "motionZ")
)> motionZ{ *this };/* I */
END_KLASS_DEF();
END_1_12_2
