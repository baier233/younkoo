#pragma once
#include "../Component.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>

	
class ModuleCategoryButton
{
public:
	Category moduleCategory;
	std::wstring displayName;
	std::wstring icon;
	ModuleCategoryButton(Category category);
	void draw(NVGcontext *vg, float x, float y, float width, float height, double mouseX, double mouseY, bool flag);
private:
	AnimationObject animation = AnimationObject(130, Easing::EASE_IN_QUAD());
};