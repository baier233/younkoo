#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientPacketListener.h>
BEGIN_1_18_1
BEGIN_KLASS_DEF(TextColor, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/TextColor"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/TextColor"), "value")
)> value{ *this };/* I */

JNI::Field<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/TextColor"), "name")
)> name{ *this };/* Ljava/lang/String; */

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/TextColor", "formatValue", "()Ljava/lang/String;").first
)> formatValue{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/TextColor", "hashCode", "()I").first
)> hashCode{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/TextColor", "toString", "()Ljava/lang/String;").first
)> toString{ *this };

JNI::Method<TextColor, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/TextColor", "fromRgb", "(I)Lnet/minecraft/network/chat/TextColor;").first
), jint> fromRgb{ *this };

JNI::Method<TextColor, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/TextColor", "parseColor", "(Ljava/lang/String;)Lnet/minecraft/network/chat/TextColor;").first
), String> parseColor{ *this };

JNI::Method<ClientPacketListener, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getConnection", "()Lnet/minecraft/client/multiplayer/ClientPacketListener;").first
)> getConnection{ *this };
END_KLASS_DEF();
END_1_18_1