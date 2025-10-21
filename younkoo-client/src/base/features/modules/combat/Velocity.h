#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>
class Velocity : public AbstractModule
{
public:
	DEFINE_BOOL_VALUE(mouseOverValue, "Mouse Over", "Mouse Over", true);
	static Velocity& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onLivingWalkUpdate();
	void onPacket(const EventPacket& e);
protected:
	DEFINE_FLOAT_VALUE(strengthPercent, "Strength Percent", "Strength Percent", 10.0f, 10.0f, 60.0f);
	Velocity();
};
