#include <Bull/Core/Thread/Lock.hpp>

namespace Bull
{
    /*! Constructor
     *
     * Lock the mutex
     *
     * \param mutex The mutex to lock
     *
     */
    Lock::Lock(Mutex& mutex) :
        m_mutex(mutex)
    {
        if(!m_mutex.isLocked())
        {
            if(!m_mutex.tryLock())
            {
                ThrowException(FailToLockMutex);
            }
        }
    }

    /*! Destructor
     *
     * Unlock the mutex
     *
     */
    Lock::~Lock()
    {
        m_mutex.unlock();
    }
}
