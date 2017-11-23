#include <Bull/Core/Thread/Win32/ThreadImplWin32.hpp>

namespace Bull
{
    namespace prv
    {

        void ThreadImplWin32::sleep(const Time& time)
        {
            Sleep(static_cast<DWORD>(time.asMilliseconds()));
        }

        DWORD WINAPI ThreadImplWin32::entryPoint(void* data)
        {
            std::function<void()>* function = static_cast<std::function<void()>*>(data);

            function->operator()();

            return 0;
        }

        ThreadImplWin32::ThreadImplWin32(std::function<void()>& function, ThreadPriority priority)
        {
            m_handler = CreateThread(nullptr,
                                     0,
                                     &ThreadImplWin32::entryPoint,
                                     &function,
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
