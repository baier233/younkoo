#include "ModeValueComponent.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>


ModeValueSelection::ModeValueSelection(ModeValueComponent* parent, ModeValue* value, int index,
                                       const std::string& description)
{
    this->parent = parent;
    this->value = value;
    this->index = index;
    this->description = description;
}

void ModeValueSelection::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
    const auto description_w = wstr::toString(description);

    auto [description_width_,description_height_] = NanoVGHelper::nvgTextBoundsW(
        vg,
        description_w,
        NanoVGHelper::fontHarmony,
        16
    );
    this->description_x = x;
    this->description_y = y;
    this->description_width = description_width_;
    this->description_height = description_height_;

    NanoVGHelper::nvgTextW(
        vg,
        description_w,
        x,
        y,
        NanoVGHelper::fontHarmony,
        16,
        nvgRGBA(79, 77, 80, 128)
    );
}

bool ModeValueSelection::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY,
                                      int button)
{
    if (isHovering(this->description_x, this->description_y, this->description_width, this->description_height, mouseX,
                   mouseY))
    {
        value->setValue(this->index);
        parent->selection_ = false;
        return true;
    }
    return false;
}

bool ModeValueSelection::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
                                       int button)
{
    return false;
}

bool ModeValueSelection::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                                       double horizontalAmount, double verticalAmount)
{
    return false;
}

bool ModeValueSelection::keyPressed(int keyCode, int scanCode, int modifiers)
{
    return false;
}

ModeValueComponent::ModeValueComponent(ModeValue* modeValue)
{
    value = modeValue;
    for (int i = 0; i < value->getDescs().size(); ++i)
    {
        components_.emplace_back(
            std::make_shared<ModeValueSelection>(
                this, value, i, value->getDescs()[i]
            )
        );
    }
}

bool ModeValueComponent::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                                       double horizontalAmount, double verticalAmount)
{
    return false;
}

bool ModeValueComponent::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
                                       int button)
{
    return false;
}

bool ModeValueComponent::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY,
                                      int button)
{
    if (selection_)
    {
        for (const auto& selection : components_)
        {
            selection->mouseClicked(0, 0, 0, 0, mouseX, mouseY, button);
        }
    }

    if (hovered_)
    {
        selection_ = !selection_;
        return true;
    }
    return false;
}

bool ModeValueComponent::keyPressed(int keyCode, int scanCode, int modifiers)
{
    return false;
}

void ModeValueComponent::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
    hovered_ = isHovering(rectangle_x_, rectangle_y_, rectangle_width_, rectangle_height_, mouseX, mouseY);

    NanoVGHelper::nvgTextW(vg, wstr::toString(value->getName()), x + 17 + 20, y + 27.72 + 22, NanoVGHelper::fontHarmony,
                           16, nvgRGBA(79, 77, 80, 255));

    hovered_animation_.setTarget(selection_ ? 1.0 : 0.0);
    hovered_animation_.calculate();

    const float normalize = hovered_animation_.getCurrent();


    const float right = x + width - 39.0F;
    const auto render_text = wstr::toString(value->getDescs()[value->getValue()]);
    auto [text_width,text_height] = NanoVGHelper::nvgTextBoundsW(
        vg,
        render_text,
        NanoVGHelper::fontHarmony,
        16
    );
    const float children_height = value->getModes().size() * (text_height + 5.0F) * normalize;
    if (last_text_width_ == 0.0F)
    {
        last_text_width_ = text_width;
    }

    rectangle_x_ = right - last_text_width_ - 8.0F;
    rectangle_y_ = y + 49.72F;
    rectangle_width_ = last_text_width_ + 8.0F;
    rectangle_height_ = text_height + 8.0F;

    const float render_height = normalize == 0.0F ? rectangle_height_ : rectangle_height_ + children_height;
    NanoVGHelper::drawRoundedOutlineRect(
        vg,
        rectangle_x_,
        rectangle_y_,
        rectangle_width_,
        render_height,
        5.0F,
        1.0F,
        NanoVGHelper::rgbaToColor(222, 223, 223, 255)
    );

    NanoVGHelper::nvgTextW(
        vg,
        render_text,
        rectangle_x_ + 5.0F,
        rectangle_y_ + 5.0F,
        NanoVGHelper::fontHarmony,
        16,
        nvgRGBA(79, 77, 80, 255)
    );

    if (normalize != 0.0)
    {
        const auto scissor = NanoVGHelper::scissorHelper.scissor(
            vg,
            rectangle_x_,
            rectangle_y_,
            rectangle_width_,
            render_height
        );

        float start_y = rectangle_y_ + rectangle_height_;
        for (const auto& selection : components_)
        {
            const auto description_w = wstr::toString(selection->description);

            selection->draw(
                vg,
                rectangle_x_ + 5.0F,
                start_y,
                0.0F,
                0.0F,
                mouseX,
                mouseY
            );

            if (selection->description_width > last_text_width_)
            {
                last_text_width_ = selection->description_width;
            }
            start_y += selection->description_height + 5.0F;
        }

        NanoVGHelper::scissorHelper.resetScissor(vg, scissor);
    }

    component_height_ = 35.0F + children_height;

    if (text_width > last_text_width_)
    {
        last_text_width_ = text_width;
    }
}
