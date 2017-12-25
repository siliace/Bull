#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Win32/ClockImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Duration ClockImpl::uptime()
        {
            return Duration::milliseconds(GetTickCount());
        }
    }
}
