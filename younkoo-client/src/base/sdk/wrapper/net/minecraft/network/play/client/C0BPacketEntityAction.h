#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>
#include <wrapper/net/minecraft/entity/Entity.h>
#include "C0BPacketEntityAction$Action.h"
BEGIN_WRAP
class C0BPacketEntityAction :public Packet {
public:
	using Packet::Packet;
	static C0BPacketEntityAction create(Entity entity, C0BPacketEntityAction$Action action);
};

END_WRAP