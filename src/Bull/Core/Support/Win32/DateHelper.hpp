#ifndef BULL_CORE_SUPPORT_DATEHELPER_HPP
#define BULL_CORE_SUPPORT_DATEHELPER_HPP

#include <windows.h>

#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        Date systemTimeToDate(SYSTEMTIME sysTime);
    }
}

#endif // BULL_CORE_SUPPORT_DATEHELPER_HPP
