#include <Bull/Core/Thread/Mutex.hpp>
#include <Bull/Core/Thread/MutexImpl.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    Mutex::Mutex() :
        m_impl(prv::MutexImpl::createInstance()),
        m_locked(false)
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    Mutex::~Mutex()
    {
        m_impl.reset(nullptr);
    }

    /*! \brief Try to lock the mutex
     *
     * \return Return true if the mutex was locked successfully, else return false
     *
     */
    bool Mutex::tryLock()
    {
        if(m_impl)
        {
            m_locked = m_impl->tryLock();

            return m_locked;
        }

        return false;
    }

    /*! \brief Lock the mutex
     *
     */
    void Mutex::lock()
    {
        if(m_impl)
        {
            m_impl->lock();

            m_locked = true;
        }
    }

    /*! \brief Check whether the mutex is locked
     *
     * \return Return true if the mutex is locked, false otherwise
     *
     */
    bool Mutex::isLocked() const
    {
        return m_locked;
    }

    /*! \brief Unlock the mutex
     *
     */
    void Mutex::unlock()
    {
        if(m_impl)
        {
            m_impl->unlock();

            m_locked = false;
        }
    }
}
