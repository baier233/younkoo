#pragma once
#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(RayTraceResult$Type, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult$Type"))

JNI::Field<RayTraceResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult$Type"), "MISS")
)> MISS{ *this };/* Lnet/minecraft/util/math/RayTraceResult$Type; */

JNI::Field<RayTraceResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult$Type"), "BLOCK")
)> BLOCK{ *this };/* Lnet/minecraft/util/math/RayTraceResult$Type; */

JNI::Field<RayTraceResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult$Type"), "ENTITY")
)> ENTITY{ *this };/* Lnet/minecraft/util/math/RayTraceResult$Type; */

END_KLASS_DEF();
END_1_12_2