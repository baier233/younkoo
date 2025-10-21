#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_20_1/com/mojang/blaze3d/platform/Window.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/gui/screens/Screen.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/player/LocalPlayer.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/phys/HitResult.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/Options.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/multiplayer/MultiPlayerGameMode.h>
BEGIN_1_20_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))
JNI::Field<Minecraft, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance")
)> instance{ *this};/* Lnet/minecraft/client/Minecraft; */

JNI::Field<Window, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "window")
)> window{ *this};/* Lcom/mojang/blaze3d/platform/Window; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "launchedVersion")
)> launchedVersion{ *this};/* Ljava/lang/String; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "versionType")
)> versionType{ *this};/* Ljava/lang/String; */

JNI::Field<Screen, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen")
)>screen{ *this };

JNI::Field < ClientLevel, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "level")
)> level{ *this };/* Lnet/minecraft/client/multiplayer/ClientLevel; */

JNI::Field <LocalPlayer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "player")
)> player{ *this };/* Lnet/minecraft/client/player/LocalPlayer; */

JNI::Field<HitResult, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult")
)> hitResult{ *this };/* Lnet/minecraft/world/phys/HitResult; */

JNI::Field<Options, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "options")
)> options{ *this };/* Lnet/minecraft/client/Options; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "missTime")
)> missTime{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fps")
)> fps{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "rightClickDelay")
)> rightClickDelay{ *this };/* I */

JNI::Field<MultiPlayerGameMode, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameMode")
)> gameMode{ *this };/* Lnet/minecraft/client/multiplayer/MultiPlayerGameMode; */

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first
)>getInstance{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTime", "()F").first
)> getFrameTime{ *this };

END_KLASS_DEF();

END_1_20_1