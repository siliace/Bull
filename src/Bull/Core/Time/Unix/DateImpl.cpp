#include <ctime>

#include <Bull/Core/Time/Unix/DateImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Date DateImpl::now()
        {
            time_t now;
            struct tm* sysDate;

            time(&now);
            sysDate = localtime(&now);

            return Date::make(1900 + sysDate->tm_year, DateMonth(sysDate->tm_mon), sysDate->tm_mday);
        }
    }
}
