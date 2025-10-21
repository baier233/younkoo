#pragma once
#include "../Component.h"
#include <base\render\nano\NanovgHelper.hpp>
#include "pages\ModuleListsPage.h"
#include <memory>

class PageFrame : public Component
{
public:
	PageFrame();
	static std::shared_ptr<PageFrame>& getInstance();
	void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
	bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
	std::shared_ptr<Component> previousPage;
	std::shared_ptr<Component> currentPage = std::make_shared<ModuleListsPage>(Category::COMBAT);
	void displayPage(std::shared_ptr<Component> component);

private:
	AnimationObject animation = AnimationObject(650, Easing::EASE_IN_OUT_Expo());
};