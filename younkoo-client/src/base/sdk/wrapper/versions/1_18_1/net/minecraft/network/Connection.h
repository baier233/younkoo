#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/Packet.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(ChannelHandlerContext, return "io/netty/channel/ChannelHandlerContext")
END_KLASS_DEF();


BEGIN_KLASS_DEF(Connection, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/Connection"))


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/Connection", "send", "(Lnet/minecraft/network/protocol/Packet;)V").first
), Packet> send{ *this };


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/Connection", "channelRead0", "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V").first
), ChannelHandlerContext, JDK::Object> channelRead0{ *this };

END_KLASS_DEF();
END_1_18_1