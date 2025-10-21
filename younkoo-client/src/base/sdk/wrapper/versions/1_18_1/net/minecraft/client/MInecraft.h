﻿#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/Options.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/gui/screens/Screen.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h>

#include <wrapper/versions/1_18_1/com/mojang/blaze3d/platform/Window.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/MultiPlayerGameMode.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))

JNI::Field < ClientLevel, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "level")
)> level{ *this };/* Lnet/minecraft/client/multiplayer/ClientLevel; */


JNI::Field < LocalPlayer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "player")
)> player{ *this };/* Lnet/minecraft/client/player/LocalPlayer; */

JNI::Field<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance")
)> instance{ *this };

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first
)>getInstance{ *this };

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fps")
)> fps{ *this };/* I */


JNI::Field<Screen, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen")
)>screen{ *this };

JNI::Field<HitResult, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult")
)> hitResult{ *this };/* Lnet/minecraft/world/phys/HitResult; */

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTime", "()F").first
)> getFrameTime{ *this };

JNI::Method<Window, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getWindow", "()Lcom/mojang/blaze3d/platform/Window;").first
)> getWindow{ *this };

JNI::Field<Options, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "options")
)> options{ *this };/* Lnet/minecraft/client/Options; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "rightClickDelay")
)> rightClickDelay{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "missTime")
)> missTime{ *this };/* I */

JNI::Field<MultiPlayerGameMode, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameMode")
)> gameMode{ *this };/* Lnet/minecraft/client/multiplayer/MultiPlayerGameMode; */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "tick", "()V").first
)> tick{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "loadLevel", "(Ljava/lang/String;)V").first
), String> loadLevel{ *this };

JNI::Method<ClientPacketListener, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getConnection", "()Lnet/minecraft/client/multiplayer/ClientPacketListener;").first
)> getConnection{ *this };

END_KLASS_DEF();


END_1_18_1