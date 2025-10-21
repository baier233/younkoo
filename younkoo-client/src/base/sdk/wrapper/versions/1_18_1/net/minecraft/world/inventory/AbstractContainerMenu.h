#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(AbstractContainerMenu, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/AbstractContainerMenu"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/AbstractContainerMenu"), "containerId")
)> containerId{ *this };/* I */

END_KLASS_DEF();

END_1_18_1