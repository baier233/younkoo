#pragma once
#include <base\render\nano\NanovgHelper.hpp>
class Component {
public:
	virtual ~Component() = default;
	virtual void draw(NVGcontext *vg, float x, float y, float width, float height, double mouseX, double mouseY) = 0;
	virtual bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) = 0;
	virtual bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) = 0;
	virtual bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) = 0;
	virtual bool keyPressed(int keyCode, int scanCode, int modifiers) = 0;
	static inline bool isHovering(float x, float y, float width, float height, double mouseX, double mouseY) {
		return mouseX >= x && mouseY >= y && mouseX < x + width && mouseY < y + height;
	}
};