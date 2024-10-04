#include "pch.h"
#include "Utilities.h"
#include <cstdint>

namespace Utility {
    double GetGLFWTime() {
        return glfwGetTime();
    }

    std::string GetTime(const char *format) {
        std::chrono::time_point<std::chrono::system_clock> now_time = std::chrono::system_clock::now();
        time_t t_time = std::chrono::system_clock::to_time_t(now_time);
        tm tm = *gmtime(&t_time);
        std::stringstream time_stream;
        time_stream << std::put_time(&tm, format);
        return time_stream.str();
    }

    long long GetMillsTime() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        std::chrono::milliseconds ns = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());

        return ns.count();
    }
    long long GetNanoTime() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());

        return ns.count();
    }
    void Timer::Reset(){
        this->lastMS = GetMillsTime();
    }

    bool Timer::HasTimeElapsed(long long time, long long reset) {
        if (GetMillsTime() - lastMS > time) {
            if (reset) this->Reset();
            return true;
        }
        return false;
    }

    bool Timer::HasTimeElapsed(long long time){
        return GetMillsTime() - lastMS > time;
    }
    bool Timer::HasTimeElapsed(double time){
        return HasTimeElapsed((long long)time);
    }
    bool Timer::HasTimeElapsed(int time) {
        return HasTimeElapsed((long long)time);
    }
    long long Timer::GetTime(){
        return GetMillsTime() - lastMS;
    }

    void Timer::SetTime(long long time)
    {
        this->lastMS = time;
    }

}

