#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/System/Win32/ProcessImplWin32.hpp>


namespace Bull
{
    namespace prv
    {
        Process::Id ProcessImplWin32::getCurrentPid()
        {
            return GetCurrentProcessId();
        }

        Process::Id ProcessImplWin32::getCurrentParentPid()
        {
            Process::Id ppid     = 0;
            PROCESSENTRY32 entry = {0};
            HANDLE handler       = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

            entry.dwSize = sizeof(PROCESSENTRY32);

            if(Process32First(handler, &entry))
            {
                do
                {
                    if(entry.th32ProcessID == getCurrentPid())
                    {
                        ppid = entry.th32ParentProcessID;
                        break;
                    }
                } while(Process32Next(handler, &entry));
            }
            CloseHandle(handler);

            return ppid;
        }

        ProcessImplWin32::ProcessImplWin32(const String &commandLine, const Path &workingDirectory, const std::vector<String> &args)
        {

        }

        Process::Id ProcessImplWin32::getPid() const
        {
            return 0;
        }

        Process::Status ProcessImplWin32::getStatus() const
        {
            return Process::Ready;
        }

        Process::ExitCode ProcessImplWin32::getExitCode(bool block) const
        {
            return Process::Ok;
        }
    }
}