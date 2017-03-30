#include <sys/unistd.h>

#include <Bull/Hardware/Unix/CPUImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get the number of CPU
         *
         * \return Return the number of CPU
         *
         */
        unsigned int CPUImpl::getCount()
        {
            return static_cast<unsigned int>(sysconf(_SC_NPROCESSORS_ONLN));
        }

        /*! \brief Get the CPU architecture
         *
         * \return Return the CPU architecture
         *
         */
        CPU::Architecture CPUImpl::getArchitecture()
        {
            return CPU::Unknown;
        }
    }
}

