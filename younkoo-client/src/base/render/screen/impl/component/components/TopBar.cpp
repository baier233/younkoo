#include "TopBar.h"
#include <base\render\nano\NanovgHelper.hpp>
#include "ModuleCategoryButton.h"


TopBar::TopBar()
{

}

bool TopBar::keyPressed(int keyCode, int scanCode, int modifiers) {
	return false;
}

bool TopBar::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return false;
}

bool TopBar::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return false;
}

bool TopBar::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {

	return false;
}

void TopBar::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	// <
	NanoVGHelper::nvgTextW(
		vg, L"\uEA57",
		x + 202, y + 14, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(227, 227, 227, 255)
	);

	// >
	NanoVGHelper::nvgTextW(
		vg, L"\uEA58",
		x + 232, y + 14, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(227, 227, 227, 255)
	);

	NanoVGHelper::drawRoundedRect(
		vg, x + 381, y + 10, 250, 26.4, NanoVGHelper::rgbaToColor(255, 255, 255, 255), 5
	);

	NanoVGHelper::drawRoundedOutlineRect(
		vg, x + 381, y + 10, 250, 26.4, 5, 1, NanoVGHelper::rgbaToColor(237, 237, 237, 255)
	);

	// ËÑË÷Í¼±ê

	NanoVGHelper::nvgTextW(
		vg, L"\uEC15",
		x + 390, y + 15, NanoVGHelper::fontMaterialIcon, 18, nvgRGBA(227, 227, 227, 255)
	);

}
