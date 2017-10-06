#ifndef BULL_CORE_PROCESSIMPL_HPP
#define BULL_CORE_PROCESSIMPL_HPP

#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Process/Process.hpp>

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
            static Process::Id getCurrentPid();

            /*! \brief Get the Parent PID of the process
             *
             * \return The PPID of the process
             *
             */
            static Process::Id getCurrentParentPid();

            /*! \brief Create an OS specific instance of ProcessImpl
             *
             * \param commandLine      The command line to start the process
             * \param workingDirectory The working directory of the process
             * \param args             The arguments of the process
             *
             * \return The created instance
             *
             */
            static ProcessImpl* createInstance(const String& commandLine, const Path& workingDirectory, const std::vector<String>& args);

        public:

            /*! \brief Get the PID of the Process
             *
             * \return The PID
             *
             */
            virtual Process::Id getPid() const = 0;

            /*! \brief Get the status of the process
             *
             * \return The status
             *
             */
            virtual Process::Status getStatus() const = 0;

            /*! \brief Get the exit code of the Process
             *
             * \param block True to wait the end of the process
             *
             * \return The exit code, -1 if the Process is still running
             *
             */
            virtual Process::ExitCode getExitCode(bool block) const = 0;
        };
    }
}

#endif // BULL_CORE_PROCESSIMPL_HPP
