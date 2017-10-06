#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Hardware/Win32/RAMImpl.hpp>

namespace Bull
{
    namespace prv
    {
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
