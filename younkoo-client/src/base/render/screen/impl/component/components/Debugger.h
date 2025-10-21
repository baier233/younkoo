#pragma once
#include "../Component.h"
#include <base\render\nano\NanovgHelper.hpp>
class Debugger : public Component
{
public:
	Debugger();
	void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
	bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
};