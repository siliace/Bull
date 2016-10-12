#include <Bull/Core/Thread/Semaphore.hpp>
#include <Bull/Core/Thread/SemaphoreImpl.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param count The initial count to set the semaphore
     *
     */
    Semaphore::Semaphore(unsigned int count) :
        m_impl(prv::SemaphoreImpl::createInstance(count))
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    Semaphore::~Semaphore()
    {
        m_impl.reset();
    }

    /*! \brief Wait until the current thread can continue
     *
     */
    void Semaphore::wait()
    {
        if(m_impl)
        {
            m_impl->wait();
        }
    }

    /*! \brief Wait until the current thread can continue
     *
     * \param timeout The maximum time to wait before fail
     *
     * \return Return true if the waiting time was less than the timeout, false otherwise
     *
     */
    bool Semaphore::wait(const Time& timeout)
    {
        if(m_impl)
        {
            return m_impl->wait(timeout);
        }

        return false;
    }

    /*! \brief Get the current count of the semaphore
     *
     * \return Return the current count of the semaphore
     *
     */
    unsigned int Semaphore::getCount() const
    {
        if(m_impl)
        {
            return m_impl->getCount();
        }

        return 0;
    }

    /*! \brief Release semaphore's protection
     *
     */
    void Semaphore::release()
    {
        if(m_impl)
        {
            m_impl->release();
        }
    }

    /*! \brief Get the system handler
     *
     * \return Return the native system semaphore handler
     *
     */
    SemaphoreHandler Semaphore::getSystemHandler() const
    {
        if(m_impl)
        {
            return m_impl->getSystemHandler();
        }

        return 0;
    }
}
