#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
#include <GL/glew.h>
#include <nanovg.h>
class HUD : public AbstractModule
{
public:
	DEFINE_BOOL_VALUE(blurValue, "Glow Text", "Text Blur(glow).", true);
	static HUD& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);

	struct ModuleAnimationState {
		bool isVisible;
		float animationProgress;
		std::chrono::steady_clock::time_point lastUpdateTime;
	};

private:

	std::unordered_map<AbstractModule*, ModuleAnimationState> moduleAnimStates;
	HUD();
};
