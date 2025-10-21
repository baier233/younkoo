#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/java/lang/String.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(OptionInstance, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/OptionInstance"))

JNI::Field<JDK::Object, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/OptionInstance"), "initialValue")
)> initialValue{ *this };/* Ljava/lang/Object; */

JNI::Field<JDK::Object, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/OptionInstance"), "value")
)> value{ *this };/* Ljava/lang/Object; */

JNI::Method<JDK::Object, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/OptionInstance", "get", "()Ljava/lang/Object;").first
)> get{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/OptionInstance", "toString", "()Ljava/lang/String;").first
)> toString{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/OptionInstance", "set", "(Ljava/lang/Object;)V").first
), JDK::Object> set{ *this };

END_KLASS_DEF();
END_1_20_1