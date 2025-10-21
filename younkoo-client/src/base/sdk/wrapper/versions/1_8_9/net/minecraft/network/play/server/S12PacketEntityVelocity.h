#pragma once
#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(S12PacketEntityVelocity, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/S12PacketEntityVelocity"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/S12PacketEntityVelocity"), "entityID")
)> entityID{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/S12PacketEntityVelocity"), "motionX")
)> motionX{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/S12PacketEntityVelocity"), "motionY")
)> motionY{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/play/server/S12PacketEntityVelocity"), "motionZ")
)> motionZ{ *this };/* I */

END_KLASS_DEF();
END_1_8_9