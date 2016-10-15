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
            m_mutex.lock();
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
