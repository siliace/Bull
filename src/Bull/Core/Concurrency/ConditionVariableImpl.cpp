#include <Bull/Core/Concurrency/ConditionVariableImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Concurrency/Win32/ConditionVariableImplWin32.hpp>
    typedef Bull::prv::ConditionVariableImplWin32 ConditionVariableType;
#else
    #include <Bull/Core/Concurrency/Unix/ConditionVariableImplUnix.hpp>
    typedef Bull::prv::ConditionVariableImplUnix ConditionVariableType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<ConditionVariableImpl> ConditionVariableImpl::createInstance()
        {
            return std::make_unique<ConditionVariableType>();
        }

        ConditionVariableImpl::~ConditionVariableImpl() = default;
    }
}
