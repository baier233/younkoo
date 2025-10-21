#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <iostream>
#include <cmath>
#include <functional>
#include <chrono>

class Easing {
public:
	using EasingFunction = std::function<double(double)>;



	inline static EasingFunction EASE_IN_Expo() {
		return [](double x) { return x == 0 ? 0 : std::pow(2, 10 * x - 10); };
	}

	inline static EasingFunction EASE_OUT_Expo() {
		return [](double x) { return x == 1 ? 1 : 1 - std::pow(2, -10 * x); };
	}

	inline static EasingFunction EASE_IN_OUT_Expo() {
		return [](double x) { return x ==  0
			? 0
			: x == 1
			? 1
			: x < 0.5 ? std::pow(2, 20 * x - 10) / 2
			: (2 - std::pow(2, -20 * x + 10)) / 2; };
	}


	inline static EasingFunction EASE_IN_QUAD() {
		return [](double x) { return std::pow(x, 2); };
	}

	inline static EasingFunction EASE_OUT_QUAD() {
		return [](double x) { return 1 - std::pow(1 - x, 2); };
	}

	inline static EasingFunction EASE_IN_OUT_QUAD() {
		return [](double x) { return x < 0.5 ? 2 * std::pow(x, 2) : 1 - std::pow(-2 * x + 2, 2) / 2; };
	}
	inline static EasingFunction EASE_IN_CUBIC() {
		return [](double x) { return std::pow(x, 3); };
	}

	inline static EasingFunction EASE_OUT_CUBIC() {
		return [](double x) { return 1 - std::pow(1 - x, 3); };
	}

	inline static EasingFunction EASE_IN_OUT_CUBIC() {
		return [](double x) { return x < 0.5 ? 4 * std::pow(x, 3) : 1 - std::pow(-2 * x + 2, 3) / 2; };
	}

	inline static EasingFunction EASE_IN_QUART() {
		return [](double x) { return std::pow(x, 4); };
	}

	inline static EasingFunction EASE_OUT_QUART() {
		return [](double x) { return 1 - std::pow(1 - x, 4); };
	}

	inline static EasingFunction EASE_IN_OUT_QUART() {
		return [](double x) { return x < 0.5 ? 8 * std::pow(x, 4) : 1 - std::pow(-2 * x + 2, 4) / 2; };
	}

	inline static EasingFunction EASE_IN_QUINT() {
		return [](double x) { return std::pow(x, 5); };
	}

	inline static EasingFunction EASE_OUT_QUINT() {
		return [](double x) { return 1 - std::pow(1 - x, 5); };
	}

	inline static EasingFunction EASE_IN_OUT_QUINT() {
		return [](double x) { return x < 0.5 ? 16 * std::pow(x, 5) : 1 - std::pow(-2 * x + 2, 5) / 2; };
	}

	inline static EasingFunction EASE_IN_CRIC() {
		return [](double x) { return 1 - std::sqrt(1 - std::pow(x, 2)); };
	}

	inline static EasingFunction EASE_OUT_CRIC() {
		return [](double x) { return std::sqrt(1 - std::pow(x - 1, 2)); };
	}

	inline static EasingFunction EASE_IN_OUT_CRIC() {
		return [](double x) {
			return x < 0.5 ? (1 - std::sqrt(1 - std::pow(2 * x, 2))) / 2 : (std::sqrt(1 - std::pow(-2 * x + 2, 2)) + 1) / 2;
			};
	}

	inline static EasingFunction EASE_IN_BACK() {
		return [](double x) {
			double inertia = 1.5;
			return (1 + inertia) * std::pow(x, 3) - inertia * std::pow(x, 2);
			};
	}

	inline static EasingFunction EASE_OUT_BACK() {
		return [](double x) {
			double inertia = 1.5;
			return 1 + (1 + inertia) * std::pow(x - 1, 3) + inertia * std::pow(x - 1, 2);
			};
	}

	inline static EasingFunction EASE_IN_OUT_BACK() {
		return [](double x) {
			double inertia = 1.5;
			return x < 0.5 ? (std::pow(2 * x, 2) * (((inertia * 1.5) + 1) * 2 * x - (inertia * 1.5))) / 2 :
				(std::pow(2 * x - 2, 2) * (((inertia * 1.5) + 1) * (x * 2 - 2) + (inertia * 1.5)) + 2) / 2;
			};
	}
};

class AnimationObject {
private:
	long duration;
	Easing::EasingFunction easing;

	float current = 0.0f;
	float target = 0.0f;
	float startValue = 0.0f;

	std::chrono::steady_clock::time_point startMillis;
	bool finished = true;

public:
	inline AnimationObject(long duration, Easing::EasingFunction easing)
		: duration(duration), easing(easing) {}

	inline void setTarget(float targetValue) {
		if (targetValue != target) {
			startMillis = std::chrono::steady_clock::now();
			startValue = current;
			finished = false;
			target = targetValue;
		}
	}

	inline void calculate() {
		auto now = std::chrono::steady_clock::now();
		long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - startMillis).count();
		finished = elapsed >= duration;

		if (finished) {
			current = target;
			return;
		}

		double progress = static_cast<double>(elapsed) / duration;
		current = current > target
			? startValue - (startValue - target) * easing(progress)
			: startValue + (target - startValue) * easing(progress);
	}

	inline void initialize(float value) {
		current = value;
		target = value;
		finished = true;
		startValue = value;
		startMillis = std::chrono::steady_clock::now();
	}

	inline float getProgress() const {
		auto now = std::chrono::steady_clock::now();
		long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - startMillis).count();
		return std::min(static_cast<float>(elapsed) / duration, 1.0f);
	}

	inline long getDuration() const { return duration; }
	inline void setDuration(long newDuration) { duration = newDuration; }

	inline Easing::EasingFunction getEasing() const { return easing; }

	inline bool isFinished() const { return finished; }
	inline void setFinished(bool isFinished) { finished = isFinished; }
	inline void setEasing(Easing::EasingFunction newEasing) { easing = newEasing; }

	inline float getCurrent() const { return current; }
	inline float getTarget() const { return target; }

	inline void reset() {
		startValue = current = target = 0.0f;
		startMillis = std::chrono::steady_clock::now();
		finished = true;
	}

	inline void reset(float value) {
		startValue = current = target = value;
		startMillis = std::chrono::steady_clock::now();
		finished = true;
	}
};
