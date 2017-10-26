#ifndef BULL_CORE_HARDWARE_WIN32_CPUIMPL_HPP
#define BULL_CORE_HARDWARE_WIN32_CPUIMPL_HPP

#include <Bull/Core/Hardware/CPUArchitecture.hpp>

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
            static CPUArchitecture getArchitecture();
        };
    }
}

#endif // BULL_CORE_HARDWARE_WIN32_CPUIMPL_HPP

