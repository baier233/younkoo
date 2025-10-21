#pragma once
#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(Container, return SRGParser::get().getObfuscatedClassName("net/minecraft/inventory/Container"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/inventory/Container"), "windowId")
)> windowId{ *this };/* I */

END_KLASS_DEF()
END_1_8_9