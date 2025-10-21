#pragma once
#include <base\render\screen\impl\component\components\pages\moduleListPage\ValueComponent.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>

class BooleanValueComponent : public ValueComponent
{
public:
    BooleanValueComponent(BoolValue* boolValue);
    void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
    bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                       double horizontalAmount, double verticalAmount) override;
    bool keyPressed(int keyCode, int scanCode, int modifiers) override;

private:
    float x_ = 0.0F;
    float y_ = 0.0F;
    float width_ = 0.0F;
    float height_ = 0.0F;
    
    float switch_width_ = 20.0F;
    float switch_height_ = 20.0F;
    AnimationObject hovered_animation_{200, Easing::EASE_OUT_CRIC()};
    BoolValue* value_;
};
