#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

class FastPlace : public AbstractModule
{
public:
	static FastPlace& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	DEFINE_BOOL_VALUE(onlyBlockValue, "Only Block", "Appy Fastplace only when with block.", true);
protected:
	FastPlace();
private:
};

