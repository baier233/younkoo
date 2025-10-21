#pragma once
#include <chrono>

class TimerUtil {

private:
    std::chrono::steady_clock::time_point lastMS = std::chrono::steady_clock::now();

public:
    void reset() {
        lastMS = std::chrono::steady_clock::now();
    }

    bool hasTimeElapsed(std::chrono::milliseconds time, bool reset) {
        std::chrono::steady_clock::time_point timerNow = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(timerNow - lastMS) > time) {
            if (reset) this->reset();
            return true;
        }
        return false;
    }

    template <typename T>
    bool hasTimeElapsed(T time, bool reset) {
        std::chrono::milliseconds duration(time);
        return hasTimeElapsed(duration, reset);
    }
};
