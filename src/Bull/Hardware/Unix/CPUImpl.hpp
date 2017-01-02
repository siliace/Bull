#ifndef Bull_CPUImpl_hpp
#define Bull_CPUImpl_hpp

#include <Bull/Hardware/CPU.hpp>

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

#endif // Bull_CPUImpl_hpp

