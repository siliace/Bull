#include <time.h>

#include <Bull/Core/Time/Unix/ClockImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time ClockImpl::uptime()
        {
            timespec time;

            clock_gettime(CLOCK_MONOTONIC, &time);

            return Time::microseconds(static_cast<float>(time.tv_sec) * 1000000 + time.tv_nsec / 1000);
        }
    }
}
