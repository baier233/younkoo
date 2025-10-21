#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

class AutoSprint : public AbstractModule
{
public:
	static AutoSprint& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	AutoSprint();
private:
};

