#pragma once
#include <SDK.hpp>
#include <jdk/Classes.h>

BEGIN_1_8_9
BEGIN_KLASS_DEF(ActiveRenderInfo, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/ActiveRenderInfo"))
JNI::Field<JDK::IntBuffer, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/ActiveRenderInfo"), "VIEWPORT")
)> VIEWPORT{ *this };/* Ljava/nio/IntBuffer; */

JNI::Field<JDK::FloatBuffer, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/ActiveRenderInfo"), "MODELVIEW")
)> MODELVIEW{ *this };/* Ljava/nio/FloatBuffer; */

JNI::Field<JDK::FloatBuffer, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/ActiveRenderInfo"), "PROJECTION")
)> PROJECTION{ *this };/* Ljava/nio/FloatBuffer; */
END_KLASS_DEF();
END_1_8_9