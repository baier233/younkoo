#include "Chams.h"
TitanHook<decltype(&glScalef)> glScalefHook;

Chams& Chams::getInstance()
{
	static Chams inst = Chams();
	return inst;
}

void Chams::onEnable()
{
	glScalefHook.SetHook();
}

void Chams::onDisable()
{
	glScalefHook.RemoveHook();
}

void Chams::onUpdate()
{
	ToggleCheck;
}
void WINAPI hk_glScalef(float x, float y, float z)
{
	if (x == 0.9375)
	{
		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1.0f, -1100000.0f);
	}
	else {
		if (x == 0.00390625 || x == 0.666667 || x == 0.0104167 || x == -0.0266667)
		{
			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1.0f, 1100000.0f);
		}
		else {
			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1.0f, 1100000.0f);
		}

		if (x > 0.f)
		{
			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1.0f, 1100000.0f);
		}


	}
	// Calling the original function
	glScalefHook.GetOrignalFunc()(x, y, z);
}
Chams::Chams() :AbstractModule(xorstr_("Chams"), Category::VISUAL, xorstr_("此模块可能不绕过OBS！！！"))
{
	glScalefHook.InitHook(glScalef, hk_glScalef);
}
