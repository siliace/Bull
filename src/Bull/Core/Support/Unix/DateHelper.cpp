#include <ctime>

#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        DateTime systemTimeToDate(struct tm* sysDate)
        {
            return DateTime::make(
                    Date::make(1900 + sysDate->tm_year, DateMonth(sysDate->tm_mon), sysDate->tm_mday),
                    Time::make(sysDate->tm_hour, sysDate->tm_min, sysDate->tm_sec)
            );
        }
    }
}