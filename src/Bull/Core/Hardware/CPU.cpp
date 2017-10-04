#include <Bull/Core/Hardware/CPU.hpp>
#include <Bull/Core/Hardware/CPUImpl.hpp>

namespace Bull
{
    unsigned int CPU::getCount()
    {
        return prv::CPUImpl::getCount();
    }

    CPU::Architecture CPU::getArchitecture()
    {
        return prv::CPUImpl::getArchitecture();
    }
}
