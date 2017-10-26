#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Process/Win32/ProcessImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        ProcessImplWin32::ProcessImplWin32(const CommandLine& commandLine)
        {
            String buffer;
            StringStream ss;

            for(const String& option : commandLine.getOptions(true))
            {
                ss << " " << option;
            }

            buffer = ss.toString();
            buffer.ensureOwnership();

            CreateProcess(commandLine.getProgram().getBuffer(),
                          &buffer[0],
                          nullptr,
                          nullptr,
                          FALSE,
                          NORMAL_PRIORITY_CLASS,
                          nullptr,
                          nullptr,
                          &m_startupinfo,
                          &m_processInformation);
        }

        ProcessState ProcessImplWin32::wait()
        {
            WaitForSingleObject(m_processInformation.hProcess, INFINITE);
            CloseHandle(m_processInformation.hProcess);
            CloseHandle(m_processInformation.hThread);

            return ProcessState_Terminated;
        }

        ProcessState ProcessImplWin32::wait(const Time& timeout)
        {
            WaitForSingleObject(m_processInformation.hProcess, static_cast<DWORD>(timeout.asMilliseconds()));
            CloseHandle(m_processInformation.hProcess);
            CloseHandle(m_processInformation.hThread);

            return ProcessState_Terminated;
        }

        Process::Id ProcessImplWin32::getId() const
        {
            return m_processInformation.dwProcessId;
        }
    }
}