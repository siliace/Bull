#include <Bull/System/RAM.hpp>
#include <Bull/System/RAMImpl.hpp>

namespace Bull
{
    Uint64 RAM::getSystemMemory()
    {
        return prv::RAMImpl::getSystemMemory();
    }
}
