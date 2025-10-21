#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>
class CaveFinder : public AbstractModule
{
public:
	static CaveFinder& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	CaveFinder();
};
