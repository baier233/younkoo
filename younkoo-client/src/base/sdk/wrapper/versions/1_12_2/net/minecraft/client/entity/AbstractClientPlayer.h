#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/entity/player/EntityPlayer.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF_EX(AbstractClientPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/entity/AbstractClientPlayer"), EntityPlayer)

END_KLASS_DEF();
END_1_12_2