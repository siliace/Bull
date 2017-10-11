#include <Bull/Core/Process/ProcessImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Process/Win32/ProcessImplWin32.hpp>
    typedef Bull::prv::ProcessImplWin32 ProcessImplType;
#else
    #include <Bull/Core/Process/Unix/ProcessImplUnix.hpp>
    typedef Bull::prv::ProcessImplUnix ProcessImplType;
#endif

namespace Bull
{
    namespace prv
    {
        Process::Id ProcessImpl::getCurrentPid()
        {
            return ProcessImplType::getCurrentPid();
        }

        Process::Id ProcessImpl::getCurrentParentPid()
        {
            return ProcessImplType::getCurrentParentPid();
        }

        ProcessImpl* ProcessImpl::createInstance(const String& commandLine, const Path& workingDirectory, const std::vector<String>& args)
        {
            return new ProcessImplType(commandLine, workingDirectory, args);
        }
    }
}