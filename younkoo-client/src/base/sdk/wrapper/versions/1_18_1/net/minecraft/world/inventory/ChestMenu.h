#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/Container.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/inventory/AbstractContainerMenu.h>
BEGIN_1_18_1
BEGIN_KLASS_DEF_EX(ChestMenu, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ChestMenu"), AbstractContainerMenu)

JNI::Field<Container, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/inventory/ChestMenu"), "container")
)> container{ *this };/* Lnet/minecraft/world/Container; */

END_KLASS_DEF();

END_1_18_1