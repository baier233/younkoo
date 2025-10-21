#include "C0BPacketEntityAction$Action.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundPlayerCommandPacket$Action.h>
Wrapper::C0BPacketEntityAction$Action Wrapper::C0BPacketEntityAction$Action::START_SPRINTING()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return V1_18_1::ServerboundPlayerCommandPacket$Action::static_obj().START_SPRINTING.get();
	}
	return C0BPacketEntityAction$Action();
}
Wrapper::C0BPacketEntityAction$Action Wrapper::C0BPacketEntityAction$Action::STOP_SPRINTING()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return V1_18_1::ServerboundPlayerCommandPacket$Action::static_obj().STOP_SPRINTING.get();
	}
	return C0BPacketEntityAction$Action();
}

