#pragma once
#include "../AbstractHook.h"
class ConnectionHook : public AbstractHook
{
public:
	void hook(const HookManagerData& container) override;
private:

};

