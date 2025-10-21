#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>
#include <wrapper/net/minecraft/entity/Entity.h>
BEGIN_WRAP
class C0BPacketEntityAction$Action :public Object {
public:
	using Object::Object;
	static C0BPacketEntityAction$Action START_SPRINTING();
	static C0BPacketEntityAction$Action STOP_SPRINTING();
};

END_WRAP