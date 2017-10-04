#include <sys/unistd.h>

#include <Bull/Core/Hardware/Unix/CPUImpl.hpp>

namespace Bull
{
    namespace prv
    {
        unsigned int CPUImpl::getCount()
        {
            return static_cast<unsigned int>(sysconf(_SC_NPROCESSORS_ONLN));
        }

        CPU::Architecture CPUImpl::getArchitecture()
        {
            return CPU::Unknown;
        }
    }
}

