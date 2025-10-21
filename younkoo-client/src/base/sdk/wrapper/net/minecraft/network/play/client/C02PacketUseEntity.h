#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>
#include <wrapper/net/minecraft/entity/Entity.h>
BEGIN_WRAP
class C02PacketUseEntity :public Packet {
public:
	using Packet::Packet;
	static C02PacketUseEntity createAttackPacket(Entity entity, boolean isShift);
};

END_WRAP