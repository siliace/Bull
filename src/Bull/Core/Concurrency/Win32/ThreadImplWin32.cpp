#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/Concurrency/Win32/ThreadImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        void ThreadImplWin32::sleep(const Duration& time)
        {
            Sleep(static_cast<DWORD>(time.asMilliseconds()));
        }

        DWORD WINAPI ThreadImplWin32::entryPoint(void* data)
        {
            Runnable* runnable = static_cast<Runnable*>(data);

            runnable->run();

            return 0;
        }

        ThreadImplWin32::ThreadImplWin32(Runnable* runnable, ThreadPriority priority)
        {
            m_handler = CreateThread(nullptr,
                                     0,
                                     &ThreadImplWin32::entryPoint,
                                     runnable,
                                     0,
                                     nullptr);

            switch(priority)
            {
                case ThreadPriority_Idle: SetThreadPriority(m_handler, THREAD_PRIORITY_IDLE); break;
                case ThreadPriority_Lowest: SetThreadPriority(m_handler, THREAD_PRIORITY_LOWEST); break;
                case ThreadPriority_Low: SetThreadPriority(m_handler, THREAD_PRIORITY_BELOW_NORMAL); break;
                case ThreadPriority_Normal: SetThreadPriority(m_handler, THREAD_PRIORITY_NORMAL); break;
                case ThreadPriority_High: SetThreadPriority(m_handler, THREAD_PRIORITY_ABOVE_NORMAL); break;
                case ThreadPriority_Highest: SetThreadPriority(m_handler, THREAD_PRIORITY_HIGHEST); break;
                case ThreadPriority_TimeCritial: SetThreadPriority(m_handler, THREAD_PRIORITY_TIME_CRITICAL); break;
                case ThreadPriority_Inherit: SetThreadPriority(m_handler, GetThreadPriority(GetCurrentThread())); break;
            }
        }

        ThreadImplWin32::~ThreadImplWin32()
        {
            if(m_handler)
            {
                CloseHandle(m_handler);
            }
        }

        bool ThreadImplWin32::isRunning() const
        {
            return WaitForSingleObject(m_handler, 0) != WAIT_OBJECT_0;
        }

        void ThreadImplWin32::wait()
        {
            if(GetCurrentThread() != m_handler)
            {
                if(WaitForSingleObject(m_handler, INFINITE) == WAIT_FAILED)
                {
                    throw RuntimeError("Failed to wait thread");
                }
            }
            else
            {
                throw RuntimeError("Failed to wait thread");
            }
        }

        void ThreadImplWin32::terminate()
        {
            if(GetCurrentThread() != m_handler)
            {
                if(!TerminateThread(m_handler, 0))
                {
                    throw RuntimeError("Failed to terminate thread");
                }
            }
            else
            {
                throw RuntimeError("Failed to terminate thread");
            }
        }
    }
}
