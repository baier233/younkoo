#include "S12PacketEntityVelocity.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/protocol/game/ClientboundSetEntityMotionPacket.h>
#include <wrapper/versions/1_8_9/net/minecraft/network/play/server/S12PacketEntityVelocity.h>
#include <wrapper/versions/1_12_2/net/minecraft/network/play/server/SPacketEntityVelocity.h>
jclass Wrapper::S12PacketEntityVelocity::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::ClientboundSetEntityMotionPacket::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::ClientboundSetEntityMotionPacket::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		static auto klass = V1_8_9::S12PacketEntityVelocity::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		static auto klass = V1_12_2::SPacketEntityVelocity::static_obj().init();
		return klass;
	}
	return jclass();
}

int Wrapper::S12PacketEntityVelocity::getEntityID()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getId();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getId();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::S12PacketEntityVelocity packet = this->getObject();
		return packet.entityID.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::SPacketEntityVelocity packet = this->getObject();
		return packet.entityID.get();
	}
	return 0;
}

int Wrapper::S12PacketEntityVelocity::getMotionX()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getXa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getXa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::S12PacketEntityVelocity packet = this->getObject();
		return packet.motionX.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::SPacketEntityVelocity packet = this->getObject();
		return packet.motionX.get();
	}
	return 0;
}

int Wrapper::S12PacketEntityVelocity::getMotionY()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getYa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getYa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::S12PacketEntityVelocity packet = this->getObject();
		return packet.motionY.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::SPacketEntityVelocity packet = this->getObject();
		return packet.motionY.get();
	}
	return 0;
}

int Wrapper::S12PacketEntityVelocity::getMotionZ()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getZa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::ClientboundSetEntityMotionPacket packet = this->getObject();
		return packet.getZa();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::S12PacketEntityVelocity packet = this->getObject();
		return packet.motionZ.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::SPacketEntityVelocity packet = this->getObject();
		return packet.motionZ.get();
	}
	return 0;
}
