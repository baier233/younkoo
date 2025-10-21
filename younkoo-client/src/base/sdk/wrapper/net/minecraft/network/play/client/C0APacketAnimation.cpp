#include "C0APacketAnimation.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ServerboundSwingPacket.h>

Wrapper::C0APacketAnimation Wrapper::C0APacketAnimation::create()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return V1_18_1::ServerboundSwingPacket::create(V1_18_1::InteractionHand::static_obj().MAIN_HAND.get());
	}
	return C0APacketAnimation();
}
