#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>
#include <wrapper/net/minecraft/entity/Entity.h>
BEGIN_WRAP
class C0APacketAnimation :public Packet {
public:
	using Packet::Packet;
	static C0APacketAnimation create();
};

END_WRAP