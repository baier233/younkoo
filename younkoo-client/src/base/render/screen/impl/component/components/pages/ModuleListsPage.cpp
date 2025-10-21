#include "ModuleListsPage.h"
#include <base\features\modules\ModuleManager.h>


ModuleListsPage::ModuleListsPage(Category category)
{
	selectComponent = category;
	std::vector<void*> mods;
	ModuleManager::get().getModule(category, &mods);

	for (void* mod : mods)
	{
		auto m = ToBaseModule(mod);
		moduleInfos.push_back(std::make_shared<ModuleInfo>(m));
	}
}

void ModuleListsPage::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	/* TODO: 在渲染时限制滚动值，因为展开并收起 Component 时会导致 component_height_ 改变 */
	limit_scroll(height);

	scrollAnimation.calculate();
	y -= scrollAnimation.getCurrent();

	// MODULE START
	float offset_y = 0;
	for (const auto& module_info : moduleInfos)
	{
		module_info->draw(vg, x, y + offset_y, width, height, mouseX, mouseY);
		offset_y += module_info->height.getCurrent() + 11.22F;
	}

	/* TODO: 这里为什么会多 28pixel? IDK，但是为了对齐滚动的内容所以我加了 */
	component_height_ = offset_y + 43.0F;

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + 17, y + 27.72, width - (17 * 2), 73.26,  NanoVGHelper::rgbaToColor(255, 255, 255, 255) , 5
	//);

	//NanoVGHelper::drawRoundedOutlineRect(
	//	vg, x + 17, y + 27.72, width - (17 * 2), 73.26, 5, 1, NanoVGHelper::rgbaToColor(227, 227, 227, 255)
	//);

	//NanoVGHelper::nvgTextW(vg, L"Auto Soup", x + 17 + 20, y + 27.72 + 22, NanoVGHelper::fontHarmony, 17, nvgRGBA(79, 77, 80, 255));

	//NanoVGHelper::nvgTextW(
	//	vg, L"Automatically eat soup when you are at low health",
	//	x + 17 + 20, y + 27.72  + 44, NanoVGHelper::fontHarmony, 13, nvgRGBA(171, 161, 159, 255)
	//);

	//NanoVGHelper::nvgTextW(
	//	vg, L"\uEA58",
	//	x + width - 55, y + 25  + 30, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(78, 76, 80, 255)
	//);

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + width - 116, y + 25 + 30, 42.9, 20.46, NanoVGHelper::rgbaToColor(192, 224, 248, 255), 10
	//);

	//// ENABLE

	//NanoVGHelper::drawCircle(
	//	vg, x + width - 116 + 10 + 22.9, y + 25 + 30 + 10, 10, -1
	//);

	//NanoVGHelper::renderShadow(
	//	vg, x + width - 116      + 22.9, y + 25 + 30, 20, 20.46, 10, 4
	//);

	//// END
	//
	//testY = 0;

	////       HEIGHT
	//testY += (73.26 + 11.22);


	//// MODULE START

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + 17 , y + 27.72 + testY, width - (17 * 2), 73.26 + 26, NanoVGHelper::rgbaToColor(255, 255, 255, 255), 5
	//);

	//NanoVGHelper::drawRoundedOutlineRect(
	//	vg, x + 17, y + 27.72 + testY, width - (17 * 2), 73.26 + 26, 5, 1, NanoVGHelper::rgbaToColor(227, 227, 227, 255)
	//);

	//NanoVGHelper::nvgTextW(vg, L"Kill Aura", x + 17 + 20, y + 27.72 + 22 + testY, NanoVGHelper::fontHarmony, 17, nvgRGBA(79, 77, 80, 255));

	//NanoVGHelper::nvgTextW(
	//	vg, L"Automatically hit enemies",
	//	x + 17 + 20 , y + 27.72 + 44 + testY, NanoVGHelper::fontHarmony, 13, nvgRGBA(171, 161, 159, 255)
	//);

	//NanoVGHelper::nvgTextW(
	//	vg, L"CURRENTLY BOUNDTO: R",
	//	x + 17 + 20, y + 27.72 + 44 + 27 + testY, NanoVGHelper::fontGreycliffCFLight, 12, nvgRGBA(171, 161, 159, 255)
	//);

	//NanoVGHelper::nvgTextW(
	//	vg, L"\uEA58",
	//	x + width - 55 , y + 25 + 30 + testY, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(78, 76, 80, 255)
	//);

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + width - 116 , y + 25 + 30 + testY, 42.9, 20.46, NanoVGHelper::rgbaToColor(192, 224, 248, 255), 10
	//);

	//// ENABLE

	//NanoVGHelper::drawCircle(
	//	vg, x + width - 116 + 10 + 22.9 , y + 25 + 30 + 10 + testY, 10, -1
	//);

	//NanoVGHelper::renderShadow(
	//	vg, x + width - 116 + 22.9 , y + 25 + 30 + testY, 20, 20.46, 10, 4
	//);

	//// END

	//	//       HEIGHT      BOUND
	//testY += (73.26 + 11.22 + 26);

	//	// MODULE START

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + 17, y + 27.72 + testY, width - (17 * 2), 73.26, NanoVGHelper::rgbaToColor(255, 255, 255, 255), 5
	//);

	//NanoVGHelper::drawRoundedOutlineRect(
	//	vg, x + 17, y + 27.72 + testY, width - (17 * 2), 73.26, 5, 1, NanoVGHelper::rgbaToColor(227, 227, 227, 255)
	//);

	//NanoVGHelper::nvgTextW(vg, L"Crystal Aura", x + 17 + 20, y + 27.72 + 22 + testY, NanoVGHelper::fontHarmony, 17, nvgRGBA(79, 77, 80, 255));

	//NanoVGHelper::nvgTextW(
	//	vg, L"Atomatically hit ender crystals when you are infght",
	//	x + 17 + 20, y + 27.72 + 44 + testY, NanoVGHelper::fontHarmony, 13, nvgRGBA(171, 161, 159, 255)
	//);

	//NanoVGHelper::nvgTextW(
	//	vg, L"\uEA58",
	//	x + width - 55, y + 25 + 30 + testY, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(78, 76, 80, 255)
	//);

	//NanoVGHelper::drawRoundedRect(
	//	vg, x + width - 116, y + 25 + 30 + testY, 42.9, 20.46, NanoVGHelper::rgbaToColor(205, 197, 195, 255), 10
	//);

	//// DISABLE

	//NanoVGHelper::drawCircle(
	//	vg, x + width - 116 + 10, y + 25 + 30 + 10 + testY, 10, -1
	//);

	//NanoVGHelper::renderShadow(
	//	vg, x + width - 116, y + 25 + 30 + testY, 20, 20.46, 10, 4
	//);

	//// END
}

