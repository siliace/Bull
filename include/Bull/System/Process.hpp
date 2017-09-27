#ifndef BULL_SYSTEM_PROCESS_HPP
#define BULL_SYSTEM_PROCESS_HPP

#include <memory>

#include <Bull/Core/FileSystem/FileSystem.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/System/Export.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImpl;
    }

    class BULL_SYSTEM_API Process : public NonCopyable
    {
    public:

        typedef int Id;

        /*! \brief Get the PID of the current process
         *
         * \return The PID of the process
         *
         */
        static Id getPid();

        /*! \brief Get the Parent PID of the process
         *
         * \return The PPID of the process
         *
         */
        static Id getParentPid();
    };
}

#endif // BULL_SYSTEM_PROCESS_HPP
