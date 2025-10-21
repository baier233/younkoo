#include <iostream>

#include "SettingPage.h"
#include "base/Younkoo.hpp"
#include "base/config/ConfigManager.h"
#include "base/render/gui/GUI.h"
static bool useWinAPI = false;
auto click_api = std::make_shared<setting_button>(
	"Change ClickAPI(Wrap)",
	[](setting_button& button)
	{
		button.set_title((useWinAPI ? "Change ClickAPI(WinAPI)" : "Change ClickAPI(Wrap)"));
		useWinAPI = !useWinAPI;
	}
);

setting_page::setting_page()
{

	buttons.emplace_back(
		std::make_shared<setting_button>(
			"Open Directory",
			[](setting_button&)
			{
				ConfigManager::get().OpenConfigDirectory();
			}
		)
	);
	buttons.emplace_back(
		std::make_shared<setting_button>(
			"Load Config",
			[](setting_button&)
			{
				ConfigManager::get().LoadConfig("config.json");
			}
		)
	); buttons.emplace_back(
		std::make_shared<setting_button>(
			"Save Config",
			[](setting_button&)
			{
				ConfigManager::get().SaveConfig("config.json");
			}
		)
	);
			buttons.emplace_back(
				std::make_shared<setting_button>(
					"Detach",
					[](setting_button&)
					{
						Younkoo::get().shouldShutDown = true;
					}
				)
			);
			buttons.emplace_back(click_api);
}

void setting_page::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	float start_y = y + 16.0F;
	for (const auto& setting_button : buttons)
	{
		setting_button->x = x + 16.0F;
		setting_button->y = start_y;
		setting_button->draw(vg, 0, 0, 0, 0, mouseX, mouseY);
		start_y = setting_button->y + setting_button->height + 8.0F;
	}
}

bool setting_page::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button)
{
	/* 不清楚为什么要传 x,y,width,height 暂时直接填 0 了 */
	for (const auto& setting_button : buttons)
	{
		setting_button->mouseClicked(0, 0, 0, 0, mouseX, mouseY, button);
	}
	return false;
}

bool setting_page::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button)
{
	for (const auto& setting_button : buttons)
	{
		setting_button->mouseReleased(0, 0, 0, 0, mouseX, mouseY, button);
	}
	return false;
}

bool setting_page::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
	double horizontalAmount, double verticalAmount)
{
	return false;
}

bool setting_page::keyPressed(int keyCode, int scanCode, int modifiers)
{
	return false;
}
