#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        DateTime systemTimeToDate(SYSTEMTIME sysTime)
        {
            return DateTime::make(
                    Date::make(sysTime.wYear, DateMonth(sysTime.wMonth),sysTime.wDay),
                    Time::make(sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds)
            );
        }
    }
}
