#ifndef BULL_CORE_SUPPORT_DATEHELPER_HPP
#define BULL_CORE_SUPPORT_DATEHELPER_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        DateTime systemTimeToDate(SYSTEMTIME sysTime);
    }
}

#endif // BULL_CORE_SUPPORT_DATEHELPER_HPP
