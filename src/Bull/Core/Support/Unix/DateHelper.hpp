#ifndef BULL_CORE_SUPPORT_UNIX_DATEHELPER_HPP
#define BULL_CORE_SUPPORT_UNIX_DATEHELPER_HPP

#include <unistd.h>

#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        DateTime systemTimeToDate(struct tm* sysDate);
    }
}

#endif // BULL_CORE_SUPPORT_UNIX_DATEHELPER_HPP
