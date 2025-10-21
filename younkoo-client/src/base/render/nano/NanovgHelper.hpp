﻿#pragma once
#include <Windows.h>
#undef min
#undef max
class NVGcontext;
#include <nanovg.h>
#include <string>
#include<array>
#include <vector>
#include <memory>
#include <list>

#include <GL/glew.h>

enum class GradientDirection {
	DOWN,
	UP,
	LEFT,
	RIGHT,
	DIAGONAL_DOWN,
	DIAGONAL_UP
};


class Scissor {
public:
	float x;
	float y;
	float width;
	float height;

	// Constructor
	Scissor(float x, float y, float width, float height) :
		x(x), y(y), width(width), height(height) { }

	// Copy constructor
	Scissor(const Scissor& scissor) :
		x(scissor.x), y(scissor.y), width(scissor.width), height(scissor.height) { }

	// Function to check if a point is in the Scissor
	inline bool isInScissor(float x, float y) {
		return x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height;
	}
};

namespace MaskHelper {
	inline void defineMask() {
		glDepthMask(GL_TRUE);
		glClearDepth(1);
		glClear(GL_DEPTH_BUFFER_BIT);
		glDepthFunc(GL_ALWAYS);
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	}

	inline void finishDefineMask() {
		glDepthMask(GL_FALSE);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	}

	inline void drawOnMask() {
		glDepthFunc(GL_EQUAL);
	}

	inline void drawOffMask() {
		glDepthFunc(GL_NOTEQUAL);
	}

	inline void resetMask() {
		glDepthMask(GL_TRUE);
		glClearDepth(0);
		glClear(GL_DEPTH_BUFFER_BIT);
		glDepthMask(GL_FALSE);
		glDisable(GL_DEPTH_TEST);
	}
}

class ScissorHelperImpl {
	std::list<std::vector<std::shared_ptr<Scissor>>> previousScissors;
	std::vector<std::shared_ptr<Scissor>> scissors;

public:
	inline std::shared_ptr<Scissor> scissor(NVGcontext* vg, float x, float y, float width, float height) {
		auto scissor = std::make_shared<Scissor>(x, y, width, height);
		if (std::find(scissors.begin(), scissors.end(), scissor) != scissors.end()) return scissor;
		scissors.push_back(scissor);
		applyScissors(vg);
		return scissor;
	}

	inline void resetScissor(NVGcontext* vg, std::shared_ptr<Scissor> scissor) {
		auto it = std::find(scissors.begin(), scissors.end(), scissor);
		if (it != scissors.end()) {
			scissors.erase(it);
			applyScissors(vg);
		}
	}

	inline void clearScissors(NVGcontext* vg) {
		scissors.clear();
		nvgResetScissor(vg);
	}

	inline void save() {
		previousScissors.push_back(scissors);
	}

	inline void restore(NVGcontext* vg) {
		scissors = previousScissors.front();
		previousScissors.pop_front();
		applyScissors(vg);
	}

private:
	inline void applyScissors(NVGcontext* vg) {
		nvgResetScissor(vg);
		if (scissors.size() == 0) return;
		std::shared_ptr<Scissor> finalScissor = getFinalScissor(scissors);
		nvgScissor(vg, finalScissor->x, finalScissor->y, finalScissor->width, finalScissor->height);
	}

	inline std::shared_ptr<Scissor> getFinalScissor(const std::vector<std::shared_ptr<Scissor>>& scissors) {
		auto finalScissor = Scissor(*scissors.at(0).get());
		for (int i = 1; i < scissors.size(); i++) {
			auto scissor = scissors.at(i);
			float rightX = std::min(scissor->x + scissor->width, finalScissor.x + finalScissor.width);
			float rightY = std::min(scissor->y + scissor->height, finalScissor.y + finalScissor.height);
			finalScissor.x = std::max(finalScissor.x, scissor->x);
			finalScissor.y = std::max(finalScissor.y, scissor->y);
			finalScissor.width = rightX - finalScissor.x;
			finalScissor.height = rightY - finalScissor.y;
		}
		return std::make_shared<Scissor>(finalScissor);
	}
};








namespace NanoVGHelper {
	void LoadFonts();
	bool InitContext(HWND window2Attach);
	bool DeleteContext();
	inline NVGcontext* Context{};
	inline int rgbaToColor(int r, int g, int b, int a) {
		return ((a & 0xFF) << 24) |
			((r & 0xFF) << 16) |
			((g & 0xFF) << 8) |
			((b & 0xFF) << 0);
	}

	inline NVGcolor colorToRGBA(int color) {
		NVGcolor nvgColor{};
		nvgColor.a = ((color >> 24) & 0xFF);
		nvgColor.r = ((color >> 16) & 0xFF);
		nvgColor.g = ((color >> 8) & 0xFF);
		nvgColor.b = ((color >> 0) & 0xFF);
		return nvgColor;
	}

	inline NVGcolor colorToRGB(int color) {
		NVGcolor nvgColor{};
		nvgColor.r = ((color >> 16) & 0xFF) / 255;
		nvgColor.g = ((color >> 8) & 0xFF) / 255;
		nvgColor.b = ((color >> 0) & 0xFF) / 255;
		nvgColor.a = 0XFF / 255;
		return nvgColor;
	}

	inline int nvgColorToRGB(NVGcolor color) {
		return ((static_cast<int>(color.a * 255) & 0xFF) << 24) |
			((static_cast<int>(color.r * 255) & 0xFF) << 16) |
			((static_cast<int>(color.g * 255) & 0xFF) << 8) |
			((static_cast<int>(color.b * 255) & 0xFF) << 0);
	}

