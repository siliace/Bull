#include <Bull/Core/Concurrency/Thread.hpp>
#include <Bull/Core/Concurrency/ThreadImpl.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>

namespace Bull
{
    void Thread::sleep(const Duration& time)
    {
        prv::ThreadImpl::sleep(time);
    }

    void Thread::setCurrentName(const String &name)
    {
        prv::ThreadImpl::setCurrentName(name);
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

    void Thread::start()
    {
        if(isRunning())
        {
            wait();
        }

        if(!m_runnable)
        {
            Throw(InvalidParameter, "Thread::start", "The provided runnable is null");
        }

        m_impl = prv::ThreadImpl::createInstance(m_runnable.get(), m_priority);
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

    void Thread::setName(const String& name)
    {
        if(isRunning())
        {
            m_impl->setName(name);
        }
    }
}
