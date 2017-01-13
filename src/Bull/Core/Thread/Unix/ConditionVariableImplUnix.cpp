#include <sys/time.h>

#include <Bull/Core/Thread/Unix/ConditionVariableImplUnix.hpp>
#include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        ConditionVariableImplUnix::ConditionVariableImplUnix()
        {
            pthread_cond_init(&m_handler, nullptr);
        }

        ConditionVariableImplUnix::~ConditionVariableImplUnix()
        {
            pthread_cond_destroy(&m_handler);
        }

        void ConditionVariableImplUnix::signalOne()
        {
            pthread_cond_signal(&m_handler);
        }

        void ConditionVariableImplUnix::signalAll()
        {
            pthread_cond_broadcast(&m_handler);
        }

        void ConditionVariableImplUnix::wait(MutexImpl* mutex)
        {
            pthread_cond_wait(&m_handler, static_cast<MutexImplUnix*>(mutex)->getHandlerPointer());
        }

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
