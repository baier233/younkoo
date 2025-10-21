#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(ForgeHooks, return SRGParser::get().getObfuscatedClassName("net/minecraftforge/common/ForgeHooks"))
JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraftforge/common/ForgeHooks", "onLivingJump", "(Lnet/minecraft/world/entity/LivingEntity;)V").first
), LivingEntity> onLivingJump{ *this };
END_KLASS_DEF();
END_1_18_1