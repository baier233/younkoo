#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>

class AutoTool : public AbstractModule
{
public:
	static AutoTool& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	DEFINE_BOOL_VALUE(shiftPressedValue, "Need Shift Pressed", "Only when shift key is pressed will this module work.", false);
	AutoTool();
private:
};
