#pragma once

#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(RenderManager, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/entity/RenderManager"))
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/entity/RenderManager"), "renderPosX")
)> renderPosX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/entity/RenderManager"), "renderPosY")
)> renderPosY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/entity/RenderManager"), "renderPosZ")
)> renderPosZ{ *this };/* D */
END_KLASS_DEF();
END_1_8_9