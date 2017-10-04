#ifndef BULL_CORE_CPU_HPP
#define BULL_CORE_CPU_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API CPU
    {
        enum Architecture
        {
            x64,
            ARM,
            IA64,
            Intel,
            Unknown
        };

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
        static Architecture getArchitecture();
    };
}

#endif // BULL_CORE_CPU_HPP
