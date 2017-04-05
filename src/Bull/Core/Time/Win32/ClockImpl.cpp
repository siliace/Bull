#include <windows.h>

#include <Bull/Core/Time/Win32/ClockImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time ClockImpl::uptime()
        {
            return Time::milliseconds(GetTickCount());
        }
    }
}
