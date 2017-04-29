#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Thread/ThreadImpl.hpp>

namespace Bull
{
    void Thread::sleep(const Time& time)
    {
        prv::ThreadImpl::sleep(time);
    }

    Thread::Thread() :
        m_impl(nullptr),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    Thread::Thread(const Functor<void>& function, Priority priority) :
        m_impl(nullptr),
        m_function(function),
        m_priority(priority)
    {
        /// Nothing
    }

    Thread::~Thread()
    {
        wait();
    }

    bool Thread::start()
    {
        if(isRunning())
        {
            return false;
        }

        m_impl = prv::ThreadImpl::createInstance(m_function, m_priority);

        return true;
    }

    bool Thread::isRunning() const
    {
        return m_impl != nullptr;
    }

    void Thread::wait()
    {
        if(m_impl)
        {
            m_impl->wait();

            reset();
        }
    }

    void Thread::stop()
    {
        if(m_impl)
        {
            m_impl->stop();

            reset();
        }
    }

    Thread::Priority Thread::getPriority() const
    {
        return m_priority;
    }

    void Thread::reset()
    {
        delete m_impl;
        m_impl = nullptr;
    }
}
