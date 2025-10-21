#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>
class Jamming : public AbstractModule
{
public:
	static Jamming& getInstance();
	static void asyncJammingPlayer(const std::string& player_uuid);
	DEFINE_BOOL_VALUE(modifyTitleValue, "Modify Title", "Modify Title.", false);
	void onAttack(const EventAttack& e);
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	Jamming();
};
