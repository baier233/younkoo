#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/world/IBlockAccess.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/BlockPos.h>
#include <wrapper/versions/1_12_2/net/minecraft/block/state/IBlockState.h>
#include <jdk/Classes.h>

BEGIN_1_12_2
BEGIN_KLASS_DEF_EX(World, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), IBlockAccess)

JNI::Field<JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), "playerEntities")
)> playerEntities{ *this };/* Ljava/util/List; */

JNI::Field<JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/World"), "loadedEntityList")
)> loadedEntityList{ *this };/* Ljava/util/List; */
JNI::Method<IBlockState, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/World", "getBlockState", "(Lnet/minecraft/util/math/BlockPos;)Lnet/minecraft/block/state/IBlockState;").first
), BlockPos> getBlockState{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/World", "isAirBlock", "(Lnet/minecraft/util/math/BlockPos;)Z").first
), BlockPos> isAirBlock{ *this };

END_KLASS_DEF()
END_1_12_2