#pragma once
#include <SDK.hpp>

BEGIN_1_20_1

BEGIN_KLASS_DEF(InputConstants$Key, return SRGParser::get().getObfuscatedClassName("com/mojang/blaze3d/platform/InputConstants$Key"))

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/platform/InputConstants$Key", "getValue", "()I").first
)> getValue{ *this };

END_KLASS_DEF();

END_1_20_1