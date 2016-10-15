#include <sys/time.h>

#include <Bull/Core/Thread/Unix/ConditionVariableImplUnix.hpp>
#include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        ConditionVariableImplUnix::ConditionVariableImplUnix()
        {
            pthread_cond_init(&m_handler, nullptr);
        }

        /*! \brief Destructor
         *
         */
        ConditionVariableImplUnix::~ConditionVariableImplUnix()
        {
            pthread_cond_destroy(&m_handler);
        }

        /*! \brief Send a signal to a waiting thread
         *
         */
        void ConditionVariableImplUnix::signalOne()
        {
            pthread_cond_signal(&m_handler);
        }

        /*! \brief Send a signal to all waiting thread
         *
         */
        void ConditionVariableImplUnix::signalAll()
        {
            pthread_cond_broadcast(&m_handler);
        }

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to use to lock the resource
         *
         */
        void ConditionVariableImplUnix::wait(MutexImpl* mutex)
        {
            pthread_cond_wait(&m_handler, static_cast<MutexImplUnix*>(mutex)->getHandlerPointer());
        }

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to use to lock the resource
         * \param timeout The time to wait before failing
         *
         * \return Return false if timeout, false otherwise
         *
         */
        bool ConditionVariableImplUnix::wait(MutexImpl* mutex, const Time& timeout)
        {
            struct timeval tv;
            struct timespec ts;

            gettimeofday(&tv, nullptr);
            ts.tv_sec = time(nullptr) + static_cast<int>(timeout.asMilliseconds()) / 1000;
            ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (static_cast<int>(timeout.asMilliseconds()) % 1000);
            ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
            ts.tv_nsec %= (1000 * 1000 * 1000);

            return pthread_cond_timedwait(&m_handler, static_cast<MutexImplUnix*>(mutex)->getHandlerPointer(), &ts) != 0;
        }
    }
}
