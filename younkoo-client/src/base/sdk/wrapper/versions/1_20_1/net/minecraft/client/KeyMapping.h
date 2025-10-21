#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <jdk/Classes.h>
#include <wrapper/versions/1_20_1/com/mojang/blaze3d/platform/InputConstants$Key.h>
BEGIN_1_20_1
BEGIN_KLASS_DEF(KeyMapping, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"))
JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_MOVEMENT")
)> CATEGORY_MOVEMENT{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_MISC")
)> CATEGORY_MISC{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_MULTIPLAYER")
)> CATEGORY_MULTIPLAYER{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_GAMEPLAY")
)> CATEGORY_GAMEPLAY{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_INVENTORY")
)> CATEGORY_INVENTORY{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_INTERFACE")
)> CATEGORY_INTERFACE{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "CATEGORY_CREATIVE")
)> CATEGORY_CREATIVE{ *this };/* Ljava/lang/String; */

JNI::Field<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "name")
)> name{ *this };/* Ljava/lang/String; */
JNI::Field<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "category")
)> category{ *this };/* Ljava/lang/String; */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "isDown")
)> isDown{ *this };/* Z */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"), "clickCount")
)> clickCount{ *this };/* I */

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "releaseAll", "()V").first
)> releaseAll{ *this };

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "resetToggleKeys", "()V").first
)> resetToggleKeys{ *this };

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "resetMapping", "()V").first
)> resetMapping{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "getCategory", "()Ljava/lang/String;").first
)> getCategory{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "consumeClick", "()Z").first
)> consumeClick{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "release", "()V").first
)> release{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "getName", "()Ljava/lang/String;").first
)> getName{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "compareTo", "(Lnet/minecraft/client/KeyMapping;)I").first
), KeyMapping> compareTo{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "same", "(Lnet/minecraft/client/KeyMapping;)Z").first
), KeyMapping> same{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "isUnbound", "()Z").first
)> isUnbound{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "matches", "(II)Z").first
), jint, jint> matches{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "matchesMouse", "(I)Z").first
), jint> matchesMouse{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "isDefault", "()Z").first
)> isDefault{ *this };

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "saveString", "()Ljava/lang/String;").first
)> saveString{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "setDown", "(Z)V").first
), jboolean> setDown{ *this };

JNI::Method<InputConstants$Key, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraftforge/client/extensions/IForgeKeyMapping", "getKey", "()Lcom/mojang/blaze3d/platform/InputConstants$Key;").first
)> getKey{ *this };

END_KLASS_DEF();
END_1_20_1