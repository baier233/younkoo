#include "HUD.h"
#include "base/render/hooks/WndProcHook.hpp"
#include "base/GitInfo.h"
#include <utils/Wstr.h>
#include "../ModuleManager.h"
#include <base/render/gui/GUI.h>

#include "utils/TimerUtil.hpp"

#define ANIMATION_DURATION 0.2f // Animation duration in seconds
class MousePositionEstimator
{
public:
	MousePositionEstimator(int screenWidth, int screenHeight, float mouseSensitivity)
		: screenWidth(screenWidth), screenHeight(screenHeight), mouseSensitivity(mouseSensitivity)
	{
		// 初始鼠标位置假设在屏幕中心
		mouseX = screenWidth / 2.0f;
		mouseY = screenHeight / 2.0f;
	}

	void update(float currentYaw, float currentPitch, float previousYaw, float previousPitch)
	{
		// 计算 yaw 和 pitch 的变化量
		float deltaYaw = currentYaw - previousYaw;
		float deltaPitch = currentPitch - previousPitch;

		// 计算鼠标的相对移动量
		float deltaMouseX = deltaYaw / mouseSensitivity;
		float deltaMouseY = deltaPitch / mouseSensitivity;

		// 更新鼠标位置
		mouseX += deltaMouseX;
		mouseY -= deltaMouseY; // 注意：屏幕坐标系通常是 y 轴向下为正

		// 确保鼠标位置在屏幕范围内
		mouseX = std::max(0.0f, std::min(static_cast<float>(screenWidth), mouseX));
		mouseY = std::max(0.0f, std::min(static_cast<float>(screenHeight), mouseY));
	}

	void printMousePosition() const
	{
		LOG("Estimated mouse position: (" << mouseX << ", " << mouseY << ")");
	}

private:
	int screenWidth;
	int screenHeight;
	float mouseSensitivity;
	float mouseX;
	float mouseY;
};


HUD::HUD() : AbstractModule(xorstr_("HUD"), Category::VISUAL, xorstr_("HUD."), 'K')
{
	REGISTER_EVENT(EventRender2D, HUD::onRender);
	//ModuleManager::get().registrations.push_back(Younkoo::get().EventBus->register_handler<EventRender2D>(this, &HUD::onRender));
	this->addValue(BoolType, blurValue);
	this->setToggle(true);
}


HUD& HUD::getInstance()
{
	static HUD instance = HUD();
	return instance;
}

void HUD::onEnable()
{
}

void HUD::onDisable()
{
}

#include <base/render/Renderer.hpp>

#include <wrapper/net/minecraft/client/Minecraft.h>

static bool inGui = false;
static float anglesX = 0, anglesY = 0;

void HUD::onUpdate()
{
	ToggleCheck;

	if (NanoGui::available)
	{
		inGui = true;
		return;
	}
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.isInGuiState())
	{
		inGui = true;
		return;
	}
	inGui = false;
}

static void drawEyes(NVGcontext* vg, float x, float y, float w, float h, float mx, float my, float t)
{
	NVGpaint gloss, bg;
	float ex = w * 0.23f;
	float ey = h * 0.5f;
	float lx = x + ex;
	float ly = y + ey;
	float rx = x + w - ex;
	float ry = y + ey;
	float dx, dy, d;
	float br = (ex < ey ? ex : ey) * 0.5f;
	float blink = 1 - pow(sinf(t * 0.5f), 200) * 0.8f;

	bg = nvgLinearGradient(vg, x, y + h * 0.5f, x + w * 0.1f, y + h, nvgRGBA(0, 0, 0, 32), nvgRGBA(0, 0, 0, 16));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx + 3.0f, ly + 16.0f, ex, ey);
	nvgEllipse(vg, rx + 3.0f, ry + 16.0f, ex, ey);
	nvgFillPaint(vg, bg);
	nvgFill(vg);

	bg = nvgLinearGradient(vg, x, y + h * 0.25f, x + w * 0.1f, y + h, nvgRGBA(220, 220, 220, 255),
		nvgRGBA(128, 128, 128, 255));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx, ly, ex, ey);
	nvgEllipse(vg, rx, ry, ex, ey);
	nvgFillPaint(vg, bg);
	nvgFill(vg);

	dx = (mx - rx) / (ex * 10);
	dy = (my - ry) / (ey * 10);
	d = sqrtf(dx * dx + dy * dy);
	if (d > 1.0f)
	{
		dx /= d;
		dy /= d;
	}
	dx *= ex * 0.4f;
	dy *= ey * 0.5f;
	nvgBeginPath(vg);
	nvgEllipse(vg, lx + dx, ly + dy + ey * 0.25f * (1 - blink), br, br * blink);
	nvgFillColor(vg, nvgRGBA(32, 32, 32, 255));
	nvgFill(vg);

	dx = (mx - rx) / (ex * 10);
	dy = (my - ry) / (ey * 10);
	d = sqrtf(dx * dx + dy * dy);
	if (d > 1.0f)
	{
		dx /= d;
		dy /= d;
	}
	dx *= ex * 0.4f;
	dy *= ey * 0.5f;
	nvgBeginPath(vg);
	nvgEllipse(vg, rx + dx, ry + dy + ey * 0.25f * (1 - blink), br, br * blink);
	nvgFillColor(vg, nvgRGBA(32, 32, 32, 255));
	nvgFill(vg);

	gloss = nvgRadialGradient(vg, lx - ex * 0.25f, ly - ey * 0.5f, ex * 0.1f, ex * 0.75f, nvgRGBA(255, 255, 255, 128),
		nvgRGBA(255, 255, 255, 0));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx, ly, ex, ey);
	nvgFillPaint(vg, gloss);
	nvgFill(vg);

	gloss = nvgRadialGradient(vg, rx - ex * 0.25f, ry - ey * 0.5f, ex * 0.1f, ex * 0.75f, nvgRGBA(255, 255, 255, 128),
		nvgRGBA(255, 255, 255, 0));
	nvgBeginPath(vg);
	nvgEllipse(vg, rx, ry, ex, ey);
	nvgFillPaint(vg, gloss);
	nvgFill(vg);
}

