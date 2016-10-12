#include <unistd.h>

#include <Bull/Core/Thread/Unix/ThreadImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Asleep the current thread
         *
         * \param time The time to sleep
         *
         */
        void ThreadImplUnix::sleep(const Time& time)
        {
            usleep(time.asMicroseconds());
        }

        /*! \brief Entry point for every Win32 threads
         *
         * \param data User data
         *
         * \return Return always nullptr
         *
         */
        void* ThreadImplUnix::entryPoint(void* data)
        {
            Functor<void>* function = static_cast<Functor<void>*>(data);

            function->run();

            return nullptr;
        }

        /*! \brief Contructor
         *
         * \param function The function to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
        ThreadImplUnix::ThreadImplUnix(Functor<void>& function, Thread::Priority priority)
        {
            pthread_create(&m_handler,
                           nullptr,
                           &ThreadImplUnix::entryPoint,
                           &function);
        }

        /*! \brief Wait the end of a thread
         *
         */
        void ThreadImplUnix::wait()
        {
            if(pthread_self() != m_handler)
            {
                pthread_join(m_handler, nullptr);
            }
        }

        /*! \brief Stop the thread
         *
         */
        void ThreadImplUnix::stop()
        {
            pthread_detach(m_handler);
        }

        /*! \brief Get the system handler
         *
         * \return Return the native system thread handler
         *
         */
        ThreadHandler ThreadImplUnix::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
