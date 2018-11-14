#ifndef BULL_CORE_HARDWARE_WIN32_RAM_HPP
#define BULL_CORE_HARDWARE_WIN32_RAM_HPP

#include <Bull/Core/Prerequisites.hpp>

namespace Bull
{
    namespace prv
    {
        class RAMImpl
        {
        public:

            /*! \brief Retrieves the amount of RAM that is physically installed on the computer
             *
             * \return Return the amount of RAM
             *
             */
            static Uint64 getSystemMemory();
        };
    }
}

#endif // BULL_CORE_HARDWARE_WIN32_RAM_HPP
