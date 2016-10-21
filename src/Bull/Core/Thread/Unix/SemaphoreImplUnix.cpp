#include <sys/time.h>

#include <Bull/Core/Thread/Unix/SemaphoreImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param count The initial count to set the semaphore
         *
         */
        SemaphoreImplUnix::SemaphoreImplUnix(unsigned int count)
        {
            sem_init(&m_handler, 0, count);
        }

        /*! \brief Destructor
         *
         */
        SemaphoreImplUnix::~SemaphoreImplUnix()
        {
            sem_destroy(&m_handler);
        }

        /*! \brief Wait until the current thread can continue
         *
         */
        void SemaphoreImplUnix::wait()
        {
            sem_wait(&m_handler);
        }

        /*! \brief Wait until the current thread can continue
         *
         * \param timeout The maximum time to wait before fail
         *
         * \return Return true if the waiting time was less than the timeout, false otherwise
         *
         */
        bool SemaphoreImplUnix::wait(const Time& timeout)
        {
            struct timeval tv;
            struct timespec ts;

            gettimeofday(&tv, nullptr);
            ts.tv_sec = time(nullptr) + static_cast<int>(timeout.asMilliseconds()) / 1000;
            ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (static_cast<int>(timeout.asMilliseconds()) % 1000);
            ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
            ts.tv_nsec %= (1000 * 1000 * 1000);


            sem_timedwait(&m_handler, &ts);
        }

        /*! \brief Get the current count of the semaphore
         *
         * \return Return the current count of the semaphore
         *
         */
        unsigned int SemaphoreImplUnix::getCount() const
        {
            int count;
            sem_getvalue(const_cast<sem_t*>(&m_handler), &count);

            return count;
        }

        /*! \brief Release semaphore's protection
         *
         */
        void SemaphoreImplUnix::release()
        {
            sem_post(&m_handler);
        }

        /*! \brief Get the system handler
         *
         * \return Return the native system semaphore handler
         *
         */
        SemaphoreHandler SemaphoreImplUnix::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
