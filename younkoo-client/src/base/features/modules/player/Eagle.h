#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class Eagle : public AbstractModule
{
public:
	static Eagle& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	DEFINE_BOOL_VALUE(shiftPressedValue, "Need Shift Pressed", "Only when shift key is pressed will this module work.", false);
	Eagle();
private:
};
