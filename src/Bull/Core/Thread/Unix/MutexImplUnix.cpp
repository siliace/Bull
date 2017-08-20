#include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        MutexImplUnix::MutexImplUnix() :
            m_handler(PTHREAD_MUTEX_INITIALIZER)
        {
            pthread_mutexattr_t attr;
            pthread_mutexattr_init(&attr);
            pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

            pthread_mutex_init(&m_handler, &attr);
        }

        MutexImplUnix::~MutexImplUnix()
        {
            unlock();
        }

        bool MutexImplUnix::tryLock()
        {
            return pthread_mutex_trylock(&m_handler);
        }

        void MutexImplUnix::lock()
        {
            pthread_mutex_lock(&m_handler);
        }

        void MutexImplUnix::unlock()
        {
            pthread_mutex_unlock(&m_handler);
        }

        MutexHandler* MutexImplUnix::getHandler()
        {
            return &m_handler;
        }
    }
}
