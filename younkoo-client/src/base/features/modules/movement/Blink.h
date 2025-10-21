#pragma once
#define WIN32_LEAN_AND_MEAN
#include "titan_hook.h"
#include "../AbstractModule.h"

class Blink : public AbstractModule
{
public:
	static Blink& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	Blink();
};

