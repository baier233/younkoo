#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
class KeepSprint : public AbstractModule
{
public:
	static KeepSprint& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	KeepSprint();
};
