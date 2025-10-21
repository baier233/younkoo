#include "AutoSprint.h"

AutoSprint::AutoSprint() :AbstractModule(xorstr_("AutoSprint"), Category::MOVEMENT)
{
}

AutoSprint& AutoSprint::getInstance()
{
	static AutoSprint instance = AutoSprint();
	return instance;
}


void AutoSprint::onEnable()
{
}

void AutoSprint::onDisable()
{
}

void AutoSprint::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto options = mc.getSettings();
	options.setSprintKeyPressed(true);
}