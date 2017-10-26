#include <Bull/Core/Hardware/CPU.hpp>
#include <Bull/Core/Hardware/CPUImpl.hpp>

namespace Bull
{
    unsigned int CPU::getCount()
    {
        return prv::CPUImpl::getCount();
    }

    CPUArchitecture CPU::getArchitecture()
    {
        return prv::CPUImpl::getArchitecture();
    }
}
