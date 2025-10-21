#include "TargetHud.h"
#include "base/render/hooks/WndProcHook.hpp"
#include "base/GitInfo.h"
#include <utils/Wstr.h>
#include "../ModuleManager.h"
#include <base/render/gui/GUI.h>
#include <utils/Math.h>

TargetHud::TargetHud() : AbstractModule(xorstr_("TargetHud"), Category::VISUAL, xorstr_("TargetHud."))
{
	REGISTER_EVENT(EventRender2D, TargetHud::onRender);
}


TargetHud& TargetHud::getInstance()
{
	static TargetHud instance = TargetHud();
	return instance;
}
static float hp = 0, maxHp = 0, absorptionAmount = 0;
static std::wstring displayName{};
void TargetHud::onUpdate()
{
	ToggleCheck;
	if (clear)
	{
		renderTarget = std::nullopt;
		return;
	}
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.isInGuiState()) return;

	auto thePlayer = mc.getPlayer();

	if (!renderTarget.has_value()) return;

	if (!thePlayer.canEntityBeSeen(renderTarget.value()))
	{
		return;
	}
	auto target = renderTarget.value();
	hp = target.getHealth();
	maxHp = target.getMaxHealth();
	absorptionAmount = target.getAbsorptionAmount();
	displayName = wstr::toString(target.getDisplayName());

}

void TargetHud::onEnable()
{
}

void TargetHud::onDisable()
{
}

float healthAnimation = 0.0f;

#include <utils/strutils.h>
#include <base/render/Renderer.hpp>
#include <utils/animation/Animation.h>
static auto animationObject = AnimationObject(500, Easing::EASE_IN_OUT_BACK());
void TargetHud::onRender(const EventRender2D& e)
{
	using namespace NanoVGHelper;

	ToggleCheck;

	if (NanoGui::available) return;

	static auto dpi = Renderer::get().renderContext.devicePixelRatio;
	if (clear) {
		healthAnimation = 0.0f;
		animationObject.reset();
		animationObject.setTarget(dpi);
		return;
	}


	float x = e.winWidth / 2.f + 100.f * dpi;
	float y = (e.winHeight / 2.f) + 100.f * dpi;
	float headSize = 28;
	float spacing = 5;
	float width = (234 / 1.75f);
	float height = (93.75f / 1.75f);
	animationObject.calculate();
	startScale(e.vg, x + width / 2.f, y + height / 2.f, animationObject.getCurrent());

	healthAnimation = MathHelper::fast(healthAnimation, MathHelper::clamp_float(hp / maxHp, 0, 1), 10);
	drawRoundedRect(e.vg, x, y, width, height, rgbaToColor(0, 0, 0, 150), 8);
	drawDropShadow(e.vg, x, y, width, height, 15, 0, 8);
	auto name(displayName);
	auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, name, NanoVGHelper::fontHarmonyBold, 15);
	if (bounds.first > width)
	{
		name = std::wstring(name.c_str(), 10) + L"...";
	}
	nvgTextW(e.vg, name, x + headSize + spacing + spacing - 28,
		y + 8, fontHarmonyBold, 15, nvgRGBA(200, 200, 200, 255));

	nvgTextW(e.vg, L"HP: " + std::to_wstring((int)hp + (int)absorptionAmount), x + headSize + spacing + spacing - 28, y + 25, fontHarmonyBold, 15, nvgRGBA(255, 255, 255, 255));

	drawRoundedRect(e.vg, x + headSize + spacing + spacing - 28, y + height - spacing * 2 - 3, (width - 20), 4, rgbaToColor(32, 32, 32, 255), 2);
	drawDropShadow(e.vg, x + headSize + spacing + spacing - 28, y + height - spacing * 2 - 3, (width - 20) * healthAnimation, 4, 8, 0, 2);
	drawRoundedRect(e.vg, x + headSize + spacing + spacing - 28, y + height - spacing * 2 - 3, (width - 20) * healthAnimation, 4, rgbaToColor(23, 85, 243, 255), 2);
	stopScale(e.vg);
}