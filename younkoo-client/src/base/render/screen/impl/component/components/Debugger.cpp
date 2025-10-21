#include "Debugger.h"
#include <base\render\nano\NanovgHelper.hpp>
#include "ModuleCategoryButton.h"


Debugger::Debugger()
{

}

bool Debugger::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return false;
}

bool Debugger::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return false;
}

bool Debugger::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {

	return false;
}

bool Debugger::keyPressed(int keyCode, int scanCode, int modifiers) {
	return false;
}

void Debugger::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	NanoVGHelper::nvgRect(vg, mouseX, mouseY, 300, 100, nvgRGBA(0, 0, 0, 80));
	NanoVGHelper::nvgTextW(vg, std::to_wstring(mouseX) + L" " + std::to_wstring(mouseY), mouseX + 10, mouseY + 10, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	NanoVGHelper::nvgTextW(vg, std::to_wstring(mouseX - x) + L" " + std::to_wstring(mouseY - y), mouseX + 10, mouseY + 40, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

}
