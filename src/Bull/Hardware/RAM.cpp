#include <Bull/Hardware/RAM.hpp>
#include <Bull/Hardware/RAMImpl.hpp>

namespace Bull
{
    /*! \brief Retrieves the amount of RAM that is physically installed on the computer
     *
     * \return Return the amount of RAM
     *
     */
    Uint64 RAM::getSystemMemory()
    {
        return prv::RAMImpl::getSystemMemory();
    }
}
