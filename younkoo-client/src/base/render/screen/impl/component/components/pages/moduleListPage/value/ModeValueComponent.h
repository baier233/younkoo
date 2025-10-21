#pragma once
#include <base\render\screen\impl\component\components\pages\moduleListPage\ValueComponent.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>

class ModeValueComponent;

class ModeValueSelection : public Component
{
public:
    ModeValueSelection(ModeValueComponent* parent, ModeValue* value, int index, const std::string& description);
    void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
    bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                       double horizontalAmount, double verticalAmount) override;
    bool keyPressed(int keyCode, int scanCode, int modifiers) override;

    ModeValue* value = nullptr;
    int index = 0;
    std::string description;

    float description_x = 0.0F;
    float description_y = 0.0F;
    float description_width = 0.0F;
    float description_height = 0.0F;

    ModeValueComponent* parent;
};

class ModeValueComponent : public ValueComponent
{
public:
    ModeValueComponent(ModeValue* modeValue);
    void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
    bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
                       double horizontalAmount, double verticalAmount) override;
    bool keyPressed(int keyCode, int scanCode, int modifiers) override;
    ModeValue* value;

    bool selection_ = false;
    
private:
    std::vector<std::shared_ptr<ModeValueSelection>> components_ = {};
    AnimationObject hovered_animation_{300, Easing::EASE_OUT_BACK()};
    bool hovered_ = false;
    float rectangle_x_ = 0.0F;
    float rectangle_y_ = 0.0F;
    float rectangle_width_ = 0.0F;
    float rectangle_height_ = 0.0F;
    float last_text_width_ = 0.0F;
};
