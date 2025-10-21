#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include "wrapper/versions/1_8_9/net/minecraft/block/state/IBlockState.h"
#include <wrapper/versions/1_8_9/net/minecraft/util/BlockPos.h>

BEGIN_1_8_9
BEGIN_KLASS_DEF(World, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"))

JNI::Field<JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), "loadedEntityList")
)> loadedEntityList{ *this };/* Ljava/util/List; */
JNI::Field<JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), "loadedTileEntityList")
)> loadedTileEntityList{ *this };/* Ljava/util/List; */

JNI::Field<JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), "playerEntities")
)> playerEntities{ *this };/* Ljava/util/List; */

JNI::Method<IBlockState, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/World", "getBlockState", "(Lnet/minecraft/util/BlockPos;)Lnet/minecraft/block/state/IBlockState;").first
), BlockPos> getBlockState{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/World", "isAirBlock", "(Lnet/minecraft/util/BlockPos;)Z").first
), BlockPos> isAirBlock{ *this };

END_KLASS_DEF();
END_1_8_9
