#include <Bull/Core/Thread/Lock.hpp>

namespace Bull
{
    Lock::Lock(Mutex& mutex) :
        m_mutex(mutex)
    {
        if(!m_mutex.isLocked())
        {
            m_mutex.lock();
        }
    }

    Lock::~Lock()
    {
        m_mutex.unlock();
    }
}
