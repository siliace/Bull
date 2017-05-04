#ifndef BULL_RAM_HPP
#define BULL_RAM_HPP

#include <Bull/Core/System/Integer.hpp>

#include <Bull/Hardware/Export.hpp>

namespace Bull
{
    struct BULL_HARDWARE_API RAM
    {
        /*! \brief Retrieves the amount of RAM that is physically installed on the computer
         *
         * \return Return the amount of RAM
         *
         */
        static Uint64 getSystemMemory();
    };
}

#endif // BULL_RAM_HPP
