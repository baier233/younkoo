#include "NetworkManager.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/Connection.h>
void Wrapper::NetworkManager::sendPacket(Packet packet)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Connection connection = this->getObject();
		V1_18_1::Packet p = packet.getObject();
		connection.send(p);
		return;
	}
	assert("unimplemented version");
}
