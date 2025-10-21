#pragma once
#include <base\render\screen\impl\component\components\pages\moduleListPage\ValueComponent.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>
class FloatValueComponent : public ValueComponent
{
public:
	FloatValueComponent(FloatValue* floatValue);
	void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
	bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
	FloatValue* value;

private:
	float slider_x_ = 0.0F;
	float slider_y_ = 0.0F;
	float slider_width_ = 380.0F;
	float slider_height_ = 8.0F;
	bool clicked_ = false;
};