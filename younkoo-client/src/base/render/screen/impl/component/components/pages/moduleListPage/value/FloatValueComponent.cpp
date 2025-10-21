#include "FloatValueComponent.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>


FloatValueComponent::FloatValueComponent(FloatValue* floatValue)
{
    value = floatValue;
}

bool FloatValueComponent::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                                        double horizontalAmount, double verticalAmount)
{
    return false;
}

bool FloatValueComponent::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
                                        int button)
{
    if (clicked_)
    {
        //LOG_N("Mouse Released" << '\n');
        clicked_ = false;
    }
    return false;
}

bool FloatValueComponent::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY,
                                       int button)
{
    if (isHovering(slider_x_, slider_y_, slider_width_, slider_height_, mouseX, mouseY))
    {
        clicked_ = true;
        return true;
    }
    return false;
}

bool FloatValueComponent::keyPressed(int keyCode, int scanCode, int modifiers)
{
    return false;
}

void FloatValueComponent::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX,
                               double mouseY)
{
    NanoVGHelper::nvgTextW(vg, wstr::toString(value->getName()), x + 17 + 20, y + 27.72 + 22, NanoVGHelper::fontHarmony,
                           16, nvgRGBA(79, 77, 80, 255));

    const float right = x + width - 39.0F;

    slider_x_ = right - slider_width_;
    slider_y_ = y + 51.0F;

    const float range = value->getMax() - value->getMin();
    const float percent = (value->getValue() - value->getMin()) / range;
    const float target_width = slider_width_ * percent;

    NanoVGHelper::drawRoundedRect(
        vg,
        slider_x_,
        slider_y_,
        slider_width_,
        slider_height_,
        NanoVGHelper::rgbaToColor(222, 223, 223, 255),
        4.0F
    );

    NanoVGHelper::drawRoundedRect(
        vg,
        slider_x_,
        slider_y_,
        target_width,
        slider_height_,
        NanoVGHelper::rgbaToColor(42, 129, 255, 255),
        4.0F
    );

    const std::string value_string = std::format("{:.2f}", value->getValue());

    const auto [text_width, text_height] = NanoVGHelper::nvgTextBoundsW(
        vg,
        wstr::toString(value_string),
        NanoVGHelper::fontHarmony,
        16
    );

    float text_x = slider_x_ + target_width - text_width;
    if (text_x < slider_x_)
    {
        text_x = slider_x_ + target_width;
    }

    NanoVGHelper::nvgTextW(
        vg,
        wstr::toString(value_string),
        text_x,
        slider_y_ - 16.0F,
        NanoVGHelper::fontHarmony,
        16,
        nvgRGBA(79, 77, 80, 128)
    );

    if (clicked_)
    {
        /* 默认保留 2 位小数点 */
        constexpr float inc = 0.01F;
        const float value_absolute = static_cast<float>(mouseX) - slider_x_;
        const float value_percent = std::min(std::max(value_absolute / slider_width_, 0.0F), 1.0F);
        const float value_relative = value_percent * range;
        const float predict = value->getMin() + value_relative;
        const float value_result = std::round(predict * (1.0F / inc)) / (1.0F / inc);
        //LOG_N(value_result << '\n');
        value->setValue(*(int64_t*)&value_result);
    }
}
