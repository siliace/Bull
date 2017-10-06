#ifndef BULL_CORE_HARDWARE_RAM_HPP
#define BULL_CORE_HARDWARE_RAM_HPP

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API RAM
    {
        /*! \brief Retrieves the amount of RAM that is physically installed on the computer
         *
         * \return Return the amount of RAM
         *
         */
        static Uint64 getSystemMemory();
    };
}

#endif // BULL_CORE_HARDWARE_RAM_HPP
