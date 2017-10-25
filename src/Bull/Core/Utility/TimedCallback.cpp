#include <Bull/Core/Utility/TimedCallback.hpp>

namespace Bull
{
    void TimedCallback::loop(const Functor<void>& functor, const Time& timeout)
    {
        while(true)
        {
            Thread::sleep(timeout);
            functor();
        }
    }

    TimedCallback::TimedCallback(const Functor<void>& functor, const Time& timeout) :
        m_worker(&TimedCallback::loop, functor, timeout)
    {
        m_worker.start();
    }

    TimedCallback::~TimedCallback()
    {
        m_worker.stop();
    }
}