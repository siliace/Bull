#include <Bull/Hardware/RAM.hpp>
#include <Bull/Hardware/RAMImpl.hpp>

namespace Bull
{
    Uint64 RAM::getSystemMemory()
    {
        return prv::RAMImpl::getSystemMemory();
    }
}
