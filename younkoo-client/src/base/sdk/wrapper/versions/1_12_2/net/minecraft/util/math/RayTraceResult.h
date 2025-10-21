#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/RayTraceResult$Type.h>
#include <wrapper/versions/1_12_2/net/minecraft/entity/Entity.h>

BEGIN_1_12_2
BEGIN_KLASS_DEF(RayTraceResult, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult"))

JNI::Field<RayTraceResult$Type, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult"), "typeOfHit")
)> typeOfHit{ *this };/* Lnet/minecraft/util/math/RayTraceResult$Type; */
JNI::Field<Entity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult"), "entityHit")
)> entityHit{ *this };/* Lnet/minecraft/entity/Entity; */

JNI::Method<BlockPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/math/RayTraceResult", "getBlockPos", "()Lnet/minecraft/util/math/BlockPos;").first
)> getBlockPos{ *this };

END_KLASS_DEF();
END_1_12_2