/* TODO: 需要被更好的Rainbow替换，现在只是用来View的 */
static std::array<float, 3> rainbow(const long long nanoseconds, const long long offset = 0)
{
	constexpr double frequency = 1e-9;
	const double time = static_cast<double>(nanoseconds + offset) * frequency;
	const float red = static_cast<float>(std::sin(time + 0)) * 0.5f + 0.5f;
	const float green = static_cast<float>(std::sin(time + 2 * 3.14159265358979323846 / 3)) * 0.5f + 0.5f;
	const float blue = static_cast<float>(std::sin(time + 4 * 3.14159265358979323846 / 3)) * 0.5f + 0.5f;
	return { 255 * red, 255 * green, 255 * blue };
}
static std::array<float, 3> lightBlueToWhiteGradient(const long long nanoseconds, const long long offset = 0)
{
	constexpr double frequency = 1e-9;
	const double time = static_cast<double>(nanoseconds + offset) * frequency;

	const float t = (std::sin(time) + 1.0f) / 2.0f; // t 在 0 到 1 之间变化

	// 浅蓝色到白色的插值
	const float red = 173 + t * (255 - 173);   // 从 173 到 255
	const float green = 216 + t * (255 - 216); // 从 216 到 255
	const float blue = 230 + t * (255 - 230);   // 从 230 到 255

	return { red, green, blue };
}

#include <utils/Wstr.h>

