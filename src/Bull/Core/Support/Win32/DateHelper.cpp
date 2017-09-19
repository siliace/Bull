#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        Date systemTimeToDate(SYSTEMTIME sysTime)
        {
            Date date;

            date.year      = sysTime.wYear;
            date.month     = Date::Month(sysTime.wMonth);
            date.day       = sysTime.wDay;
            date.dayOfWeek = Date::Day(sysTime.wDayOfWeek);
            date.hour      = sysTime.wHour;
            date.minute    = sysTime.wMinute;
            date.second    = Time::seconds(sysTime.wSecond) + Time::milliseconds(sysTime.wMilliseconds);

            return date;
        }
    }
}
