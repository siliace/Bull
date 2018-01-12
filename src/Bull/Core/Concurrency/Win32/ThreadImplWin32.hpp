#ifndef BULL_CORE_CONCURRENCY_WIN32_THREADIMPLWIN32_HPP
#define BULL_CORE_CONCURRENCY_WIN32_THREADIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Concurrency/ThreadImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ThreadImplWin32 : public ThreadImpl
        {
        public:

            /*! \brief Asleep the current thread
             *
             * \param time The time to sleep
             *
             */
            static void sleep(const Duration& time);

        private:

            /*! \brief Entry point for every Win32 threads
             *
             * \param data User data
             *
             * \return Return always 0
             *
             */
            static DWORD WINAPI entryPoint(void* data);

        public:

            /*! \brief Constructor
             *
             * \param priority The priority of the thread (by default inherit form the parent thread)
             *
             */
            ThreadImplWin32(Runnable* runnable, ThreadPriority priority);

            /*! \brief Destructor
             *
             */
            ~ThreadImplWin32();

            bool isRunning() const override;

            void wait() override;

            void terminate() override;

        private:

            HANDLE m_handler;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_WIN32_THREADIMPLWIN32_HPP

