#include <Bull/Core/Hardware/RAM.hpp>
#include <Bull/Core/Hardware/RAMImpl.hpp>

namespace Bull
{
    Uint64 RAM::getSystemMemory()
    {
        return prv::RAMImpl::getSystemMemory();
    }
}
