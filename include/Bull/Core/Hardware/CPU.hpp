#ifndef BULL_CORE_HARDWARE_CPU_HPP
#define BULL_CORE_HARDWARE_CPU_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Hardware/CPUArchitecture.hpp>

namespace Bull
{
    struct BULL_CORE_API CPU
    {
        /** \brief Get the number of CPU
         *
         * \return Return the number of CPU
         *
         */
        static unsigned int getCount();

        /** \brief Get the CPU architecture
         *
         * \return Return the CPU architecture
         *
         */
        static CPUArchitecture getArchitecture();
    };
}

#endif // BULL_CORE_HARDWARE_CPU_HPP
