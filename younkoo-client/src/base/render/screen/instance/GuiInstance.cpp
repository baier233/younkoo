#include "GuiInstance.h"
#include <base/render/gui/input/Context.hpp>
#include <base/render/gui/api/VirtualKey.h>

static auto devicePixel = 1.f;
#include <base/render/Renderer.hpp>
#include <base/render/gui/GUI.h>
void GuiInstance::RegisterGui(AbstractScreen* screen)
{
	devicePixel = Renderer::get().renderContext.devicePixelRatio;
	Instance::screen = screen;
	YounkooIO::IOEvents.SetCursorPosCallback(
		[](HWND w, double x, double y) {
			if (!NanoGui::available) return false;
			Instance::x = x / devicePixel;
			Instance::y = y / devicePixel;
			Instance::screen->mouseMoved(x / devicePixel, y / devicePixel);
			return false;
		}
	);

	YounkooIO::IOEvents.SetMouseButtonCallback(
		[](HWND w, int button, int action, int modifiers) {
			if (!NanoGui::available) return false;
			if (action == CALLBACK_PRESS)
			{
				return Instance::screen->mouseClicked(Instance::x, Instance::y, button);
			}
			else if (action == CALLBACK_RELEASE) {
				return Instance::screen->mouseReleased(Instance::x, Instance::y, button);
			}
			return false;
		}
	);

	YounkooIO::IOEvents.SetKeyCallback(
		[](HWND w, int key, int scancode, int action, int mods) {
			if (!NanoGui::available) return false;
			if (action == CALLBACK_PRESS)
			{
				return Instance::screen->keyPressed(key, scancode, mods);
			}
			else if (action == CALLBACK_RELEASE) {
				return Instance::screen->keyReleased(key, scancode, mods);
			}
			return false;
		}
	);

	YounkooIO::IOEvents.SetCharCallback(
		[](HWND w, uint32_t codepoint) {
			if (!NanoGui::available) return false;
			return Instance::screen->charTyped(codepoint, getKeyMods());
		}
	);


	YounkooIO::IOEvents.SetScrollCallback(
		[](HWND w, double x, double y) {
			if (!NanoGui::available) return false;
			Instance::screen->mouseScrolled(Instance::x, Instance::y, x / devicePixel, y / devicePixel);
			return true;
		}
	);

}

void GuiInstance::DrawGui()
{
	Instance::screen->render(Instance::x, Instance::y);
}

bool GuiInstance::MouseInZone(const Math::Vector2D& pos, const Math::Vector2D& size)
{
	const Math::Vector2D& cursor_pos = { Instance::x,Instance::y };

	if (cursor_pos.x > pos.x && cursor_pos.y > pos.y)
		if (cursor_pos.x < pos.x + size.x && cursor_pos.y < pos.y + size.y)
			return true;
	return false;

}
