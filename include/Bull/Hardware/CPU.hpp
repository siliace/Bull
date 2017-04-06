#ifndef Bull_CPU_hpp
#define Bull_CPU_hpp

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    struct BULL_API CPU
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

#endif // Bull_CPU_hpp
