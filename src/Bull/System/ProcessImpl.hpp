#ifndef BULL_SYSTEM_PROCESSIMPL_HPP
#define BULL_SYSTEM_PROCESSIMPL_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/System/Process.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImpl : public NonCopyable
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

#endif // BULL_SYSTEM_PROCESSIMPL_HPP
