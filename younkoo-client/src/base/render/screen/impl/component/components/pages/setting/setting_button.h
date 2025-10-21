#pragma once

#include <functional>
#include "base/render/screen/impl/component/Component.h"

class setting_button final : Component
{
public:
	explicit setting_button(std::string title, const std::function<void(setting_button& button)>& callback);

	void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
	bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
		double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
	inline void set_title(const std::string& title) {
		this->title_ = title;
	}
	float x = 0.0F;
	float y = 0.0F;
	float width = 0.0F;
	float height = 0.0F;

private:
	std::string title_ = {};
	std::function<void(setting_button& button)> callback_ = nullptr;
};
