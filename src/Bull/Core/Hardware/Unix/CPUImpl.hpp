#ifndef BULL_CORE_HARDWARE_CPU_HPP
#define BULL_CORE_HARDWARE_CPU_HPP

#include <Bull/Core/Hardware/CPU.hpp>

namespace Bull
{
    namespace prv
    {
        struct CPUImpl
        {
            /*! \brief Get the number of CPU
             *
             * \return Return the number of CPU
             *
             */
            static unsigned int getCount();

            /*! \brief Get the CPU architecture
             *
             * \return Return the CPU architecture
             *
             */
            static CPU::Architecture getArchitecture();
        };
    }
}

#endif // BULL_CORE_HARDWARE_CPU_HPP

