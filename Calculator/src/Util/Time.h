#pragma once
#include <sstream>
#include <string>
#include <time.h>

namespace Util
{
    class Time
    {
    public:
        static inline std::string GetTimeFormated()
        {
            time_t theTime = time(nullptr);
            struct tm *aTime = localtime(&theTime);

            int hour = aTime->tm_hour;
            int min = aTime->tm_min;
            int sec = aTime->tm_sec;

            std::stringstream ss;

            ss << ((hour < 10) ? "0" : "") << hour << ":";
            ss << ((min < 10) ? "0" : "") << min << ":";
            ss << ((sec < 10) ? "0" : "") << sec;

            return ss.str();
        }
    };
}