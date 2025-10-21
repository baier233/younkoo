#include "PatcherManager.h"
#include "patchers/ExitProcessPatcher.h"
#include "patchers/HideModulePatcher.h"
#include "patchers/VEHAntiCrcPatcher.h"
#include <base/Younkoo.hpp>
void PatcherManager::setup()
{
	if (Younkoo::get().info.major >= MajorVersion::MAJOR_1181) {

		patchers.push_back(std::make_shared<VEHAntiCrcPatcher>());
		patchers.push_back(std::make_shared<ExitProcessPatcher>());
	}
	else {
		patchers.push_back(std::make_shared<ExitProcessPatcher>());

	}
	//patchers.push_back(std::make_shared<HideModulePatcher>());
}

void PatcherManager::clean()
{
	for (auto& patcher : patchers)
	{
		patcher->clean({});
	}
}

void PatcherManager::handle()
{
	for (auto& patcher : patchers)
	{

		patcher->patch({});
	}
}
