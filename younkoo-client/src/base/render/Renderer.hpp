#pragma once
#include <Windows.h>

#include <vector>
#include <string>

#include "../../utils/Singleton.hpp"
#include "../../utils/Structs.hpp"

struct RenderContext
{
    HGLRC OriginalGLContext = 0;
    HGLRC MenuGLContext = 0;
    HDC HandleDeviceContext = 0;
    HWND HandleWindow = 0;
    std::string ClassName;
    float devicePixelRatio = 1;
    std::pair<int, int> winSize;
};


class Renderer : public Singleton<Renderer>
{
protected:
public:
    Renderer()
    {
        renderContext.OriginalGLContext = 0;
        renderContext.MenuGLContext = 0;
        renderContext.HandleDeviceContext = 0;
        renderContext.HandleWindow = 0;
    }

    auto update(float mouse_x,float mouse_y) -> void;

    RenderContext renderContext;

    float last_mouse_x = 0.0F;
    float last_mouse_y = 0.0F;
    float delta_x = 0.0F;
    float delta_y = 0.0F;

    bool Initialized = 0;

    bool Init();
    bool Shutdown();
};
