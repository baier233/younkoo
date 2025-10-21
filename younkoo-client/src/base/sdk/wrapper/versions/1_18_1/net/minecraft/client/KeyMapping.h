#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>
#include <wrapper/versions/1_18_1/com/mojang/blaze3d/platform/InputConstants$Key.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(KeyMapping, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"))

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "isDown")
)> isDown{ *this };/* Z */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "setDown", "(Z)V").first
), jboolean> setDown{ *this };
JNI::Method<InputConstants$Key, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraftforge/client/extensions/IForgeKeyMapping", "getKey", "()Lcom/mojang/blaze3d/platform/InputConstants$Key;").first
)> getKey{ *this };
END_KLASS_DEF();

END_1_18_1