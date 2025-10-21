#pragma once
#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/chat/Style.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(Component, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/Component"))

JNI::Method<Style, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/Component", "getStyle", "()Lnet/minecraft/network/chat/Style;").first
)> getStyle{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/Component", "getString", "()Ljava/lang/String;").first
)> getString{ *this };
END_KLASS_DEF();

END_1_18_1