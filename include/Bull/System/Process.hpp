#ifndef BULL_SYSTEM_PROCESS_HPP
#define BULL_SYSTEM_PROCESS_HPP

#include <memory>
#include <vector>

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

        enum Status
        {
            Ready,
            Running,
            Terminated
        };

        enum ExitCode
        {
            None         = -1,
            Ok           = 0,
            GeneralError = 1,
        };

        /*! \brief Get the PID of the current process
         *
         * \return The PID of the process
         *
         */
        static Id getCurrentPid();

        /*! \brief Get the Parent PID of the process
         *
         * \return The PPID of the process
         *
         */
        static Id getCurrentParentPid();

    public:

        /*! \brief Constructor
         *
         * \param commandLine
         * \param workingDirectory
         *
         */
        explicit Process(const String& commandLine, const Path& workingDirectory = FileSystem::getCurrentDirectory());

        /*! \brief Destructor
         *
         */
        ~Process();

        /*! \brief Start the Process
         *
         * \return True if the Process was started successfully
         *
         */
        bool start();

        /*! \brief Tell whether the Process is running
         *
         * \return True if the Process is running
         *
         */
        bool isRunning() const;

        /*! \brief Stop the process
         *
         */
        void stop();

        /*! \brief Get the command line of the process
         *
         * \return The command line
         *
         */
        const String& getCommandLine() const;

        /*! \brief Get the working directory of the process
         *
         * \return The working directory
         *
         */
        const Path& getWorkingDirectory() const;

        /*! \brief Get the PID of the Process
         *
         * \return The PID
         *
         */
        Id getPid() const;

        /*! \brief Get the status of the Process
         *
         * \return The status
         *
         */
        Status getStatus() const;

        /*! \brief Get the exit code of the Process
         *
         * \param block True to wait the end of the process
         *
         * \return The exit code, -1 if the Process is still running
         *
         */
        ExitCode getExitCode(bool block = false) const;

    private:

        std::unique_ptr<prv::ProcessImpl> m_impl;
        std::vector<String>               m_arguments;
        String                            m_commandLine;
        Path                              m_workingDirectory;
    };
}

#endif // BULL_SYSTEM_PROCESS_HPP
