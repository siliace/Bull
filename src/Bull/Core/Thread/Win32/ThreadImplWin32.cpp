#include <Bull/Core/Thread/Win32/ThreadImplWin32.hpp>

namespace Bull
{
    namespace prv
    {

        void ThreadImplWin32::sleep(const Time& time)
        {
            Sleep(time.asMilliseconds());
        }

        DWORD WINAPI ThreadImplWin32::entryPoint(void* data)
        {
            Functor<void>* function = static_cast<Functor<void>*>(data);

            function->run();

            return 0;
        }

        ThreadImplWin32::ThreadImplWin32(Functor<void>& function, Thread::Priority priority)
        {
            m_handler = CreateThread(nullptr,
                                     0,
                                     &ThreadImplWin32::entryPoint,
                                     &function,
                                     0,
                                     nullptr);

            switch(priority)
            {
            case Thread::Idle:
                SetThreadPriority(m_handler, THREAD_PRIORITY_IDLE);
                break;

            case Thread::Lowest:
                SetThreadPriority(m_handler, THREAD_PRIORITY_LOWEST);
                break;

            case Thread::Low:
                SetThreadPriority(m_handler, THREAD_PRIORITY_BELOW_NORMAL);
                break;

            case Thread::Normal:
                SetThreadPriority(m_handler, THREAD_PRIORITY_NORMAL);
                break;

            case Thread::High:
                SetThreadPriority(m_handler, THREAD_PRIORITY_ABOVE_NORMAL);
                break;

            case Thread::Highest:
                SetThreadPriority(m_handler, THREAD_PRIORITY_HIGHEST);
                break;

            case Thread::TimeCritial:
                SetThreadPriority(m_handler, THREAD_PRIORITY_TIME_CRITICAL);
                break;

            case Thread::Inherit:
                SetThreadPriority(m_handler, GetThreadPriority(GetCurrentThread()));
                break;

            default:
                SetThreadPriority(m_handler, THREAD_PRIORITY_NORMAL);
                break;
            }
        }

        void ThreadImplWin32::wait()
        {
            if(GetCurrentThread() != m_handler)
            {
                WaitForSingleObject(m_handler, INFINITE);
            }
        }

        void ThreadImplWin32::stop()
        {
            CloseHandle(m_handler);
        }
    }
}
