#pragma once
#include <SDK.hpp>
#include "IInventory.h"
#include "Container.h"
BEGIN_1_8_9
BEGIN_KLASS_DEF_EX(ContainerChest, return SRGParser::get().getObfuscatedClassName("net/minecraft/inventory/ContainerChest"), Container)
JNI::Field<IInventory, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/inventory/ContainerChest"), "lowerChestInventory")
)> lowerChestInventory{ *this };/* Lnet/minecraft/inventory/IInventory; */
END_KLASS_DEF()
END_1_8_9