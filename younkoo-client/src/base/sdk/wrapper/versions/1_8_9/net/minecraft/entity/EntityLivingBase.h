#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/entity/Entity.h>

BEGIN_1_8_9
BEGIN_KLASS_DEF_EX(EntityLivingBase, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), Entity)

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), "jumpTicks")
)> jumpTicks{ *this };/* I */
JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getAbsorptionAmount", "()F").first
)> getAbsorptionAmount{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "canEntityBeSeen", "(Lnet/minecraft/entity/Entity;)Z").first
), Entity> canEntityBeSeen{ *this };
JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "isPlayerSleeping", "()Z").first
)> isPlayerSleeping{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "setSprinting", "(Z)V").first
), jboolean> setSprinting{ *this };
JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getMaxHealth", "()F").first
)> getMaxHealth{ *this };


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "swingItem", "()V").first
)> swingItem{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getHealth", "()F").first
)> getHealth{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getHeldItem", "()Lnet/minecraft/item/ItemStack;").first
)> getHeldItem{ *this };
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), "hurtTime")
)> hurtTime{ *this };/* I */

END_KLASS_DEF();
END_1_8_9
