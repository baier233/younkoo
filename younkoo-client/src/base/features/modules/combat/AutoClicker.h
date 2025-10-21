﻿#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
class AutoClicker : public AbstractModule
{
public:
	static AutoClicker& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	enum ClickMode
	{
		BOTH,
		LEFTONLY,
		RIGHTONLY
	};
	DEFINE_FLOAT_VALUE(leftMaxCpsValue, "Left Max Cps", "Left Mouse Maximum Clicks per Second. ", 14, 0, 20);
	DEFINE_FLOAT_VALUE(leftMinCpsValue, "Left Min Cps", "Left Mouse Minmum Clicks per Second. ", 8, 0, 20);

	DEFINE_FLOAT_VALUE(rightMaxCpsValue, "Right Max Cps", "Right Mouse Maximum Clicks per Second. ", 14, 0, 20);
	DEFINE_FLOAT_VALUE(rightMinCpsValue, "Right Min Cps", "Right Mouse Minmum Clicks per Second. ", 8, 0, 20);

	DEFINE_BOOL_VALUE(miningValue, "Mining", "Still effective during mining.", true);

	DEFINE_BOOL_VALUE(blockHitValue, "Block Hit", "Hit with automatically right click.", false);
	DEFINE_FLOAT_VALUE(blockHitChanceValue, "BlockHit Chance", "Automatically right click chance. ", 3, 1, 50);

	DEFINE_BOOL_VALUE(doubleClickValue, "Double Click", "Make your CPS in Practice lower.", false);
	DEFINE_BOOL_VALUE(doubleClickMistakeValue, "DoubleClick Mistake", "Lower click frequence when double click is failed.", true);
	DEFINE_FLOAT_VALUE(doubleClickChanceValue, "DoubleClick Chance", "Automatically double click chance. ", 60, 20, 100);

	DEFINE_BOOL_VALUE(inInventoryValue, "Inventory", "Still effective when inventory screen is open.", false);
	DEFINE_BOOL_VALUE(blockOnlyValue, "Right Block Only", "Only do right click when current item is Block.", true);
	DEFINE_BOOL_VALUE(ignoreBowValue, "Right Ignore Bow", "Skip when current item is Bow.", true);

	std::shared_ptr<ModeValue>clickModeValue = std::make_shared<ModeValue>("Mode", "Click Mode.", std::vector<int>{ BOTH, LEFTONLY, RIGHTONLY }, std::vector<std::string>{ "Both", "Left Only", "Right Only" }, BOTH);

	AutoClicker();
};
