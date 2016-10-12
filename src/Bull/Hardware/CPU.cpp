#include <Bull/Hardware/CPU.hpp>
#include <Bull/Hardware/CPUImpl.hpp>

namespace Bull
{
    /*! \brief Get the number of CPU
     *
     * \return Return the number of CPU
     *
     */
    unsigned int CPU::getCount()
    {
        return prv::CPUImpl::getCount();
    }

    /*! \brief Get the CPU architecture
     *
     * \return Return the CPU architecture
     *
     */
    CPU::Architecture CPU::getArchitecture()
    {
        return prv::CPUImpl::getArchitecture();
    }
}
