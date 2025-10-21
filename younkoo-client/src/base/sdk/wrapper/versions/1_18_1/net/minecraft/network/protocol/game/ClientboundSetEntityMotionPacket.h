#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/core/SectionPos.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ClientboundSetEntityMotionPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket"))

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getXa", "()I").first
)> getXa{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getYa", "()I").first
)> getYa{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getZa", "()I").first
)> getZa{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket", "getId", "()I").first
)> getId{ *this };

END_KLASS_DEF();
END_1_18_1