#include <Bull/Core/Support/Win32/Windows.hpp>
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
