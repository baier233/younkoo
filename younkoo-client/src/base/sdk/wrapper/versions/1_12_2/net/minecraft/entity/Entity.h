#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemStack.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/text/ITextComponent.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/AxisAlignedBB.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF(Entity, return SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"))

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setGlowing", "(Z)V").first
), jboolean> setGlowing{ *this };
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
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosX")
)> prevPosX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosY")
)> prevPosY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "prevPosZ")
)> prevPosZ{ *this };/* D */

JNI::Method<ITextComponent, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getDisplayName", "()Lnet/minecraft/util/text/ITextComponent;").first
)> getDisplayName{ *this };

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "width")
)> width{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "height")
)> height{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "rotationYaw")
)> rotationYaw{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "rotationPitch")
)> rotationPitch{ *this };/* F */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "onGround")
)> onGround{ *this };/* Z */

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "isSneaking", "()Z").first
)> isSneaking{ *this };

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionX")
)> motionX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionY")
)> motionY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "motionZ")
)> motionZ{ *this };/* D */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "setSneaking", "(Z)V").first
), jboolean> setSneaking{ *this };
JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "entityId")
)> entityId{ *this };/* I */

JNI::Method<JDK::java_util::UUID, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getUniqueID", "()Ljava/util/UUID;").first
)> getUniqueID{ *this };

JNI::Field<AxisAlignedBB, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/entity/Entity"), "boundingBox")
)> boundingBox{ *this };/* Lnet/minecraft/util/math/AxisAlignedBB; */

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/entity/Entity", "getName", "()Ljava/lang/String;").first
)> getName{ *this };


END_KLASS_DEF();
END_1_12_2