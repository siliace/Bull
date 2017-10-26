#include <Bull/Core/Configuration/OS.hpp>
#include <Bull/Core/Process/ProcessImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Process/Win32/ProcessImplWin32.hpp>
    typedef Bull::prv::ProcessImplWin32 ProcessImplType;
#else
    #error Lack of implementation : Process
#endif

namespace Bull
{
    namespace prv
    {
        ProcessImpl* ProcessImpl::createInstance(const CommandLine& commandLine)
        {
            return new ProcessImplType(commandLine);
        }
    }
}