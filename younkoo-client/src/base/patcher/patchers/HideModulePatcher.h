#pragma once
#include "../AbstractPatcher.h"
class HideModulePatcher :public AbstractPatcher {
public:
	void patch(const PatcherManagerData& data) override;
	void clean(const PatcherManagerData& data)  override;
};
