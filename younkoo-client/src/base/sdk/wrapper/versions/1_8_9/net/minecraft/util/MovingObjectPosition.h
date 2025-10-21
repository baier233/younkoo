#pragma once
#include <SDK.hpp>
#include "MovingObjectPosition$MovingObjectType.h"
#include "BlockPos.h"
#include "wrapper/versions/1_8_9/net/minecraft/entity/Entity.h"
BEGIN_1_8_9

BEGIN_KLASS_DEF(MovingObjectPosition, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition"))

JNI::Field<MovingObjectPosition$MovingObjectType, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition"), "typeOfHit")
)> typeOfHit{ *this };/* Lnet/minecraft/util/MovingObjectPosition$MovingObjectType; */

JNI::Field<BlockPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition"), "blockPos")
)> blockPos{ *this };/* Lnet/minecraft/util/BlockPos; */

JNI::Field<Entity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/MovingObjectPosition"), "entityHit")
)> entityHit{ *this };/* Lnet/minecraft/entity/Entity; */

END_KLASS_DEF();

END_1_8_9