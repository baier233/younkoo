#include "IntValueComponent.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>


IntValueComponent::IntValueComponent(NumberValue* numberValue)
{
	value = numberValue;
}

bool IntValueComponent::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return false;
}

bool IntValueComponent::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return false;
}

bool IntValueComponent::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {

	return false;
}

bool IntValueComponent::keyPressed(int keyCode, int scanCode, int modifiers) {
	return false;
}

void IntValueComponent::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	NanoVGHelper::nvgTextW(vg, wstr::toString(value->getName()), x + 17 + 20, y + 27.72 + 22, NanoVGHelper::fontHarmony, 16, nvgRGBA(79, 77, 80, 255));

}
