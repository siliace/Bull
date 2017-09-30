#ifndef BULL_SYSTEM_CPU_HPP
#define BULL_SYSTEM_CPU_HPP

#include <Bull/System/Export.hpp>

namespace Bull
{
    struct BULL_SYSTEM_API CPU
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

#endif // BULL_SYSTEM_CPU_HPP
