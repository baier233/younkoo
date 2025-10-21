#pragma once
#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include "titan_hook.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <base/event/Events.h>
#include "../ModuleManager.h"
class ChestESP : public AbstractModule
{
public:
	static ChestESP& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
protected:
	ChestESP();
private:
	void drawBox(glm::vec4 color);

};