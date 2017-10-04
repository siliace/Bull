#include <iostream>

#include <errno.h>
#include <wait.h>

#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/FileSystem.hpp>
#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Core/Process/Unix/ProcessImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        Process::Id ProcessImplUnix::getCurrentPid()
        {
            return getpid();
        }

        Process::Id ProcessImplUnix::getCurrentParentPid()
        {
            return getppid();
        }

        ProcessImplUnix::ProcessImplUnix(const String& commandLine, const Path& workingDirectory, const std::vector<String>& args) :
            m_pid(0)
        {
            int pid = makeFork();

            if(pid == 0)
            {
                if(!FileSystem::setCurrentDirectory(workingDirectory))
                {
                    throw RuntimeError("Failed to create process");
                }

                makeExec(commandLine, args);

                throw RuntimeError("Failed to create process"); /// Should not be reached
            }
            else
            {
                m_pid = pid;
            }
        }

        Process::Id ProcessImplUnix::getPid() const
        {
            return m_pid;
        }

        Process::Status ProcessImplUnix::getStatus() const
        {
            return (waitpid(m_pid, nullptr, WNOHANG | WUNTRACED) == m_pid) ? Process::Terminated : Process::Running;
        }

        Process::ExitCode ProcessImplUnix::getExitCode(bool block) const
        {
            int status;

            waitpid(m_pid, &status, (block) ? WUNTRACED : WNOHANG | WUNTRACED);

            if(WIFEXITED(status))
            {
                return Process::ExitCode(WEXITSTATUS(status));
            }

            return Process::ExitCode::None;
        }

        int ProcessImplUnix::makeFork()
        {
            int pid = fork();

            if(pid == -1)
            {
                throw RuntimeError("Failed to create process");
            }

            return pid;
        }

        void ProcessImplUnix::makeExec(const String& commandLine, const std::vector<String>& args)
        {
            /// Todo : find something less dirty...
            const char** ptrArgs = new const char*[args.size() + 1];

            for(Index i = 0; i < args.size(); i++)
            {
                ptrArgs[i] = args[i].getBuffer();
            }

            ptrArgs[args.size()] = nullptr;

            execvp(commandLine.getBuffer(), (char* const*)ptrArgs);
        }
    }
}