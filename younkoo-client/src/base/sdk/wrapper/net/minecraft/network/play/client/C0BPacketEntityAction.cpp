#include "C0BPacketEntityAction.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket.h>
Wrapper::C0BPacketEntityAction Wrapper::C0BPacketEntityAction::create(Entity entity, C0BPacketEntityAction$Action action)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return V1_18_1::ServerboundPlayerCommandPacket::create(entity.getObject(), action.getObject());
	}
	return C0BPacketEntityAction();
}
