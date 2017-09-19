#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Win32/DateImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Date DateImpl::now()
        {
            Date now;
            SYSTEMTIME lt = {0};

            GetLocalTime(&lt);

            now.year      = lt.wYear;
            now.month     = Date::Month(lt.wMonth);
            now.day       = lt.wDay;
            now.dayOfWeek = Date::Day(lt.wDayOfWeek);
            now.hour      = lt.wHour;
            now.minute    = lt.wMinute;
            now.second    = Time::seconds(lt.wSecond) + Time::milliseconds(lt.wMilliseconds);

            return now;
        }
    }
}
