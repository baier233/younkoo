#pragma once
#include "../AbstractHook.h"

class MinecraftHook : public AbstractHook
{
public:
	void hook(const HookManagerData& container) override;
private:
};