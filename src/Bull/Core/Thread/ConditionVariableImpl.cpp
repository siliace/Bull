#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/ConditionVariableImplWin32.hpp>
    typedef Bull::prv::ConditionVariableImplWin32 ConditionVariableType;
#else
    #include <Bull/Core/Thread/Unix/ConditionVariableImplUnix.hpp>
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
