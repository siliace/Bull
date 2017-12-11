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

        void ConditionVariableImplWin32::wait(std::unique_ptr<MutexImpl>& mutex)
        {
            SleepConditionVariableCS(&m_handler, mutex->getHandler(), INFINITE);
        }

        bool ConditionVariableImplWin32::wait(std::unique_ptr<MutexImpl>& mutex, const Time& timeout)
        {
            return SleepConditionVariableCS(&m_handler, mutex->getHandler(), static_cast<DWORD>(timeout.asMilliseconds())) != 0;
        }
    }
}
