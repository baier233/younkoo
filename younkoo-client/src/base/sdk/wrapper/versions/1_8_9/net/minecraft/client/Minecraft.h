#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/client/multiplayer/WorldClient.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/entity/EntityPlayerSP.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/gui/GuiScreen.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/MovingObjectPosition.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/Timer.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/settings/GameSettings.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/renderer/entity/RenderManager.h>

BEGIN_1_8_9


BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))


JNI::Field<EntityPlayerSP, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "thePlayer")
)> thePlayer{ *this };/* Lnet/minecraft/client/entity/EntityPlayerSP; */

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMinecraft", "()Lnet/minecraft/client/Minecraft;").first
)> getMinecraft{ *this };


JNI::Field<WorldClient, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "theWorld")
)> theWorld{ *this };/* Lnet/minecraft/client/multiplayer/WorldClient; */

JNI::Field<GuiScreen, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "currentScreen")
)> currentScreen{ *this };/* Lnet/minecraft/client/gui/GuiScreen; */

JNI::Field<MovingObjectPosition, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "objectMouseOver")
)> objectMouseOver{ *this };/* Lnet/minecraft/util/MovingObjectPosition; */

JNI::Field<GameSettings, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameSettings")
)> gameSettings{ *this };/* Lnet/minecraft/client/settings/GameSettings; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "leftClickCounter")
)> leftClickCounter{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "debugFPS")
)> debugFPS{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "rightClickDelayTimer")
)> rightClickDelayTimer{ *this };/* I */

JNI::Field<Timer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "timer")
)> timer{ *this };/* Lnet/minecraft/util/Timer; */

JNI::Field<RenderManager, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "renderManager")
)> renderManager{ *this };/* Lnet/minecraft/client/renderer/entity/RenderManager; */

END_KLASS_DEF();
END_1_8_9
