#include "GuiScreen.h"
#include <base/render/nano/NanovgHelper.hpp>
#include <base/render/Renderer.hpp>
#include <base/render/screen/instance/GuiInstance.h>
#include <base/render/gui/input/Context.hpp>
#include <base/render/gui/input/Context.hpp>

static double width = 830, height = 500;
static bool isDrag = false;
static float posX = -1, posY = -1;

static auto SIDEBAR_BACKGROUND = nvgRGBA(255, 255, 255, 255);
static auto BASE_BACKGROUND = nvgRGBA(251, 255, 255, 255);
#include <memory>
#include "component\Component.h"
#include "component\components\SliderBar.h"
#include <utils\animation\Animation.h>
#include "component\components\PageFrame.h"
#include "component\components\Debugger.h"
#include "component\components\TopBar.h"
static std::vector<std::shared_ptr<Component>> components;

AnimationObject testAnimation = AnimationObject(500, Easing::EASE_OUT_Expo());


GuiScreen::GuiScreen()
{
	components.push_back(std::make_shared<SliderBar>());

	components.push_back(PageFrame::getInstance());

	components.push_back(std::make_shared<TopBar>());

	//components.push_back(std::make_shared<Debugger>());
}


float clamp(float number, float min, float max)
{
	return std::clamp(number, min, max);
}

#include <base/render/gui/GUI.h>

void GuiScreen::render(double mouseX, double mouseY)
{
	Renderer::get().update(static_cast<float>(mouseX), static_cast<float>(mouseY));
	auto vg = NanoVGHelper::Context;
	static auto& context = Renderer::get().renderContext;
	auto [winWidth, winHeight] = context.winSize;
	if (posX == -1 && posY == -1)
	{
		posX = winWidth / 2.f - width / 2.f;
		posY = (winHeight / 2.f - height / 2.f) - 12.5;
	}

	if (title_clicked_)
	{
		posX += Renderer::get().delta_x;
		posY += Renderer::get().delta_y;
	}

	posX = std::max(0.0F, posX);
	posY = std::max(0.0F, posY);

	if (shouldQuit)
	{
		testAnimation.setTarget(0);
		testAnimation.calculate();

		if (testAnimation.isFinished())
		{
			closeGui();
			return;
		}
	}
	else
	{
		testAnimation.setTarget(0.1f);
		testAnimation.calculate();
	}

	nvgGlobalAlpha(vg, clamp(testAnimation.getCurrent() * 10.0f, 0, 1));


	NanoVGHelper::startScale(vg, posX + (width / 2), posY + (height / 2),
		clamp(.9f + testAnimation.getCurrent(), 0.9f, 1.0f));

	//NanoVGHelper::drawDropShadow(vg, posX + 5, posY + 5 , width - 10 , height - 10 ,15,2,1);
	NanoVGHelper::renderShadow(vg, posX, posY, width, height, 5, 5);
	NanoVGHelper::drawRoundedRect(vg, posX, posY, width, height, NanoVGHelper::nvgColorToRGB(BASE_BACKGROUND), 5);

	NanoVGHelper::drawRoundedRect(vg, posX, posY, 181.5, height, NanoVGHelper::nvgColorToRGB(SIDEBAR_BACKGROUND), 5);

	NanoVGHelper::nvgTextStr(vg, "younkoo", posX + 15, posY + 65, NanoVGHelper::fontHarmony, 20,
		nvgRGBA(76, 76, 76, 255));

	// >
	NanoVGHelper::nvgTextW(
		vg, L"\uEA58",
		posX + 148, posY + 62, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(78, 76, 80, 255)
	);


	NanoVGHelper::drawLine(vg, posX + 181.5, posY, posX + 181.5, posY + height, 0.5,
		NanoVGHelper::rgbaToColor(196, 196, 196, 255));

	NanoVGHelper::drawLine(vg, posX + 181.5, posY + 43, posX + width, posY + 43, 0.5,
		NanoVGHelper::rgbaToColor(196, 196, 196, 255));

	NanoVGHelper::drawLine(vg, posX, posY + 100, posX + 181.5, posY + 100, 0.5,
		NanoVGHelper::rgbaToColor(196, 196, 196, 255));

	NanoVGHelper::drawLine(vg, posX, posY + 380, posX + 181.5, posY + 380, 0.5,
		NanoVGHelper::rgbaToColor(196, 196, 196, 255));

	for (auto& component : components)
	{
		component->draw(vg, posX, posY, width, height, mouseX, mouseY);
	}

	NanoVGHelper::stopScale();


	//NanoVGHelper::nvgRect(vg, mouseX, mouseY, 300, 100, nvgRGBA(0, 0, 0, 80));
	//NanoVGHelper::nvgTextW(vg, std::to_wstring(mouseX) + L" " + std::to_wstring(mouseY), mouseX + 10, mouseY + 10, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	//NanoVGHelper::nvgTextW(vg, std::to_wstring(testAnimation.getCurrent()), mouseX + 10, mouseY + 40, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	//

	//nvgEndFrame(vg);

	nvgGlobalAlpha(vg, 1);
}

void GuiScreen::mouseMoved(double mouseX, double mouseY)
{
}

bool GuiScreen::mouseClicked(double mouseX, double mouseY, int button)
{
	if (Component::isHovering(posX, posY, static_cast<float>(width), 16, mouseX, mouseY))
	{
		title_clicked_ = true;
		return NanoGui::available;
	}
	for (auto& component : components)
	{
		component->mouseClicked(posX, posY, width, height, mouseX, mouseY, button);
	}
	return NanoGui::available;
}

bool GuiScreen::mouseReleased(double mouseX, double mouseY, int button)
{
	if (title_clicked_)
	{
		title_clicked_ = false;
	}
	for (auto& component : components)
	{
		component->mouseReleased(posX, posY, width, height, mouseX, mouseY, button);
	}
	return NanoGui::available;
}

bool GuiScreen::mouseDragged(double mouseX, double mouseY, int button, double deltaX, double deltaY)
{
	return false;
}

bool GuiScreen::mouseScrolled(double mouseX, double mouseY, double horizontalAmount, double verticalAmount)
{

	for (auto& component : components)
	{
		component->mouseScrolled(posX, posY, width, height, mouseX, mouseY, horizontalAmount, verticalAmount);
	}

	return NanoGui::available;
}

bool GuiScreen::keyPressed(int keyCode, int scanCode, int modifiers)
{
	if (shouldQuit && keyCode == 16)
	{
		// 打断动画
		shouldQuit = false;
		return true;
	}

	bool flag = false;

	for (auto& component : components)
	{
		if (component->keyPressed(keyCode, scanCode, modifiers))
			flag = true;
	}

	return flag;
}

bool GuiScreen::keyReleased(int keyCode, int scanCode, int modifiers)
{
	return false;
}

bool GuiScreen::charTyped(char chr, int modifiers)
{
	return false;
}


void GuiScreen::onGuiOpen()
{
	shouldQuit = false;
}

void GuiScreen::onGuiClose()
{
	shouldQuit = true;
}


void GuiScreen::closeGui()
{


	NanoGui::available = false;
}
