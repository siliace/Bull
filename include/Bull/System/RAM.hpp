#ifndef BULL_RAM_HPP
#define BULL_RAM_HPP

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/System/Export.hpp>

namespace Bull
{
    struct BULL_SYSTEM_API RAM
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
