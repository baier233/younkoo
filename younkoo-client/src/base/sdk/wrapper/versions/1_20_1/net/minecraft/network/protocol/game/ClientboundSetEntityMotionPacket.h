#pragma once

#include <SDK.hpp>

BEGIN_1_20_1
BEGIN_KLASS_DEF(ClientboundSetEntityMotionPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"))
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"), "id")
)> id{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"), "xa")
)> xa{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"), "ya")
)> ya{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"), "za")
)> za{ *this };/* I */

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getId", "()I").first
)> getId{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getXa", "()I").first
)> getXa{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getYa", "()I").first
)> getYa{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getZa", "()I").first
)> getZa{ *this };

END_KLASS_DEF();
END_1_20_1