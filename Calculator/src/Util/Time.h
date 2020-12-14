#pragma once
#include <sstream>
#include <string>
#include <time.h>
#include <chrono>
#include <iostream>


namespace Util
{
    class Time
    {
    public:
        static std::chrono::time_point<std::chrono::high_resolution_clock> s_StartPoint;
        static long long s_FrameCount;
        static const char *s_Name;

        static void StartSession(const char *name);
        static void EndSession();

        static std::string GetTimeFormated();
    };
}