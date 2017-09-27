#include <Bull/System/ProcessImpl.hpp>

#if defined BULL_OS_WINDOWS
    #error Lack of implementation : Process
#else
    #include <Bull/System/Unix/ProcessImplUnix.hpp>
    typedef Bull::prv::ProcessImplUnix ProcessImplType;
#endif

namespace Bull
{
    namespace prv
    {
        Process::Id ProcessImpl::getPid()
        {
            return ProcessImplType::getPid();
        }

        Process::Id ProcessImpl::getParentPid()
        {
            return ProcessImplType::getParentPid();
        }
    }
}
