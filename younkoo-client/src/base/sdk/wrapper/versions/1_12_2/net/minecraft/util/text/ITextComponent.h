#pragma once
#include <SDK.hpp>
#include "Style.h"
BEGIN_1_12_2
BEGIN_KLASS_DEF(ITextComponent, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/text/ITextComponent"))

JNI::Method<Style, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/util/text/ITextComponent", "getStyle", "()Lnet/minecraft/util/text/Style;").first
)> getStyle{ *this };

END_KLASS_DEF();
END_1_12_2