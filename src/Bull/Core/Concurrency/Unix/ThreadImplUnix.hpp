#ifndef BULL_CORE_CONCURRENCY_UNIX_THREADIMPLUNIX_HPP
#define BULL_CORE_CONCURRENCY_UNIX_THREADIMPLUNIX_HPP

#include <pthread.h>

#include <Bull/Core/Concurrency/ThreadImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ThreadImplUnix : public ThreadImpl
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
             * \return Return always nullptr
             *
             */
            static void* entryPoint(void* data);

        public:

            /*! \brief Contructor
             *
             * \param function The function to run
             * \param priority The priority of the thread (by default inherit form the parent thread)
             *
             */
            ThreadImplUnix(std::function<void()>& function, ThreadPriority priority);

            /*! \brief Wait the end of a thread
             *
             */
            void wait() override;

            /*! \brief Tell whether the Thread is still running
             *
             * \return True if the Thread is running
             *
             */
            bool isRunning() const override;

            /*! \brief Stop the thread
             *
             */
            void terminate() override;

        private:

            pthread_t    m_handler;
            mutable bool m_isRunning;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_UNIX_THREADIMPLUNIX_HPP

