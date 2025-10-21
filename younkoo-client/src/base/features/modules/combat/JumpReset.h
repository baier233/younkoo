#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>
class JumpReset : public AbstractModule
{
public:
	static JumpReset& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onPacket(const EventPacket& e);
protected:
	JumpReset();
};
