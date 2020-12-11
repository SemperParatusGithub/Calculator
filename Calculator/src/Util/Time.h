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
            ss << hour << ":" << min << ":" << sec;

            return ss.str();
        }
    };
}