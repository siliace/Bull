#ifndef BULL_SYSTEM_UNIX_PROCESSIMPLUNIX_HPP
#define BULL_SYSTEM_UNIX_PROCESSIMPLUNIX_HPP

#include <unistd.h>

#include <Bull/System/ProcessImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImplUnix : public ProcessImpl
        {
        public:

            /*! \brief Get the PID of the current process
             *
             * \return The PID of the process
             *
             */
            static Process::Id getPid();

            /*! \brief Get the Parent PID of the process
             *
             * \return The PPID of the process
             *
             */
            static Process::Id getParentPid();
        };
    }
}

#endif // BULL_SYSTEM_UNIX_PROCESSIMPLUNIX_HPP
