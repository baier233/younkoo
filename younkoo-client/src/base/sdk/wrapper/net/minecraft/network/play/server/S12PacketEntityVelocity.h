#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>

BEGIN_WRAP
class S12PacketEntityVelocity :public Packet {
public:
	using Packet::Packet;
	static jclass klass();
	int getEntityID();
	int getMotionX();
	int getMotionY();
	int getMotionZ();
};

END_WRAP