std::string getCurrentTimeFormatted() {
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::tm* timeinfo = std::localtime(&currentTime);
	std::ostringstream oss;
	oss << std::put_time(timeinfo, "%I:%M%p");
	return oss.str();
}
#include <base/GitInfo.h>
void HUD::onRender(const EventRender2D& e)
{
	using namespace NanoVGHelper;
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.getPlayer().isNULL()) return;
	static int last_fps = 0;
	static std::string last_watermark_text;
	static std::pair<float, float> last_watermark_bounds;

	int current_fps = mc.getPlayer().isNULL() ? 0 : mc.getFps();
	if (current_fps != last_fps) {
		last_fps = current_fps;
		last_watermark_text = "younkoo | " + std::to_string(current_fps) + "FPS | " + getCurrentTimeFormatted();
		last_watermark_bounds = NanoVGHelper::nvgTextBoundsStr(e.vg, last_watermark_text, fontHarmony, 18);
	}

	drawRect(e.vg, 3, 4, last_watermark_bounds.first + 15, 3, NanoVGHelper::rgbaToColor(225, 225, 225, 255));
	drawRect(e.vg, 3, 5, last_watermark_bounds.first + 15, last_watermark_bounds.second + 12, NanoVGHelper::rgbaToColor(0, 0, 0, 128));
	nvgTextStr(e.vg, last_watermark_text, 10, 12, fontHarmony, 18, nvgRGBA(255, 255, 255, 255));

	static const auto& handle_window = Renderer::get().renderContext.HandleWindow;
	static const auto& dpi = Renderer::get().renderContext.devicePixelRatio;

	const float time = static_cast<float>(glfwGetTime());
	const float eye_x = e.winWidth - 150 / dpi;
	const float eye_y = 10;
	const float eye_width = 150 / dpi;
	const float eye_height = 100 / dpi;

	if (inGui)
	{
		POINT cursor_pos;
		GetCursorPos(&cursor_pos);
		ScreenToClient(handle_window, &cursor_pos);
		if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1 or SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
			drawEyes(e.vg, eye_x, eye_y, eye_width, eye_height, static_cast<float>(cursor_pos.x), static_cast<float>(cursor_pos.y), time);
	}
	else
	{
		if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1 or SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
			drawEyes(e.vg, eye_x, eye_y, eye_width, eye_height, 0, 0, time);
		{

			static auto commitTime = std::string(GIT_COMMIT_TIME) + " " + std::string(GIT_COMMIT_HASH);
			static auto [width, height] = nvgTextBoundsStr(e.vg, commitTime, NanoVGHelper::fontHarmony, 20);
			NanoVGHelper::drawRect(e.vg, e.winWidth - width - 3.0f, e.winHeight - height, width + 7.f, height + 10.f, rgbaToColor(0, 0, 0, 100));
			nvgTextStr(e.vg, commitTime, e.winWidth - width - 1.0f, e.winHeight - height, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255));
		}

	}

	constexpr float moduleList_FontSize = 18;
	const auto& modules = ModuleManager::get().getMods();
	//std::vector<std::pair<std::string, std::pair<float, float>>> name_properties;
	std::vector<std::pair<AbstractModule*, std::pair<std::string, std::pair<float, float>>>> modInfoWithBounds;


	auto currentTime = std::chrono::steady_clock::now();

	for (auto iter = modules.cbegin(); iter < modules.cend(); iter++) {
		auto sbmod = reinterpret_cast<AbstractModule*>(*iter);
		if (sbmod) {
			bool isVisible = sbmod->getToggle();
			auto& animState = moduleAnimStates[sbmod];

			if (animState.isVisible != isVisible) {
				animState.isVisible = isVisible;
				animState.lastUpdateTime = currentTime;
			}

			float elapsedTime = std::chrono::duration<float>(currentTime - animState.lastUpdateTime).count();
			float targetProgress = isVisible ? 1.0f : 0.0f;
			float animationSpeed = 1.0f / ANIMATION_DURATION;

			if (isVisible) {
				animState.animationProgress = std::min(animState.animationProgress + elapsedTime * animationSpeed, 1.0f);
			}
			else {
				animState.animationProgress = std::max(animState.animationProgress - elapsedTime * animationSpeed, 0.0f);
			}

			animState.lastUpdateTime = currentTime;

			if (animState.animationProgress > 0.0f) {
				auto sbname = sbmod->getName();
				auto bounds = nvgTextBoundsStr(e.vg, sbname, NanoVGHelper::fontHarmony, 18);
				modInfoWithBounds.push_back({ sbmod, {sbname, bounds} });
			}
		}
	}
	std::sort(modInfoWithBounds.begin(), modInfoWithBounds.end(), [](const auto& a, const auto& b) {
		return a.second.second.first > b.second.second.first;
		});


	float totalHeight = 0;
	for (const auto& mod : modInfoWithBounds) {
		totalHeight += mod.second.second.second + 8.0f;
	}

	float start_y = 40;
	const auto now = std::chrono::high_resolution_clock::now();
	const auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();

	for (const auto& mod : modInfoWithBounds)
	{
		const auto& module_name = mod.first->getName();
		const auto& bounds = mod.second.second;
		const auto& [name_width, name_height] = bounds;
		const auto& animState = moduleAnimStates[mod.first];

		float alpha = animState.animationProgress * 255;
		float xOffset = (1.0f - animState.animationProgress) * (bounds.first + 10);

		constexpr float render_x = 5.f;
		const float render_y = start_y + 6.0F;

		NanoVGHelper::drawRect(e.vg, 3 - xOffset, start_y, name_width + 7.f, name_height + 8.0f, rgbaToColor(0, 0, 0, static_cast<int>(100 * animState.animationProgress)));
		//NanoVGHelper::drawRect(e.vg, 5 - xOffset, start_y, bounds.first + 15, bounds.second + 8.0f, NanoVGHelper::rgbaToColor(0, 0, 0, static_cast<int>(100 * animState.animationProgress)));
		//drawRect(e.vg, 0, start_y, 3, name_height + 12.0F, rgbaToColor(red, green, blue, 255));
		//nvgTextStr(e.vg, module_name, 5 + 5 - xOffset, start_y + (8.0f / 2.0f), NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, static_cast<unsigned char>(alpha)));

		nvgTextStr(e.vg, module_name, render_x + 1.0F - xOffset, render_y + 1.0F, fontHarmony, moduleList_FontSize, nvgRGBA(255, 255, 255, static_cast<unsigned char>(alpha)));
		if (blurValue->getValue())
		{
			if (animState.animationProgress > 0.0f) {

				nvgFontBlur(e.vg, 10);
				nvgTextStr(e.vg, module_name, render_x - xOffset, render_y, fontHarmony, moduleList_FontSize, nvgRGBA(255, 255, 255, 255));
				nvgFontBlur(e.vg, 0);
			}
		}
		//nvgTextStr(e.vg, module_name, render_x, render_y, fontHarmony, moduleList_FontSize, nvgRGBA(255, 255, 255, 255));

		//	start_y += name_height + 12.0F;
		start_y += (bounds.second + 8.0f) * animState.animationProgress;

	}
}
