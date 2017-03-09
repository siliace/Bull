#include <Bull/Core/Thread/Win32/ConditionVariableImplWin32.hpp>
#include <Bull/Core/Thread/Win32/MutexImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        ConditionVariableImplWin32::ConditionVariableImplWin32()
        {
            InitializeConditionVariable(&m_handler);
        }

        void ConditionVariableImplWin32::signalOne()
        {
            WakeConditionVariable(&m_handler);
        }

        void ConditionVariableImplWin32::signalAll()
        {
            WakeAllConditionVariable(&m_handler);
        }

        void ConditionVariableImplWin32::wait(MutexImpl* mutex)
        {
            SleepConditionVariableCS(&m_handler, &static_cast<MutexImplWin32*>(mutex)->m_handler, INFINITE);
        }

        bool ConditionVariableImplWin32::wait(MutexImpl* mutex, const Time& timeout)
        {
            return SleepConditionVariableCS(&m_handler, &static_cast<MutexImplWin32*>(mutex)->m_handler, timeout.asMilliseconds()) != 0;
        }
    }
}
