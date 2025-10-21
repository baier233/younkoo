#include "JumpReset.h"

#include <GL/glew.h>
#include <nanovg.h>
#include <base/features/modules/ModuleManager.h>


JumpReset::JumpReset() :AbstractModule(xorstr_("JumpReset"), Category::COMBAT, xorstr_("Jump Reset."))
{
	REGISTER_EVENT(EventPacket, JumpReset::onPacket);
}

JumpReset& JumpReset::getInstance()
{
	static JumpReset instance = JumpReset();
	return instance;
}

void JumpReset::onEnable()
{
}

void JumpReset::onDisable()
{
}

void JumpReset::onUpdate()
{
}

#include <wrapper/net/minecraft/network/play/server/S12PacketEntityVelocity.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <hotspot/classes/instance_klass.h>
void JumpReset::onPacket(const EventPacket& e)
{
	ToggleCheck;
	static auto JumpReset_packet_class = Wrapper::S12PacketEntityVelocity::klass();
	if (auto packet = e.packet; !packet.isNULL())
	{
		auto packet_klass = packet.getClassBaseOnObject();
		auto k = java_hotspot::instance_klass::get_instance_class(packet_klass);
		if (k)
		{
			//LOG("input :" << k->get_name()->to_string());
		}
	}
	if (!e.packet.isNULL() && JumpReset_packet_class && e.packet.instanceOf(JumpReset_packet_class))
	{
		auto mc = Wrapper::Minecraft::getMinecraft();
		Wrapper::S12PacketEntityVelocity packet(*e.packet.instance);
		if (packet.getEntityID() == Wrapper::Minecraft::getMinecraft().getPlayer().getEntityID() && mc.getPlayer().isOnGround())
		{
			mc.getPlayer().jump();
			LOG("input JumpReset packet");
		}
	}
}
