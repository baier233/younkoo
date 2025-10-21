#pragma once
#include <base\render\screen\impl\component\Component.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>
#include "ValueComponent.h"
class ModuleInfo : public Component
{
public:
	ModuleInfo(AbstractModule* hack);
	void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
	bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
	bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY, double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
	AbstractModule* bindModule;
	//float height = -1;
	bool bindingKey = false;
	bool showValues = false;
	AnimationObject height = AnimationObject(500, Easing::EASE_OUT_QUAD());
	std::vector<std::shared_ptr<ValueComponent>> moduleValues;
private:
	float componentHeight = 100.0F; // BASE
	AnimationObject toggleAnimation = AnimationObject(130, Easing::EASE_OUT_QUAD());
};