#pragma once
#include <jdk/Classes.h>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/ChatStyle.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF(IChatComponent, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/IChatComponent"))


JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/IChatComponent", "getUnformattedText", "()Ljava/lang/String;").first
)> getUnformattedText{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/IChatComponent", "getFormattedText", "()Ljava/lang/String;").first
)> getFormattedText{ *this };

JNI::Method<ChatStyle, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/IChatComponent", "getChatStyle", "()Lnet/minecraft/util/ChatStyle;").first
)> getChatStyle{ *this };

END_KLASS_DEF();
END_1_8_9
