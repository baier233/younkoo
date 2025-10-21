#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/block/Block.h>
BEGIN_1_8_9

BEGIN_KLASS_DEF(BlockState, return SRGParser::get().getObfuscatedClassName("net/minecraft/block/state/BlockState"))
JNI::Field<Block, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/block/state/BlockState"), "block")
)> block{ *this };/* Lnet/minecraft/block/Block; */

END_KLASS_DEF();

END_1_8_9