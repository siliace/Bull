#include <Bull/Core/Concurrency/Thread.hpp>
#include <Bull/Core/Concurrency/ThreadImpl.hpp>

namespace Bull
{
    void Thread::sleep(const Duration& time)
    {
        prv::ThreadImpl::sleep(time);
    }

    Thread::Thread() :
        m_priority(ThreadPriority_Inherit)
    {
        /// Nothing
    }

    Thread::Thread(Runnable* runnable, ThreadPriority priority) :
        m_runnable(runnable),
        m_priority(priority)
    {
        /// Nothing
    }

    Thread::Thread(const Callable& callable, ThreadPriority priority) :
        Thread(new FunctionRunnable(callable), priority)
    {
        /// Nothing
    }

    Thread::~Thread()
    {
        wait();
    }

    bool Thread::start()
    {
        if(!isRunning() && m_runnable)
        {
            m_impl = prv::ThreadImpl::createInstance(m_runnable.get(), m_priority);

            return true;
        }

        return false;
    }

    bool Thread::isRunning() const
    {
        if(m_impl)
        {
            return m_impl->isRunning();
        }

        return false;
    }

    void Thread::wait()
    {
        if(m_impl)
        {
            m_impl->wait();
        }
    }

    void Thread::terminate()
    {
        if(m_impl)
        {
            m_impl->terminate();
        }
    }

    Runnable* Thread::getRunnable() const
    {
        return m_runnable.get();
    }

    ThreadPriority Thread::getPriority() const
    {
        return m_priority;
    }
}
