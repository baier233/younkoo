#pragma once

#include <base\render\screen\impl\component\Component.h>

#include "setting/setting_button.h"

class setting_page final : public Component
{
public:
    setting_page();
    void draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY) override;
    bool mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button) override;
    bool mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
        double horizontalAmount, double verticalAmount) override;
    bool keyPressed(int keyCode, int scanCode, int modifiers) override;

    std::vector<std::shared_ptr<setting_button>> buttons;
};
