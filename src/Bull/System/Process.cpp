#include <Bull/System/Process.hpp>
#include <Bull/System/ProcessImpl.hpp>

namespace Bull
{
    Process::Id Process::getPid()
    {
        return prv::ProcessImpl::getPid();
    }

    Process::Id Process::getParentPid()
    {
        return prv::ProcessImpl::getParentPid();
    }
}
