#pragma once
#include "../utils/Singleton.hpp"
#include "event/EventBus.hpp"
#include "render/gui/input/IOEvents.h"
#include <Main.hpp>

#include <atomic>
#include <memory>

enum class MajorVersion
{
	MAJOR_189,
	MAJOR_112,
	MAJOR_1181,
	MAJOR_1201,
	MAJOR_1204
};


struct MCInfo
{
	MajorVersion major = MajorVersion::MAJOR_1181;

};
class Younkoo : public Singleton<Younkoo> {

public:
	Younkoo();
	bool setup();
	bool shutdown();
	std::atomic<bool> shouldShutDown = false;
	std::unique_ptr<dxg::EventBus> EventBus = std::make_unique<dxg::EventBus>();
	MCInfo info;
};

