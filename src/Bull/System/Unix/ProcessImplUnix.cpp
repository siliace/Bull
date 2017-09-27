#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/FileSystem.hpp>

#include <Bull/System/Unix/ProcessImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        Process::Id ProcessImplUnix::getPid()
        {
            return getpid();
        }

        Process::Id ProcessImplUnix::getParentPid()
        {
            return getppid();
        }
    }
}