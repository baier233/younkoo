#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
BEGIN_1_18_1
BEGIN_KLASS_DEF(ClickType, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"))
JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "PICKUP")
)> PICKUP{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "QUICK_MOVE")
)> QUICK_MOVE{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "SWAP")
)> SWAP{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "CLONE")
)> CLONE{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "THROW")
)> THROW{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "QUICK_CRAFT")
)> QUICK_CRAFT{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "PICKUP_ALL")
)> PICKUP_ALL{ *this };/* Lnet/minecraft/world/inventory/ClickType; */

JNI::Field<JNI::Array<ClickType>, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ClickType"), "$VALUES")
)> $VALUES{ *this };/* [Lnet/minecraft/world/inventory/ClickType; */

JNI::Method<JNI::Array<ClickType>, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/inventory/ClickType", "values", "()[Lnet/minecraft/world/inventory/ClickType;").first
)> values{ *this };

JNI::Method<ClickType, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/inventory/ClickType", "valueOf", "(Ljava/lang/String;)Lnet/minecraft/world/inventory/ClickType;").first
), String> valueOf{ *this };

END_KLASS_DEF();
END_1_18_1