#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Thread/ThreadImpl.hpp>

namespace Bull
{
    void Thread::sleep(const Time& time)
    {
        prv::ThreadImpl::sleep(time);
    }

    Thread::Thread() :
        m_priority(ThreadPriority_Inherit)
    {
        /// Nothing
    }

    Thread::Thread(const Callable& callable, ThreadPriority priority) :
        m_function(callable),
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
        if(!isRunning() && m_function)
        {
            m_impl = prv::ThreadImpl::createInstance(m_function, m_priority);

            return true;
        }

        return false;
    }

    bool Thread::isRunning() const
    {
        return m_impl;
    }

    void Thread::wait()
    {
        if(m_impl)
        {
            m_impl.reset();
        }
    }

    ThreadPriority Thread::getPriority() const
    {
        return m_priority;
    }
}
