#pragma once
#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/java/lang/String.h>

#include <wrapper/versions/1_18_1/net/minecraft/core/SectionPos.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ServerboundPlayerCommandPacket$Action, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"))
JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "PRESS_SHIFT_KEY")
)> PRESS_SHIFT_KEY{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "RELEASE_SHIFT_KEY")
)> RELEASE_SHIFT_KEY{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "STOP_SLEEPING")
)> STOP_SLEEPING{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "START_SPRINTING")
)> START_SPRINTING{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "STOP_SPRINTING")
)> STOP_SPRINTING{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "START_RIDING_JUMP")
)> START_RIDING_JUMP{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "STOP_RIDING_JUMP")
)> STOP_RIDING_JUMP{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "OPEN_INVENTORY")
)> OPEN_INVENTORY{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */

JNI::Field<ServerboundPlayerCommandPacket$Action, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action"), "START_FALL_FLYING")
)> START_FALL_FLYING{ *this };/* Lnet/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action; */


END_KLASS_DEF();

END_1_18_1