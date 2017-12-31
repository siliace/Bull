#include <ctime>

#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        Date systemTimeToDate(struct tm* sysDate)
        {
            Date date;

            date.second    = Duration(sysDate->tm_sec);
            date.minute    = sysDate->tm_min;
            date.hour      = sysDate->tm_hour;
            date.day       = sysDate->tm_mday;
            date.dayOfWeek = DateDay(sysDate->tm_wday);
            date.month     = DateMonth(sysDate->tm_mon);
            date.year      = 1900 + sysDate->tm_year;

            return date;
        }
    }
}