bool ModuleListsPage::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
	double horizontalAmount, double verticalAmount)
{
	if (Component::isHovering(x, y, width, height, mouseX, mouseY))
	{
		const float target = scrollAnimation.getTarget();
		const float offset = static_cast<float>(-(verticalAmount * 100));
		scrollAnimation.setTarget(target + offset);
		return true;
	}

	return false;
}

bool ModuleListsPage::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
	int button)
{
	for (auto& modInfo : moduleInfos)
	{
		modInfo->mouseReleased(0, 0, 0, 0, mouseX, mouseY, button);
	}

	return false;
}

bool ModuleListsPage::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY,
	int button)
{
	y -= scrollAnimation.getCurrent();

	float testY = 0;
	for (auto& modInfo : moduleInfos)
	{
		if (modInfo->mouseClicked(x, y + testY, width, height, mouseX, mouseY, button))
		{
			return true;
		}
		if (button == 2)
		{
			if (Component::isHovering(x + 17, y + testY + 27.72, width - (17 * 2), modInfo->height.getCurrent(), mouseX,
				mouseY))
			{
				modInfo->bindingKey = !modInfo->bindingKey;
			}
			else
			{
				modInfo->bindingKey = false;
			}
		}
		testY += ((modInfo->height.getCurrent()) + 11.22);
	}
	return false;
}

bool ModuleListsPage::keyPressed(int keyCode, int scanCode, int modifiers)
{
	for (auto& modInfo : moduleInfos)
	{
		if (modInfo->bindingKey)
		{
			modInfo->bindingKey = false;
			//                                        ESC
			modInfo->bindModule->setKeyCode(keyCode == 27 ? 0 : keyCode);
			return true;
		}
	}
	return false;
}

void ModuleListsPage::limit_scroll(const float height)
{
	if (component_height_ > height)
	{
		const float range = std::max(std::min(scrollAnimation.getTarget(), -(height - component_height_)), 0.0F);
		scrollAnimation.setTarget(range);
		return;
	}
	scrollAnimation.setTarget(0);
}
