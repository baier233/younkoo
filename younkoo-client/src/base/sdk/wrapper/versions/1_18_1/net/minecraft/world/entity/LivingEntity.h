#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF_EX(LivingEntity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/LivingEntity"), Entity)

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/LivingEntity"), "noJumpDelay")
)> noJumpDelay{ *this };/* I */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "hasImpulse")
)> hasImpulse{ *this };/* Z */


JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getJumpPower", "()F").first
)> getJumpPower{ *this };
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/LivingEntity"), "hurtTime")
)> hurtTime{ *this };/* I */
JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getJumpBoostPower", "()D").first
)> getJumpBoostPower{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "jumpFromGround", "()V").first
)> jumpFromGround{ *this };
JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getHealth", "()F").first
)> getHealth{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getMainHandItem", "()Lnet/minecraft/world/item/ItemStack;").first
)> getMainHandItem{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getOffhandItem", "()Lnet/minecraft/world/item/ItemStack;").first
)> getOffhandItem{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "canAttack", "(Lnet/minecraft/world/entity/LivingEntity;)Z").first
), LivingEntity> canAttack{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "hasLineOfSight", "(Lnet/minecraft/world/entity/Entity;)Z").first
), Entity> hasLineOfSight{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getMaxHealth", "()F").first
)> getMaxHealth{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getAbsorptionAmount", "()F").first
)> getAbsorptionAmount{ *this };

//JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
//	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/EntityLivingBase"), "hurtTime")
//)> hurtTime{ *this };/* I */
END_KLASS_DEF()
END_1_18_1