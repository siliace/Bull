#include <windows.h>

#include <Bull/Core/Time/Win32/ClockImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get the uptime
         *
         * \return Return the update
         *
         */
        Time ClockImpl::uptime()
        {
            return Time::milliseconds(GetTickCount());
        }
    }
}
