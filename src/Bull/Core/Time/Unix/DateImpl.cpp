#include <ctime>

#include <Bull/Core/Time/Unix/DateImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Date DateImpl::now()
        {
            Date   now;
            time_t row;
            struct tm* sysDate;

            time(&row);
            sysDate = localtime(&row);

            now.second    = Time(sysDate->tm_sec);
            now.minute    = sysDate->tm_min;
            now.hour      = sysDate->tm_hour;
            now.day       = sysDate->tm_mday;
            now.dayOfWeek = DateDay(sysDate->tm_wday);
            now.month     = DateMonth(sysDate->tm_mon);
            now.year      = 1900 + sysDate->tm_year;

            return now;
        }
    }
}
