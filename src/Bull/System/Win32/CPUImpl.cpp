#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/System/Win32/CPUImpl.hpp>

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

        CPU::Architecture CPUImpl::getArchitecture()
        {
            SYSTEM_INFO info;
            GetSystemInfo(&info);

            switch(info.wProcessorArchitecture)
            {
                case PROCESSOR_ARCHITECTURE_AMD64: return CPU::x64;
                case PROCESSOR_ARCHITECTURE_ARM:   return CPU::ARM;
                case PROCESSOR_ARCHITECTURE_IA64:  return CPU::IA64;
                case PROCESSOR_ARCHITECTURE_INTEL: return CPU::Intel;
            }

            return CPU::Unknown;
        }
    }
}

