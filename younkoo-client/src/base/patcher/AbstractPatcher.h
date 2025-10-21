#pragma once

struct PatcherManagerData
{

};

class AbstractPatcher
{
public:
	virtual void patch(const PatcherManagerData& data) = 0;
	virtual void clean(const PatcherManagerData& data) = 0;
protected:
};

