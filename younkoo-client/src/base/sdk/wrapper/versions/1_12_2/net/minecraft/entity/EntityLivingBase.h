#pragma once
#include <SDK.hpp>
#include "Entity.h"
#include "wrapper/versions/1_12_2/net/minecraft/item/ItemStack.h"
BEGIN_1_12_2
BEGIN_KLASS_DEF_EX(EntityLivingBase, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), Entity)

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getHealth", "()F").first
)> getHealth{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getHeldItemMainhand", "()Lnet/minecraft/item/ItemStack;").first
)> getHeldItemMainhand{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getHeldItemOffhand", "()Lnet/minecraft/item/ItemStack;").first
)> getHeldItemOffhand{ *this };

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), "jumpTicks")
)> jumpTicks{ *this };/* I */

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "canEntityBeSeen", "(Lnet/minecraft/entity/Entity;)Z").first
), Entity> canEntityBeSeen{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getMaxHealth", "()F").first
)> getMaxHealth{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/EntityLivingBase", "getAbsorptionAmount", "()F").first
)> getAbsorptionAmount{ *this };

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), "hurtTime")
)> hurtTime{ *this };/* I */

END_KLASS_DEF()
END_1_12_2