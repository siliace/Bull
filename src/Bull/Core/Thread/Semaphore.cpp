#include <Bull/Core/Thread/Semaphore.hpp>
#include <Bull/Core/Thread/SemaphoreImpl.hpp>

namespace Bull
{
    Semaphore::Semaphore(unsigned int count) :
        m_impl(prv::SemaphoreImpl::createInstance(count))
    {
        /// Nothing
    }

    Semaphore::~Semaphore() = default;

    void Semaphore::wait()
    {
        if(m_impl)
        {
            m_impl->wait();
        }
    }

    bool Semaphore::wait(const Time& timeout)
    {
        if(m_impl)
        {
            return m_impl->wait(timeout);
        }

        return false;
    }

    unsigned int Semaphore::getCount() const
    {
        if(m_impl)
        {
            return m_impl->getCount();
        }

        return 0;
    }

    void Semaphore::release()
    {
        if(m_impl)
        {
            m_impl->release();
        }
    }
}
