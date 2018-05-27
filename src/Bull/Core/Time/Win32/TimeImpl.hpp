#ifndef BULL_CORE_TIME_WIN32_TIMEIMPL_HPP
#define BULL_CORE_TIME_WIN32_TIMEIMPL_HPP

#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        struct TimeImpl
        {
            static Time now();
        };
    }
}

#endif // BULL_CORE_TIME_WIN32_TIMEIMPL_HPP
