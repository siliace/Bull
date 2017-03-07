#include <Bull/Core/System/Config.hpp>

#include <windows.h>

#include <Bull/Hardware/Win32/RAMImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Retrieves the amount of RAM that is physically installed on the computer
         *
         * \return Return the amount of RAM
         *
         */
        Uint64 RAMImpl::getSystemMemory()
        {
            MEMORYSTATUSEX memStatus;
            ZeroMemory(&memStatus, sizeof(MEMORYSTATUSEX));
            memStatus.dwLength = sizeof(MEMORYSTATUSEX);

            if(!GlobalMemoryStatusEx(&memStatus))
            {
                return 0;
            }

            return memStatus.ullTotalPhys;
        }
    }
}
