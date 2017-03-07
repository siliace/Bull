#include <Bull/Core/Thread/ConditionVariable.hpp>
#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    ConditionVariable::ConditionVariable() :
        m_impl(prv::ConditionVariableImpl::createInstance())
    {
        ///Nothing
    }

    /*! \brief Destructor
     *
     */
    ConditionVariable::~ConditionVariable()
    {
        /// Nothing
    }

    /*! \brief Send a signal to a waiting thread
     *
     */
    void ConditionVariable::signalOne()
    {
        if(m_impl)
        {
            m_impl->signalOne();
        }
    }

    /*! \brief Send a signal to all waiting thread
     *
     */
    void ConditionVariable::signalAll()
    {
        if(m_impl)
        {
            m_impl->signalAll();
        }
    }

    /*! \brief Wait for a signal
     *
     * \param mutex The mutex to lock the resource
     *
     */
    void ConditionVariable::wait(Mutex& mutex)
    {
        if(m_impl)
        {
            m_impl->wait(mutex.m_impl.get());
        }
    }

    /*! \brief Wait for a signal
     *
     * \param mutex The mutex to lock the resource
     * \param timeout The time to wait before failing
     *
     * \return Return false if timeout, else return true
     *
     */
    bool ConditionVariable::wait(Mutex& mutex, const Time& timeout)
    {
        if(m_impl)
        {
            return m_impl->wait(mutex.m_impl.get(), timeout);
        }

        return false;
    }
}
