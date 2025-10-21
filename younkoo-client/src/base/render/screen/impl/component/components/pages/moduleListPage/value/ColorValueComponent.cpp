#include "ColorValueComponent.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>


ColorValueComponent::ColorValueComponent(ColorValue* colorValue)
{
	value = colorValue;
}

bool ColorValueComponent::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return false;
}

bool ColorValueComponent::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return false;
}

bool ColorValueComponent::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {

	return false;
}

bool ColorValueComponent::keyPressed(int keyCode, int scanCode, int modifiers) {
	return false;
}

void ColorValueComponent::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	NanoVGHelper::nvgTextW(vg, wstr::toString(value->getName()), x + 17 + 20, y + 27.72 + 22, NanoVGHelper::fontHarmony, 16, nvgRGBA(79, 77, 80, 255));

}
