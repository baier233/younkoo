#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/entity/player/EntityPlayer.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/MovementInput.h>
BEGIN_1_8_9


BEGIN_KLASS_DEF_EX(EntityPlayerSP, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/entity/EntityPlayerSP"), EntityPlayer)


JNI::Field<MovementInput, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/entity/EntityPlayerSP"), "movementInput")
)> movementInput{ *this };/* Lnet/minecraft/util/MovementInput; */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/entity/EntityPlayerSP", "setSprinting", "(Z)V").first
), jboolean> setSprinting{ *this };
END_KLASS_DEF();
END_1_8_9
