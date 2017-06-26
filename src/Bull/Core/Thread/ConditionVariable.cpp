#include <Bull/Core/Thread/ConditionVariable.hpp>
#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

namespace Bull
{
    ConditionVariable::ConditionVariable() :
        m_impl(prv::ConditionVariableImpl::createInstance())
    {
        ///Nothing
    }

    ConditionVariable::~ConditionVariable()
    {
        /// Nothing
    }

    void ConditionVariable::signalOne()
    {
        if(m_impl)
        {
            m_impl->signalOne();
        }
    }

    void ConditionVariable::signalAll()
    {
        if(m_impl)
        {
            m_impl->signalAll();
        }
    }

    void ConditionVariable::wait(Mutex& mutex)
    {
        if(m_impl)
        {
            m_impl->wait(mutex.m_impl);
        }
    }

    bool ConditionVariable::wait(Mutex& mutex, const Time& timeout)
    {
        if(m_impl)
        {
            return m_impl->wait(mutex.m_impl, timeout);
        }

        return false;
    }
}
