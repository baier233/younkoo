#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/inventory/ClickType.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(MultiPlayerGameMode, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/MultiPlayerGameMode"))

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/MultiPlayerGameMode", "handleInventoryMouseClick", "(IIILnet/minecraft/world/inventory/ClickType;Lnet/minecraft/world/entity/player/Player;)V").first
), jint, jint, jint, ClickType, Player> handleInventoryMouseClick{ *this };

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/MultiPlayerGameMode"), "isDestroying")
)> isDestroying{ *this };/* Z */

END_KLASS_DEF();
END_1_18_1
