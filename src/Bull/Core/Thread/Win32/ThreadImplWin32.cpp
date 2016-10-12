#include <Bull/Core/Thread/Win32/ThreadImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Asleep the current thread
         *
         * \param time The time to sleep
         *
         */
        void ThreadImplWin32::sleep(const Time& time)
        {
            Sleep(time.asMilliseconds());
        }

        /*! \brief Entry point for every Win32 threads
         *
         * \param data User data
         *
         * \return Return always 0
         *
         */
        DWORD WINAPI ThreadImplWin32::entryPoint(void* data)
        {
            Functor<void>* function = static_cast<Functor<void>*>(data);

            function->run();

            return 0;
        }

        /*! \brief Constructor
         *
         * \param function The function to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
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

        /*! \brief Wait the end of a thread
         *
         */
        void ThreadImplWin32::wait()
        {
            if(GetCurrentThread() != m_handler)
            {
                WaitForSingleObject(m_handler, INFINITE);
            }
        }

        /*! \brief Stop the thread
         *
         */
        void ThreadImplWin32::stop()
        {
            CloseHandle(m_handler);
        }

        /*! \brief Get the system handler
         *
         * \return Return the native system thread handler
         *
         */
        ThreadHandler ThreadImplWin32::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
