#pragma once
#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/java/lang/String.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundInteractPacket$Action.h>

BEGIN_1_18_1



BEGIN_KLASS_DEF(ServerboundInteractPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundInteractPacket"))

JNI::Method<ServerboundInteractPacket, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ServerboundInteractPacket", "createAttackPacket", "(Lnet/minecraft/world/entity/Entity;Z)Lnet/minecraft/network/protocol/game/ServerboundInteractPacket;").first
), Entity, jboolean> createAttackPacket{ *this };


END_KLASS_DEF();

END_1_18_1