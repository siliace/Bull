#ifndef BULL_CORE_PROCESS_WIN32_PROCESSIMPLWIN32_HPP
#define BULL_CORE_PROCESS_WIN32_PROCESSIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Process/ProcessImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImplWin32 : public ProcessImpl
        {
        public:

            /*! \brief Constructor
             *
             * \param commandLine The CommandLine to start
             *
             */
            explicit ProcessImplWin32(const CommandLine& commandLine);

            /*! \brief Wait for the Process to stop
             *
             * \return The state of the Process
             *
             */
            ProcessState wait() override;

            /*! \brief Wait for the Process to stop
             *
             * \param timeout The time to wait before failure
             *
             * \return The state of the Process
             *
             */
            ProcessState wait(const Time& timeout) override;

            /*! \brief Get the PID of the Process
             *
             * \return The PID of the Process
             *
             */
            Process::Id getId() const override;

        private:

            STARTUPINFO         m_startupinfo;
            PROCESS_INFORMATION m_processInformation;
        };
    }
}

#endif // BULL_CORE_PROCESS_WIN32_PROCESSIMPLWIN32_HPP
