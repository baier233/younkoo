#pragma once
#include <base/render/screen/AbstractScreen.h>
namespace GuiInstance {
	namespace Instance {
		inline AbstractScreen* screen;
		inline double x = 0, y = 0;
	}
	void RegisterGui(AbstractScreen* screen);
	void DrawGui();
	bool MouseInZone(const Math::Vector2D& pos, const Math::Vector2D& size);
}
