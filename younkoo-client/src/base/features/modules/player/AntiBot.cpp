#include "AntiBot.h"

Antibot& Antibot::getInstance()
{
	static Antibot instance = Antibot();
	return instance;
}

void Antibot::onEnable()
{
}

void Antibot::onDisable()
{
}

void Antibot::onUpdate()
{
	ToggleCheck;
}

bool Antibot::isBot(Wrapper::EntityPlayer& p)
{
	if (!this->getToggle()) return false;
	if (p.isNULL()) {
		return true;
	}
	if (p.instanceOf(Wrapper::EntityPlayerSP::klass())) {
		return true;
	}
	float height = p.getHeight();
	if (height <= 0.5f)
	{
		heightBots.push_back(p);
	}
	else {
		if (std::find(heightBots.begin(), heightBots.end(), p) != heightBots.end())
			heightBots.erase(std::find(heightBots.begin(), heightBots.end(), p));
	}
	if (p.getHealth() <= 0)
	{
		healthEntities.push_back(p);
	}
	else {
		if (std::find(healthEntities.begin(), healthEntities.end(), p) != healthEntities.end())
			healthEntities.erase(std::find(healthEntities.begin(), healthEntities.end(), p));
	}

	return std::find(healthEntities.begin(), healthEntities.end(), p) != healthEntities.end() || std::find(heightBots.begin(), heightBots.end(), p) != heightBots.end();

}

Antibot::Antibot() : AbstractModule(xorstr_("AntiBot"), Category::PLAYER, xorstr_("AntiBot."))
{
}
