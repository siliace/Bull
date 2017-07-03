#include <Bull/Core/Thread/Win32/MutexImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        MutexImplWin32::MutexImplWin32()
        {
            InitializeCriticalSection(&m_handler);
        }

        MutexImplWin32::~MutexImplWin32()
        {
            DeleteCriticalSection(&m_handler);
        }

        bool MutexImplWin32::tryLock()
        {
            return TryEnterCriticalSection(&m_handler) == TRUE;
        }

        void MutexImplWin32::lock()
        {
            EnterCriticalSection(&m_handler);
        }

        void MutexImplWin32::unlock()
        {
            LeaveCriticalSection(&m_handler);
        }

        MutexHandler* MutexImplWin32::getHandler()
        {
            return &m_handler;
        }
    }
}
