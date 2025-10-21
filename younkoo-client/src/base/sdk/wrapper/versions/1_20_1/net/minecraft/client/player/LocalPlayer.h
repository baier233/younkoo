#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_20_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/InteractionHand.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/Component.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/player/Input.h>
BEGIN_1_20_1
BEGIN_KLASS_DEF(LocalPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"))

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "POSITION_REMINDER_INTERVAL")
)> POSITION_REMINDER_INTERVAL{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_MAX_TIME")
)> WATER_VISION_MAX_TIME{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_QUICK_TIME")
)> WATER_VISION_QUICK_TIME{ *this };/* I */

JNI::Field<jfloat, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_QUICK_PERCENT")
)> WATER_VISION_QUICK_PERCENT{ *this };/* F */

JNI::Field<jdouble, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "SUFFOCATING_COLLISION_CHECK_SCALE")
)> SUFFOCATING_COLLISION_CHECK_SCALE{ *this };/* D */

JNI::Field<jdouble, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "MINOR_COLLISION_ANGLE_THRESHOLD_RADIAN")
)> MINOR_COLLISION_ANGLE_THRESHOLD_RADIAN{ *this };/* D */

JNI::Field<jfloat, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "DEFAULT_SNEAKING_MOVEMENT_FACTOR")
)> DEFAULT_SNEAKING_MOVEMENT_FACTOR{ *this };/* F */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "permissionLevel")
)> permissionLevel{ *this };/* I */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xLast")
)> xLast{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yLast1")
)> yLast1{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "zLast")
)> zLast{ *this };/* D */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yRotLast")
)> yRotLast{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xRotLast")
)> xRotLast{ *this };/* F */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "lastOnGround")
)> lastOnGround{ *this };/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "crouching")
)> crouching{ *this };/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasShiftKeyDown")
)> wasShiftKeyDown{ *this };/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasSprinting")
)> wasSprinting{ *this };/* Z */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "positionReminder")
)> positionReminder{ *this };/* I */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "flashOnSetHealth")
)> flashOnSetHealth{ *this };/* Z */

JNI::Field<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "serverBrand")
)> serverBrand{ *this };/* Ljava/lang/String; */

JNI::Field<Input, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "input")
)> input{ *this };/* Lnet/minecraft/client/player/Input; */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "sprintTriggerTime")
)> sprintTriggerTime{ *this };/* I */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yBob")
)> yBob{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xBob")
)> xBob{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yBobO")
)> yBobO{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xBobO")
)> xBobO{ *this };/* F */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "jumpRidingTicks")
)> jumpRidingTicks{ *this };/* I */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "jumpRidingScale")
)> jumpRidingScale{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "spinningEffectIntensity")
)> spinningEffectIntensity{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "oSpinningEffectIntensity")
)> oSpinningEffectIntensity{ *this };/* F */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "startedUsingItem")
)> startedUsingItem{ *this };/* Z */

JNI::Field<InteractionHand, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "usingItemHand")
)> usingItemHand{ *this };/* Lnet/minecraft/world/InteractionHand; */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "handsBusy")
)> handsBusy{ *this };/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "autoJumpEnabled")
)> autoJumpEnabled{ *this };/* Z */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "autoJumpTime")
)> autoJumpTime{ *this };/* I */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasFallFlying")
)> wasFallFlying{ *this };/* Z */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "waterVisionTime")
)> waterVisionTime{ *this };/* I */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "showDeathScreen")
)> showDeathScreen{ *this };/* Z */

END_KLASS_DEF();
END_1_20_1