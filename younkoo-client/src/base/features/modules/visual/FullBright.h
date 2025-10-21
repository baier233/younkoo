#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

class FullBright : public AbstractModule
{
public:
	static FullBright& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	FullBright();
private:
};

