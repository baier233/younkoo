#include "SliderBar.h"
#include <base\render\nano\NanovgHelper.hpp>
#include "ModuleCategoryButton.h"
#include "PageFrame.h"
#include "pages/SettingPage.h"

static auto COMBAT_ICON = L"\uE9DB";
static auto MOVEMENT_ICON = L"\uEB34";
static auto PLAYER_ICON = L"\uEBAD";
static auto VISUAL_ICON = L"\uEAE1";
static auto WORLD_ICON = L"\uEBB1";

static std::vector<std::shared_ptr<ModuleCategoryButton>> components;

static Category SELECT_CATEGORY = Category::COMBAT;
AnimationObject animation = AnimationObject(200, Easing::EASE_OUT_CRIC());

SliderBar::SliderBar()
{
	auto categories = { Category::COMBAT, Category::MOVEMENT, Category::PLAYER, Category::WORLD, Category::VISUAL, Category::SETTING };

	for (auto& categorie : categories) {
		auto bar = std::make_shared<ModuleCategoryButton>(categorie);

		components.push_back(bar);
	}

	animation.setTarget(0);
}

bool SliderBar::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) {
	return false;
}

bool SliderBar::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	return false;
}

bool SliderBar::keyPressed(int keyCode, int scanCode, int modifiers) {
	return false;
}

bool SliderBar::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) {
	float testY = 0;

	for (auto& component : components) {
		if (Component::isHovering(x + 16, y + 140 + testY, 150, 30, mouseX, mouseY)) {
			SELECT_CATEGORY = component->moduleCategory;

			if (SELECT_CATEGORY != Category::SETTING)
			{
				PageFrame::getInstance()->displayPage(std::make_shared<ModuleListsPage>(SELECT_CATEGORY));
			}
			else
			{
				PageFrame::getInstance()->displayPage(std::make_shared<setting_page>());
			}

			animation.setTarget(testY);
			animation.calculate();
			break;
		}
		testY += 40;
	}
	return false;
}

void SliderBar::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{

	NanoVGHelper::nvgTextStr(vg, "CATEGORY", x + 16.5, y + 120, NanoVGHelper::fontHarmony, 11, nvgRGBA(181, 183, 188, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	if (!animation.isFinished())
		animation.calculate();

	float testY = 0;

	for (auto& component : components) {
		component->draw(vg, x, y + testY, width, height, mouseX, mouseY, false);
		testY += 40;
	}

	NanoVGHelper::drawRoundedRect(vg, x + 16, y + 140 + animation.getCurrent(), 150, 30, NanoVGHelper::rgbaToColor(229, 243, 253, 255), 5);

	auto test = NanoVGHelper::scissorHelper.scissor(vg, x + 16, y + 140 + animation.getCurrent(), 150, 30);

	testY = 0;

	for (auto& component : components) {
		component->draw(vg, x, y + testY, width, height, mouseX, mouseY, true);
		testY += 40;
	}

	NanoVGHelper::scissorHelper.resetScissor(vg, test);


	NanoVGHelper::nvgTextStr(vg, "PROFILE", x + 16.5, y + 400, NanoVGHelper::fontHarmony, 11, nvgRGBA(181, 183, 188, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);


	// 头像框
	NanoVGHelper::drawCircle(vg, x + 31, y + height - 31, 16, NanoVGHelper::rgbaToColor(79, 115, 112, 255));
	NanoVGHelper::nvgTextW(vg, L"S B", x + 20, y + height - 36.5, NanoVGHelper::fontHarmony, 15, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	NanoVGHelper::nvgTextStr(vg, "夏天233", x + 57, y + height - 42, NanoVGHelper::fontHarmonyBold, 15, nvgRGBA(79, 77, 80, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	NanoVGHelper::nvgTextStr(vg, "#0250", x + 56, y + height - 28, NanoVGHelper::fontHarmonyBold, 10, nvgRGBA(207, 196, 196, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	//

	//std::to_wstring(posX) + L" " + std::to_wstring(posY)
// text 传得是wString 所以得to_wstring 然后字符串常量 前面要加 L"sssssadasdjiadb"
	//NanoVGHelper::nvgTextW(vg, std::to_wstring(mouseX) + L" " + std::to_wstring(mouseY), mouseX, mouseY, NanoVGHelper::fontHarmony, 50, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

}
