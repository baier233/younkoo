#pragma once
#include "../AbstractPatcher.h"
class ExitProcessPatcher :public AbstractPatcher {
public:
	void patch(const PatcherManagerData& data) override;
	void clean(const PatcherManagerData& data)  override;
};
