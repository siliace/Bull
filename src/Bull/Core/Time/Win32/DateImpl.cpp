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
            now.month     = DateMonth(lt.wMonth);
            now.dayOfWeek = DateDay(lt.wDayOfWeek);
            now.day       = static_cast<Uint8>(lt.wDay);
            now.hour      = static_cast<Uint8>(lt.wHour);
            now.minute    = static_cast<Uint8>(lt.wMinute);
            now.second    = Duration::seconds(lt.wSecond) + Duration::milliseconds(lt.wMilliseconds);

            return now;
        }
    }
}
