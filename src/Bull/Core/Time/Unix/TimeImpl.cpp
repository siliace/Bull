#include <ctime>

#include <Bull/Core/Time/Unix/TimeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time TimeImpl::now()
        {
            time_t now;
            struct tm* sysDate;

            time(&now);
            sysDate = localtime(&now);

            return Time::make(sysDate->tm_hour, sysDate->tm_min, sysDate->tm_sec);
        }
    }
}
