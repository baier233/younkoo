#include "Renderer.hpp"
#include "hooks/OpenGLHook.hpp"


auto Renderer::update(const float mouse_x, const float mouse_y) -> void
{
	delta_x = mouse_x - last_mouse_x;
	delta_y = mouse_y - last_mouse_y;
	last_mouse_x = mouse_x;
	last_mouse_y = mouse_y;
}

bool Renderer::Init()
{
	return OpenGLHook::Init();
}

bool Renderer::Shutdown()
{
	return OpenGLHook::Clean() && wglDeleteContext(renderContext.MenuGLContext);
}
