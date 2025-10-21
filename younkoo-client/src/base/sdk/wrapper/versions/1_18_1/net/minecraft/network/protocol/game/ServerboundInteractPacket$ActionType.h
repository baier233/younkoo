#pragma once
#include <SDK.hpp>

BEGIN_1_18_1


#pragma once

#include <SDK.hpp>

BEGIN_KLASS_DEF(ServerboundInteractPacket$ActionType, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType"))
JNI::Field<ServerboundInteractPacket$ActionType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType"), "INTERACT")
)> INTERACT{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType; */

JNI::Field<ServerboundInteractPacket$ActionType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType"), "ATTACK")
)> ATTACK{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType; */

JNI::Field<ServerboundInteractPacket$ActionType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType"), "INTERACT_AT")
)> INTERACT_AT{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundInteractPacket$ActionType; */

END_KLASS_DEF();

END_1_18_1