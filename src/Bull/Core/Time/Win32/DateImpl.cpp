#include <windows.h>

#include <Bull/Core/Time/Win32/DateImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get the current date
         *
         * \return Return the current date
         *
         */
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
