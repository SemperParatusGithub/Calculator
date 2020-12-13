#pragma once
#include <sstream>
#include <string>
#include <time.h>
#include <chrono>


namespace Util
{
    static std::chrono::time_point<std::chrono::high_resolution_clock> s_StartPoint;
    static const char *s_Name;

    class Time
    {
    public:
        static inline void StartSession(const char *name)
        {
            s_StartPoint = std::chrono::high_resolution_clock::now();
            s_Name = name;
        }
        static inline void EndSession()
        {
            auto elapsed = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() - 
                std::chrono::time_point_cast<std::chrono::microseconds>(s_StartPoint).time_since_epoch().count();
        
            std::cout << "Session " << s_Name << " took " << elapsed / 1000.0f << "ms" << std::endl;
        }

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