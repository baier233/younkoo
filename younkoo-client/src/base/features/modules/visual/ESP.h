#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
class ESP : public AbstractModule
{
public:
	static ESP& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	void onRender3D(const EventRender3D& e);
protected:
	DEFINE_BOOL_VALUE(teamBasedColorValue, "Team Based Color", "Team Based Color", true);
	DEFINE_BOOL_VALUE(Newstyle, "New Style", "New Style", true);
	DEFINE_BOOL_VALUE(HealthBar, "Health Bar", "Health Bar", true);
	DEFINE_FLOAT_VALUE(RGB_R, "Red", "Red", 255.0f, 0.0f, 255.0f);
	DEFINE_FLOAT_VALUE(RGB_G, "Green", "Green", 255.0f, 0.0f, 255.0f);
	DEFINE_FLOAT_VALUE(RGB_B, "Blue", "Blue", 255.0f, 0.0f, 255.0f);
	DEFINE_FLOAT_VALUE(outlineWidth, "Outline Width", "outlineWidth", 2.f, 1.5f, 5.f);
private:

	ESP();
};

struct EntityData {
	std::string name;
	Math::Vector2 name_pos;
	float health;
	float max_health;
	float top;
	float bottom;
	float left;
	float right;
};