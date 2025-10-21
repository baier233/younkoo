#pragma once
#include <utils/Singleton.hpp>
#include <vector>
#include <memory>

#include "AbstractPatcher.h"
class PatcherManager :public Singleton<PatcherManager>
{
public:
	void setup();
	void clean();
	void handle();
private:
	std::vector<std::shared_ptr<AbstractPatcher>> patchers;
};

