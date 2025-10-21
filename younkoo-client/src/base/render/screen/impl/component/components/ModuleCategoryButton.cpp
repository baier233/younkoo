#include "ModuleCategoryButton.h"
#include <base\features\modules\AbstractModule.h>
static NVGcolor selectColor = nvgRGBA(47, 153, 238, 255);
static NVGcolor normalColor = nvgRGBA(79, 77, 80, 255);

static int testCOlor = NanoVGHelper::rgbaToColor(0, 0, 0, 25);

ModuleCategoryButton::ModuleCategoryButton(Category category)
{
	moduleCategory = category;
	displayName = getCategoryDisplayName(category);
	icon = getCategoryIcon(category);
}


void ModuleCategoryButton::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY,bool flag)
{
	if (!flag) {
		if (!animation.isFinished())
			animation.calculate();

		if (Component::isHovering(x + 16, y + 140, 150, 30, mouseX, mouseY)) {
			animation.setTarget(1);
			animation.calculate();
		} else {
			animation.setTarget(0);
			animation.calculate();
		}

		NanoVGHelper::drawRoundedRect(vg, x + 16, y + 140, 150, 30, NanoVGHelper::rgbaToColor(0, 0, 0, animation.getCurrent() * 25), 5);
	}

	NVGcolor color = flag ? selectColor : normalColor;
	
	NanoVGHelper::nvgTextW(vg, displayName, x + 58, y + 150, NanoVGHelper::fontHarmony, 15, color, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	NanoVGHelper::nvgTextW(vg, icon, x + 26.6, y + 148, NanoVGHelper::fontMaterialIcon, 15, color, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
}


