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
            static Process::Id getCurrentPid();

            /*! \brief Get the Parent PID of the process
             *
             * \return The PPID of the process
             *
             */
            static Process::Id getCurrentParentPid();

        public:

            /*! \brief Constructor
             *
             * \param commandLine      The command line to start the process
             * \param workingDirectory The working directory of the process
             * \param args             The arguments of the process
             *
             */
            ProcessImplUnix(const String& commandLine, const Path& workingDirectory, const std::vector<String>& args);

            /*! \brief Get the PID of the Process
             *
             * \return The PID
             *
             */
            Process::Id getPid() const override;

            /*! \brief Get the status of the process
             *
             * \return The status
             *
             */
            Process::Status getStatus() const override;

            /*! \brief Get the exit code of the Process
             *
             * \param block True to wait the end of the process
             *
             * \return The exit code, -1 if the Process is still running
             *
             */
            Process::ExitCode getExitCode(bool block) const override;

        private:

            /*! \brief Fork the current process
             *
             * \return The PID of the fork
             *
             */
            int makeFork();

            /*! \brief Execute a new process
             *
             * \param commandLine The command line to start the process
             * \param args        The arguments of the process
             *
             */
            void makeExec(const String& commandLine, const std::vector<String>& args);

            int m_pid;
        };
    }
}

#endif // BULL_SYSTEM_UNIX_PROCESSIMPLUNIX_HPP
