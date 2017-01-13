#include <sys/time.h>

#include <Bull/Core/Thread/Unix/SemaphoreImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        SemaphoreImplUnix::SemaphoreImplUnix(unsigned int count)
        {
            sem_init(&m_handler, 0, count);
        }

        SemaphoreImplUnix::~SemaphoreImplUnix()
        {
            sem_destroy(&m_handler);
        }

        void SemaphoreImplUnix::wait()
        {
            sem_wait(&m_handler);
        }

        bool SemaphoreImplUnix::wait(const Time& timeout)
        {
            struct timeval tv;
            struct timespec ts;

            gettimeofday(&tv, nullptr);
            ts.tv_sec = time(nullptr) + static_cast<int>(timeout.asMilliseconds()) / 1000;
            ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (static_cast<int>(timeout.asMilliseconds()) % 1000);
            ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
            ts.tv_nsec %= (1000 * 1000 * 1000);

            return sem_timedwait(&m_handler, &ts) != -1;
        }

        unsigned int SemaphoreImplUnix::getCount() const
        {
            int count;
            sem_getvalue(const_cast<sem_t*>(&m_handler), &count);

            return count;
        }

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
