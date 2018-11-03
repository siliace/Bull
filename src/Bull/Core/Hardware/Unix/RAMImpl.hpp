#ifndef BULL_CORE_HARDWARE_UNIX_RAMPIMPL_HPP
#define BULL_CORE_HARDWARE_UNIX_RAMPIMPL_HPP

#include <Bull/Core/Prerequisites.hpp>

namespace Bull
{
    namespace prv
    {
        struct RAMImpl
        {
            /*! \brief Retrieves the amount of RAM that is physically installed on the computer
             *
             * \return Return the amount of RAM
             *
             */
            static Uint64 getSystemMemory();
        };
    }
}

#endif // BULL_CORE_HARDWARE_UNIX_RAMPIMPL_HPP
