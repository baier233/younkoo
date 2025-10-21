#include "BooleanValueComponent.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>


BooleanValueComponent::BooleanValueComponent(BoolValue* boolValue)
{
    value_ = boolValue;
}

bool BooleanValueComponent::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                                          double horizontalAmount, double verticalAmount)
{
    return false;
}

bool BooleanValueComponent::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
                                          int button)
{
    return false;
}

bool BooleanValueComponent::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY,
                                         int button)
{
    if (isHovering(this->x_ + this->width_ - 37.0F - switch_width_, this->y_ + 49.72F, switch_width_, switch_height_, mouseX, mouseY))
    {
        this->value_->setValue(!this->value_->getValue());
        return true;
    }
    return false;
}

bool BooleanValueComponent::keyPressed(int keyCode, int scanCode, int modifiers)
{
    return false;
}

void BooleanValueComponent::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX,
                                 double mouseY)
{
    /* TODO: 因为计算的不一样，所以要先保存，很奇怪的框架 */
    this->x_ = x;
    this->y_ = y;
    this->width_ = width;
    this->height_ = height;
    
    const float value_x = x + 37.0F;
    const float value_y = y + 49.72F;
    const float switch_x = x + width - 37.0F - switch_width_;

    const bool switch_hovered = isHovering(switch_x, value_y, switch_width_, switch_height_, mouseX, mouseY);

    hovered_animation_.setTarget(switch_hovered ? 1.0 : 0.0);
    hovered_animation_.calculate();
    const float normalize = hovered_animation_.getCurrent();
    const float append_radius = 5.0F * normalize;
    const int color_offset = static_cast<int>(40 * normalize);
    const int switch_color = 220 - color_offset;

    NanoVGHelper::nvgTextW(
        vg, wstr::toString(value_->getName()), value_x, value_y, NanoVGHelper::fontHarmony, 16,
        nvgRGBA(79, 77, 80, 255)
    );

    NanoVGHelper::drawRoundedRect(
        vg, switch_x, value_y, switch_width_, switch_height_,
        value_->getValue()
            ? NanoVGHelper::rgbaToColor(42, 129, 255, 255)
            : NanoVGHelper::rgbaToColor(switch_color, switch_color, switch_color, 255),
        5.0F + append_radius
    );

    if (value_->getValue())
    {
        NanoVGHelper::drawRoundedRect(
            vg, switch_x + 5.0f, value_y + 5.0f, switch_width_ - 10.0f, switch_height_ - 10.0f,
            NanoVGHelper::rgbaToColor(255, 255, 255, 255),
            2.0F + append_radius
        );
    }
}
