#pragma once
#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include "titan_hook.h"
#include "../ModuleManager.h"
class Chams : public AbstractModule
{
public:
	static Chams& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();;
protected:
	Chams();
};