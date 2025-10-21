#include "C02PacketUseEntity.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundInteractPacket.h>
Wrapper::C02PacketUseEntity Wrapper::C02PacketUseEntity::createAttackPacket(Entity entity, boolean isShift)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return V1_18_1::ServerboundInteractPacket::static_obj().createAttackPacket(entity.getObject(), isShift);
	}
	return C02PacketUseEntity();
}
