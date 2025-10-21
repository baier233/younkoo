#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemStack.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/BlockPos.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/Vec3.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/AxisAlignedBB.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/IChatComponent.h>
BEGIN_1_8_9
BEGIN_KLASS_DEF(Entity, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"))
JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "isSneaking", "()Z").first
)> isSneaking{ *this };

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "entityId")
)> entityId{ *this };/* I */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setSneaking", "(Z)V").first
), jboolean> setSneaking{ *this };

JNI::Method<BlockPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/command/ICommandSender", "getPosition", "()Lnet/minecraft/util/BlockPos;").first
)> getPosition{ *this };

JNI::Method<JNI::Array<ItemStack>, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getInventory", "()[Lnet/minecraft/item/ItemStack;").first
)> getInventory{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "isSprinting", "()Z").first
)> isSprinting{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setSprinting", "(Z)V").first
), jboolean> setSprinting{ *this };
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "lastTickPosX")
)> lastTickPosX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "lastTickPosY")
)> lastTickPosY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "lastTickPosZ")
)> lastTickPosZ{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosX")
)> prevPosX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosY")
)> prevPosY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosZ")
)> prevPosZ{ *this };/* D */

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getEyeHeight", "()F").first
)> getEyeHeight{ *this };


JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "onGround")
)> onGround{ *this };/* Z */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "width")
)> width{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "height")
)> height{ *this };/* F */

JNI::Method<AxisAlignedBB, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getEntityBoundingBox", "()Lnet/minecraft/util/AxisAlignedBB;").first
)> getEntityBoundingBox{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setEntityBoundingBox", "(Lnet/minecraft/util/AxisAlignedBB;)V").first
), AxisAlignedBB> setEntityBoundingBox{ *this };


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setAngles", "(FF)V").first
), jfloat, jfloat> setAngles{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getRotationYawHead", "()F").first
)> getRotationYawHead{ *this };


JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "posX")
)> posX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "posY")
)> posY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "posZ")
)> posZ{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionX")
)> motionX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionY")
)> motionY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionZ")
)> motionZ{ *this };/* D */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "rotationYaw")
)> rotationYaw{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "rotationPitch")
)> rotationPitch{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevRotationYaw")
)> prevRotationYaw{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevRotationPitch")
)> prevRotationPitch{ *this };/* F */


JNI::Method<IChatComponent, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getDisplayName", "()Lnet/minecraft/util/IChatComponent;").first
)> getDisplayName{ *this };

JNI::Method<JDK::java_util::UUID, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getUniqueID", "()Ljava/util/UUID;").first
)> getUniqueID{ *this };

JNI::Field<AxisAlignedBB, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "boundingBox")
)> boundingBox{ *this };/* Lnet/minecraft/util/AxisAlignedBB; */

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getName", "()Ljava/lang/String;").first
)> getName{ *this };

END_KLASS_DEF();
END_1_8_9
