#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ServerboundPlayerCommandPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket"))
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket"), "id")
)> id{ *this };/* I */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket"), "action")
)> action{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket"), "data")
)> data{ *this };/* I */



JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket", "getId", "()I").first
)> getId{ *this };

JNI::Method<ServerboundPlayerCommandPacket$Action, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket", "getAction", "()Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action;").first
)> getAction{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket", "getData", "()I").first
)> getData{ *this };


JNI::ConstructorMethod< Entity, ServerboundPlayerCommandPacket$Action> constructor_0{ *this };
static inline ServerboundPlayerCommandPacket create(Entity entity, ServerboundPlayerCommandPacket$Action action) {
	return ServerboundPlayerCommandPacket::new_object(&ServerboundPlayerCommandPacket::constructor_0, entity, action);
}

END_KLASS_DEF();
END_1_18_1