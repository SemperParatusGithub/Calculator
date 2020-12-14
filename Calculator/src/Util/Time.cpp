#include "Time.h"


namespace Util
{
    std::chrono::time_point<std::chrono::high_resolution_clock> Time::s_StartPoint;
    long long Time::s_FrameCount = 0;
    const char *Time::s_Name;

    void Time::StartSession(const char *name)
    {
        s_StartPoint = std::chrono::high_resolution_clock::now();
        s_FrameCount = 1;
        s_Name = name;
    }

    void Time::EndSession()
    {
        auto elapsed = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(s_StartPoint).time_since_epoch().count();

        std::cout << "Session average frame took " << s_Name << " took " << elapsed / (float) s_FrameCount / 1000.0f << "ms"
            << " (Collected " << s_FrameCount << " Frames)" << std::endl;
    }

    std::string Time::GetTimeFormated()
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
}