#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Hardware/Win32/CPUImpl.hpp>

namespace Bull
{
    namespace prv
    {
        unsigned int CPUImpl::getCount()
        {
            SYSTEM_INFO info;
            GetSystemInfo(&info);

            return info.dwNumberOfProcessors;
        }

        CPUArchitecture CPUImpl::getArchitecture()
        {
            SYSTEM_INFO info;
            GetSystemInfo(&info);

            switch(info.wProcessorArchitecture)
            {
                case PROCESSOR_ARCHITECTURE_AMD64:
                    return CPUArchitecture_x64;
                case PROCESSOR_ARCHITECTURE_ARM:
                    return CPUArchitecture_ARM;
                case PROCESSOR_ARCHITECTURE_IA64:
                    return CPUArchitecture_IA64;
                case PROCESSOR_ARCHITECTURE_INTEL:
                    return CPUArchitecture_Intel;
            }

            return CPUArchitecture_Unknown;
        }
    }
}

