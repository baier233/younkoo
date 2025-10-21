#include "PageFrame.h"
#include <base\render\nano\NanovgHelper.hpp>


PageFrame::PageFrame() {

}

bool PageFrame::keyPressed(int keyCode, int scanCode, int modifiers) {
	return currentPage->keyPressed(keyCode,scanCode,modifiers);
}

bool PageFrame::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return currentPage->mouseScrolled(x + 181.5, y + 43, width - 181.5, height - 43, mouseX, mouseY, horizontalAmount, verticalAmount);
}

bool PageFrame::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return currentPage->mouseReleased(x + 181.5, y + 43, width - 181.5, height - 43, mouseX, mouseY, button);
}

void PageFrame::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) {
	auto test = NanoVGHelper::scissorHelper.scissor(vg, x + 181.5, y + 43, width - 181.5, height - 43);

	if (!animation.isFinished()) {
		animation.calculate();



		previousPage->draw(vg, x + 181.5 + animation.getCurrent(), y + 43, width - 181.5, height - 43, mouseX, mouseY);
		currentPage->draw(vg, x + 181.5 + animation.getCurrent() - (830 - 181.5), y + 43, width - 181.5, height - 43, mouseX, mouseY);

	} else {
		animation.reset();
		animation.setTarget(0);
		

		currentPage->draw(vg, x + 181.5, y + 43, width - 181.5, height - 43, mouseX, mouseY);
	}

	NanoVGHelper::scissorHelper.resetScissor(vg,test);
}

bool PageFrame::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	
	return currentPage->mouseClicked(x + 181.5, y + 43, width - 181.5, height - 43, mouseX, mouseY, button);
}

std::shared_ptr<PageFrame>& PageFrame::getInstance()
{
	static std::shared_ptr<PageFrame> instance = std::make_shared<PageFrame>();
	return instance;
}

void PageFrame::displayPage(std::shared_ptr<Component> component) {
	previousPage = currentPage;
	currentPage = component;

	if (!animation.isFinished()) {
		animation.setTarget(0);
		animation.reset();
	}

	animation.setTarget(830 - 181.5);
}