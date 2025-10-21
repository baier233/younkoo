#pragma once
#include <base\render\screen\impl\component\Component.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include "moduleListPage\ModuleInfo.h"

class ModuleListsPage : public Component
{
public:
    Category selectComponent;
    ModuleListsPage(Category category);
    void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
    bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                       double horizontalAmount, double verticalAmount) override;
    bool keyPressed(int keyCode, int scanCode, int modifiers) override;
    std::vector<std::shared_ptr<ModuleInfo>> moduleInfos;

private:

    void limit_scroll(float height);
    
    float component_height_ = 0.0F;
    AnimationObject scrollAnimation = AnimationObject(300, Easing::EASE_OUT_CRIC());
};
