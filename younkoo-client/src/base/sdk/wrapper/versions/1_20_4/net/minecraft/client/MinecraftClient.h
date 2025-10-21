#pragma once

#include <SDK.hpp>

BEGIN_1_20_4

BEGIN_KLASS_DEF(MinecraftClient, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/MinecraftClient"))
JNI::Field<MinecraftClient, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/MinecraftClient"), "instance")
)> instance{ *this };/* Lnet/minecraft/client/MinecraftClient; */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/MinecraftClient"), "currentFps")
)> fps{ *this };/* I */

JNI::Method<MinecraftClient, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/MinecraftClient", "getInstance", "()Lnet/minecraft/client/MinecraftClient;").first
)>getInstance{ *this };

END_KLASS_DEF();

END_1_20_4