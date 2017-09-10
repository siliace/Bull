#include <Bull/Core/Thread/Mutex.hpp>
#include <Bull/Core/Thread/MutexImpl.hpp>

namespace Bull
{
    Mutex::Mutex() :
        m_impl(prv::MutexImpl::createInstance()),
        m_locked(false)
    {
        /// Nothing
    }

    Mutex::~Mutex() = default;

    bool Mutex::tryLock()
    {
        if(m_impl)
        {
            m_locked = m_impl->tryLock();

            return m_locked;
        }

        return false;
    }

    void Mutex::lock()
    {
        if(m_impl)
        {
            m_impl->lock();

            m_locked = true;
        }
    }

    bool Mutex::isLocked() const
    {
        return m_locked;
    }

    void Mutex::unlock()
    {
        if(m_impl)
        {
            m_impl->unlock();

            m_locked = false;
        }
    }
}
