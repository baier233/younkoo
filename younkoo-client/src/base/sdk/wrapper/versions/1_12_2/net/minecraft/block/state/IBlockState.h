#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/block/Block.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF(IBlockState, return SRGParser::get().getObfuscatedClassName("net/minecraft/block/state/IBlockState"))

JNI::Method<Block, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/block/state/IBlockState", "getBlock", "()Lnet/minecraft/block/Block;").first
)> getBlock{ *this };

END_KLASS_DEF();
END_1_12_2