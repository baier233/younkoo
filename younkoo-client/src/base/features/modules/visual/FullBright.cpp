#include "FullBright.h"

FullBright::FullBright() :AbstractModule(xorstr_("FullBright"), Category::VISUAL, xorstr_("FullBright."))
{
}

FullBright& FullBright::getInstance()
{
	static FullBright instance = FullBright();
	return instance;
}

double lastGamma = 0;

void FullBright::onEnable()
{
	auto mc = Wrapper::Minecraft::getMinecraft();

	auto options = mc.getSettings();
	if (options.isNULL()) return;
	lastGamma = options.getGamma();
}

void FullBright::onDisable()
{
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto options = mc.getSettings();
	options.setGamma(lastGamma);
}

void FullBright::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto options = mc.getSettings();
	options.setGamma(20.0f);
}