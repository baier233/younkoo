#pragma once
#include <base/render/screen/AbstractScreen.h>

class GuiScreen : public AbstractScreen {
public:
	GuiScreen();
	void render(double mouseX, double mouseY) override;
	void mouseMoved(double mouseX, double mouseY) override;
	bool mouseClicked(double mouseX, double mouseY, int button) override;
	bool mouseReleased(double mouseX, double mouseY, int button) override;
	bool mouseDragged(double mouseX, double mouseY, int button, double deltaX, double deltaY) override;
	bool mouseScrolled(double mouseX, double mouseY, double horizontalAmount, double verticalAmount) override;
	bool keyPressed(int keyCode, int scanCode, int modifiers) override;
	bool keyReleased(int keyCode, int scanCode, int modifiers) override;
	bool charTyped(char chr, int modifiers) override;
	void onGuiOpen() override;
	void onGuiClose() override;
	void closeGui();
protected:
	bool title_clicked_ = false;
	bool shouldQuit = false;
};