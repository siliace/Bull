#include <Bull/Core/System/Config.hpp>
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
        /*! \brief Create a OS specific instance of ConditionVariableImpl
         *
         * \return Return the created instance
         *
         */
        ConditionVariableImpl* ConditionVariableImpl::createInstance()
        {
            return new ConditionVariableType();
        }

        /*! \brief Destructor
         *
         */
        ConditionVariableImpl::~ConditionVariableImpl()
        {
            /// Nothing
        }
    }
}
