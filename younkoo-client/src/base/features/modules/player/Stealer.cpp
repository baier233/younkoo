#include "Stealer.h"
#include <utils/TimerUtil.hpp>
#include <cmath>	
#include <wrapper/net/minecraft/inventory/ContainerChest.h>
#include <wrapper/net/minecraft/multiplayer/PlayerController.h>
#include <wrapper/net/minecraft/world/inventory/ClickType.h>
Stealer::Stealer() :AbstractModule(xorstr_("Stealer"), Category::PLAYER, xorstr_("Stealer."))
{
	this->addValue(FloatType, this->delayValue);
}

Stealer& Stealer::getInstance()
{
	static Stealer instance = Stealer();
	return instance;
}

void Stealer::onEnable()
{
}

void Stealer::onDisable()
{

}

static int lastSteal = 0;

static long nextClick = 0;

static TimerUtil time1;

void Stealer::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.getPlayer().getObject() == NULL || mc.getPlayer().getOpenContainer().getObject() == NULL || !time1.hasTimeElapsed(nextClick, true)) {
		return;
	}
	if (JNI::get_env()->IsInstanceOf(mc.getPlayer().getOpenContainer().getObject(), Wrapper::ContainerChest::klass()))
	{
		Wrapper::ContainerChest container(*mc.getPlayer().getOpenContainer().instance);
		lastSteal++;
		for (int i = 0; i < container.lowerChestInventory().getSizeInventory(); i++)
		{
			if (!container.lowerChestInventory().getStackInSlot(i).isEmpty())
			{
				if (lastSteal <= 1) {
					continue;
				}
				nextClick = round(this->delayValue->getValue());
				mc.getPlayerController().handleInventoryMouseClick(container.windowId(), i, 0, Wrapper::ClickType::QUICKMOVE(), mc.getPlayer());
				if (nextClick > 0) return;
			}
		}
	}
}