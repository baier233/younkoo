#pragma once

#include <cmath>
#include <wrapper/net/minecraft/client/Minecraft.h>

namespace MathHelper {


	inline float clamp_float(float num, float min, float max)
	{
		return num < min ? min : (num > max ? max : num);
	}
	inline double roundToHalf(double d) {
		return std::round(d * 2) / 2.0;
	}

	inline double deltaTime() {
		return Wrapper::Minecraft::getMinecraft().getFps() > 0 ? (1.0000 / Wrapper::Minecraft::getMinecraft().getFps()) : 1;
	}

	inline float fast(float end, float start, float multiple) {
		return (1 - clamp_float((float)(deltaTime() * multiple), 0, 1)) * end
			+ clamp_float((float)(deltaTime() * multiple), 0, 1) * start;
	}
}