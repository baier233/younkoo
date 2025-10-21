#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>
#include "../render/gui/GUI.h"

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class Stealer : public AbstractModule
{
public:
	DEFINE_FLOAT_VALUE(delayValue, "Delay", "Delay millseconds", 250.f, 0.f,1000.f );
	static Stealer& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	Stealer();
private:
};
