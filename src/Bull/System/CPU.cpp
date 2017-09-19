#include <Bull/System/CPU.hpp>
#include <Bull/System/CPUImpl.hpp>

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
