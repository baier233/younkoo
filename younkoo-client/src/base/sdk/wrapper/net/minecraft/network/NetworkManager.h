#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/network/Packet.h>

BEGIN_WRAP
class NetworkManager :public Object {
public:
	using Object::Object;
	void sendPacket(Packet packet);
};

END_WRAP