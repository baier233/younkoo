#include "NoJumpDelay.h"

NoJumpDelay::NoJumpDelay() :AbstractModule(xorstr_("NoJumpDelay"), Category::PLAYER, xorstr_("No Jump Delay.."))
{
}

NoJumpDelay& NoJumpDelay::getInstance()
{
	static NoJumpDelay instance = NoJumpDelay();
	return instance;
}

void NoJumpDelay::onEnable()
{
}

void NoJumpDelay::onDisable()
{

}


void NoJumpDelay::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	mc.getPlayer().setJumpTicks(0);
}