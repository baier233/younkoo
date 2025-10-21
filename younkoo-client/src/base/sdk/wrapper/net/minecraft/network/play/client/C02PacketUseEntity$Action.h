

#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>
#include <wrapper/net/minecraft/entity/Entity.h>
BEGIN_WRAP
class C02PacketUseEntity$Action :public Object {
public:
	using Object::Object;
	static C02PacketUseEntity$Action ATTACK();
};

END_WRAP