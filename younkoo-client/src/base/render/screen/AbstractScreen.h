#pragma once


class AbstractScreen {
public:
	virtual void render(double mouseX, double mouseY) = 0;
	virtual void mouseMoved(double mouseX, double mouseY) = 0;
	virtual bool mouseClicked(double mouseX, double mouseY, int button) = 0;
	virtual bool mouseReleased(double mouseX, double mouseY, int button) = 0;
	virtual bool mouseDragged(double mouseX, double mouseY, int button, double deltaX, double deltaY) = 0;
	virtual bool mouseScrolled(double mouseX, double mouseY, double horizontalAmount, double verticalAmount) = 0;
	virtual bool keyPressed(int keyCode, int scanCode, int modifiers) = 0;
	virtual bool keyReleased(int keyCode, int scanCode, int modifiers) = 0;
	virtual bool charTyped(char chr, int modifiers) = 0;
	virtual void onGuiOpen() = 0;
	virtual void onGuiClose() = 0;

};

#include <base/render/gui/input/IOEvents.h>
namespace Register {
	inline void RegisterGui(AbstractScreen* screen) {

		YounkooIO::IOEvents.SetCursorPosCallback(
			[](HWND w, double x, double y) {

				return false;
			}
		);

		YounkooIO::IOEvents.SetMouseButtonCallback(
			[](HWND w, int button, int action, int modifiers) {
				return false;
			}
		);

		YounkooIO::IOEvents.SetKeyCallback(
			[](HWND w, int key, int scancode, int action, int mods) {

				return false;
			}
		);

		YounkooIO::IOEvents.SetCharCallback(
			[](HWND w, uint32_t codepoint) {
				return false;
			}
		);

		YounkooIO::IOEvents.SetDropCallback(
			[](HWND w, int count, const char** filenames) {
				return false;
			}
		);

		YounkooIO::IOEvents.SetScrollCallback(
			[](HWND w, double x, double y) {
				return false;
			}
		);

		/* React to framebuffer size events -- includes window
		   size events and also catches things like dragging
		   a window from a Retina-capable screen to a normal
		   screen on Mac OS X */
		YounkooIO::IOEvents.SetWindowSizeCallback(
			[](HWND w, int width, int height) {
				return false;
			}
		);

		// notify when the screen has lost focus (e.g. application switch)
		YounkooIO::IOEvents.SetWindowFoucsCallback(
			[](HWND w, bool focused) {
				return false;
				// focused: 0 when false, 1 when true
			}
		);
	}
}
