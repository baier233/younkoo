#include "Velocity.h"

#include <GL/glew.h>
#include <nanovg.h>
#include <base/features/modules/ModuleManager.h>
#include <base/render/gui/GUI.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#define DEBUG
#include <log/LOG.h>

Velocity::Velocity() :AbstractModule(xorstr_("Velocity"), Category::COMBAT, xorstr_("Velocity."))
{
	REGISTER_EVENT(EventPacket, Velocity::onPacket);
	REGISTER_EVENT(EventUpdate, Velocity::onLivingWalkUpdate);
	this->addValue(BoolType, mouseOverValue);
	this->addValue(FloatType, strengthPercent);
}

Velocity& Velocity::getInstance()
{
	static Velocity instance = Velocity();
	return instance;
}

void Velocity::onEnable()
{

}

void Velocity::onDisable()
{

}

int counter;
static std::atomic<int> cached_player_id = -1;
void Velocity::onUpdate()
{
	ToggleCheck;
}
static std::atomic_bool receivedKnockBack = false;
static std::atomic_bool attacked = false;
#include <wrapper/net/minecraft/network/play/client/C0BPacketEntityAction.h>
#include <wrapper/net/minecraft/network/play/client/C02PacketUseEntity.h>
#include <wrapper/net/minecraft/network/play/client/C0APacketAnimation.h>
#include <base/features/modules/visual/TargetHud.h>
#include "KillAura.h"
static bool close_due_to_shit_issue = false;
static bool innerToggle = false;
void Velocity::onLivingWalkUpdate()
{
	if (!this->getToggle() && !innerToggle) return;

	auto mc = Wrapper::Minecraft::getMinecraft();
	auto player = Wrapper::Minecraft::getMinecraft().getPlayer();
	auto world = Wrapper::Minecraft::getMinecraft().getWorld();
	if (player.isNULL() || world.isNULL())
	{
		return;
	}

	cached_player_id = player.getEntityID();

	if (player.getHurtTime() == 0)
	{
		receivedKnockBack = attacked = false;
	}

	if (receivedKnockBack && !attacked) {
		std::optional<Wrapper::EntityLivingBase> target = std::nullopt;
		if (mouseOverValue->getValue())
		{
			auto over = mc.getMouseOver();
			if (!over.isNULL() && over.isTypeOfEntity())
			{
				auto entity = over.getEntity();
				if (!entity.isNULL() && entity.instanceOf(Wrapper::EntityLivingBase::klass()))
				{
					target = Wrapper::EntityLivingBase(*entity.instance);
					target = Wrapper::EntityLivingBase(*entity.instance);
				}
			}
		}
		else if (KillAura::getInstance().getToggle()) {

			target = (TargetHud::getInstance().renderTarget);
		}
		else {
			return;
		}
		if (!target.has_value() || target.value().isNULL())
		{
			return;
		}

		auto deltaMovement = player.getMotion();
		double value = *this->strengthPercent->getValuePtr() / 100.0f;
		double logarithm = std::log(value) / std::log(0.6f);
		long k = std::min(std::lround(logarithm), 5L);
		float reduceXZ = std::pow(0.6f, k);

		if (k == 0)
		{
			attacked = true;
			return;
		}

		boolean sprinting = player.wasSprinting();
		if (!sprinting) {
			mc.getNetworkManager().sendPacket(Wrapper::C0BPacketEntityAction::create(player, Wrapper::C0BPacketEntityAction$Action::START_SPRINTING()));
		}

		for (int i = 0; i < k; i++) {
			//这个target还需要打磨打磨。。？
			mc.getNetworkManager().sendPacket(Wrapper::C02PacketUseEntity::createAttackPacket(target.value(), player.isSneaking()));
			mc.getNetworkManager().sendPacket(Wrapper::C0APacketAnimation::create());
		}

		if (!sprinting) {
			mc.getNetworkManager().sendPacket(Wrapper::C0BPacketEntityAction::create(player, Wrapper::C0BPacketEntityAction$Action::STOP_SPRINTING()));
		}



		attacked = true;
		if (attacked) {

		}
		LOG("Apply Anti KB");
		player.setMotion(Math::Vector3D{ deltaMovement.x * reduceXZ, deltaMovement.y, deltaMovement.z * reduceXZ });
	}

}

#include <wrapper/net/minecraft/network/play/server/S12PacketEntityVelocity.h>
#include <hotspot/classes/instance_klass.h>
void Velocity::onPacket(const EventPacket& e)
{

	if (!this->getToggle() && !innerToggle) return;
	if (e.type != RECEIVE) return;
	auto thread = e.thread;

	static auto velocity_packet_class = Wrapper::S12PacketEntityVelocity::klass();
	if (auto packet = e.packet; !packet.isNULL())
	{
		auto packet_klass = packet.getClassBaseOnObject();
		if (!packet_klass)
		{
			return;
		}
		auto k = java_hotspot::instance_klass::get_instance_class(packet_klass);
		if (k)
		{
			//LOG("Input Packet : " << k->get_name()->to_string());
			if (k->get_name()->to_string().find("ClientboundLoginPacket") != std::string::npos || k->get_name()->to_string().find("ClientboundChangeDifficultyPacket") != std::string::npos)
			{
				LOG("Loading another level...");
				this->setToggle(false);
				close_due_to_shit_issue = true;
			}
		}
	}
	else {
		return;
	}


	if (!e.packet.isNULL() && velocity_packet_class && e.packet.instanceOf(velocity_packet_class))
	{

		Wrapper::S12PacketEntityVelocity packet(*e.packet.instance);
		if (packet.getEntityID() == cached_player_id.load())
		{
			LOG("input velocity packet");
			receivedKnockBack = true;
		}
	}
	if (JNI::get_env()->ExceptionCheck())
	{
		LOG("Exception Occurred!");
		JNI::get_env()->ExceptionClear();

	}
}