	inline NVGcolor colorToRGB255(int color) {
		NVGcolor nvgColor{};
		nvgColor.r = ((color >> 16) & 0xFF);
		nvgColor.g = ((color >> 8) & 0xFF);
		nvgColor.b = ((color >> 0) & 0xFF);
		nvgColor.a = 0XFF / 255;
		return nvgColor;
	}

	void renderGlow(NVGcontext* vg, float x, float y, float width, float height, float radius, float offset, int color);

	inline void renderShadow(NVGcontext* vg, float x, float y, float width, float height, float radius, int shadowRadius) {
		int alpha = 1;

		for (float i = shadowRadius; i > 0.0F; --i) {
			renderGlow(vg, x - i / 2.0F, y - i / 2.0F, width + i, height + i, radius + 2.0F, i, rgbaToColor(0, 0, 0, alpha));
			alpha += 2;
		}
	}



	void drawOutlineRect(NVGcontext* vg, float x, float y, float width, float height, int outlineWidth, int color);
	void drawRoundedOutlineRect(NVGcontext* vg, float x, float y, float width, float height, float radius, int outlineWidth, int color);
	void drawRoundedOutlineRect1(NVGcontext* vg, float x, float y, float width, float height, float radius, int outlineWidth, int color);
	void drawRect(NVGcontext* vg, float x, float y, float width, float height, int color);
	void drawHollowRoundRect(NVGcontext* vg, float x, float y, float width, float height, int color, float radius, float thickness);
	void drawRoundedRectVaried(NVGcontext* vg, float x, float y, float width, float height, int color, float radiusTL, float radiusTR, float radiusBR, float radiusBL);
	void drawGradientRoundedRect(NVGcontext* vg, float x, float y, float width, float height, int color, int color2, float radius, GradientDirection direction);
	void nvgTextW(NVGcontext* vg, const std::wstring& str, float x, float y, int font, int size, NVGcolor col, int alight = NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	void nvgTextU8(NVGcontext* vg, const std::u8string& str, float x, float y, int font, int size, NVGcolor col, int alight = NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	void nvgTextStr(NVGcontext* vg, const std::string& str, float x, float y, int font, int size, NVGcolor col, int alight = NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	void nvgRect(NVGcontext* vg, float x, float y, float width, float height, NVGcolor col);
	std::pair<float, float> nvgTextBoundsW(NVGcontext* vg, const std::wstring& str, int font, int size);
	std::pair<float, float> nvgTextBoundsStr(NVGcontext* vg, const std::string& str, int font, int size);
	void nvgTextBoundsW(NVGcontext* vg, int x, int y, const  std::wstring& str, float bounds[]);
	void nvgTextBoundsStr(NVGcontext* vg, int x, int y, const  std::string& str, float bounds[]);
	void drawRoundedRect(NVGcontext* vg, float x, float y, float width, float height, int color, float radius);
	void drawLine(NVGcontext* vg, float x, float y, float endX, float endY, float width, int color);
	inline void scale(NVGcontext* vg, float x, float y) {
		nvgScale(vg, x, y);
	}
	inline void push(NVGcontext* vg = Context) {
		nvgSave(vg);
	}

	inline void pop(NVGcontext* vg = Context) {
		nvgRestore(vg);
	}

	inline void alpha(NVGcontext* vg, float alpha) {
		nvgGlobalAlpha(vg, alpha);
	}

	inline void startScale(NVGcontext* vg, float x, float y, float scale) {
		push();
		nvgTranslate(vg, x, y);
		nvgScale(vg, scale, scale);
		nvgTranslate(vg, -x, -y);
	}

	inline void stopScale(NVGcontext* vg = Context) {
		pop(vg);
	}

	inline void fillNVGColorWithRGBA(float r, float g, float b, float a, NVGcolor& color) {
		color = nvgRGBAf(r, g, b, a);
	}

	void drawDropShadow(NVGcontext* vg, float x, float y, float w, float h, float blur, float spread, float cornerRadius);
	NVGcolor nvgFillColorEx(NVGcontext* vg, int color);
	void drawHollowEllipse(NVGcontext* vg, float x, float y, float radiusX, float radiusY, int color, float thickness);
	void drawEllipse(NVGcontext* vg, float x, float y, float radiusX, float radiusY, int color);
	void drawCircle(NVGcontext* vg, float x, float y, float radius, int color);
	void drawHSBBox(NVGcontext* vg, float x, float y, float width, float height, int colorTarget);

	inline std::array<float, 4> getValues(float x, float y, float width, float height, GradientDirection direction) {
		switch (direction) {
		default:
		case GradientDirection::DOWN:
			return std::array<float, 4>{x, y, x, y + height};

		case GradientDirection::UP:
			return std::array<float, 4>{x, y + height, x, y};

		case GradientDirection::LEFT:
			return std::array<float, 4>{x + width, y, x, y};

		case GradientDirection::RIGHT:
			return std::array<float, 4>{x, y, x + width, y};

		case GradientDirection::DIAGONAL_DOWN:
			return std::array<float, 4>{x, y, x + width, y + height};

		case GradientDirection::DIAGONAL_UP:
			return std::array<float, 4>{x, y + height, x + width, y};
		}
	}
	inline void startRotate(NVGcontext* vg, float x, float y, float rotate) {
		push();
		nvgTranslate(vg, x, y);
		nvgRotate(vg, rotate);
		nvgTranslate(vg, -x, -y);
	}
	inline void stopRotate() {
		pop();
	}
	inline int watermark = 0;
	inline int fontHarmony{};
	inline int fontHarmonyBold{};
	inline int fontGreycliffCFLight{};
	inline int fontMaterialIcon{};
	inline ScissorHelperImpl scissorHelper;
}

