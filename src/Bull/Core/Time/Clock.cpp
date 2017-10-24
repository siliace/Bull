#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Time/ClockImpl.hpp>

namespace Bull
{
    Clock::Clock() :
        m_start(0.f),
        m_pause(0.f),
        m_totalPause(0.f),
        m_isRunning(false)
    {
        /// Nothing
    }

    bool Clock::operator==(const Clock& right) const
    {
        return m_start == right.m_start &&
               m_pause == right.m_pause &&
               m_totalPause == right.m_totalPause;
    }

    bool Clock::operator!=(const Clock& right) const
    {
        return !((*this) == right);
    }

    void Clock::start()
    {
        if(!isRunning())
        {
            m_isRunning = true;
            m_start     = prv::ClockImpl::uptime();
        }
    }

    void Clock::pause()
    {
        if(isRunning())
        {
            m_isRunning = false;
            m_pause     = prv::ClockImpl::uptime();
        }
    }

    void Clock::resume()
    {
        if(!isRunning() && m_start != Time::Zero)
        {
            m_totalPause += prv::ClockImpl::uptime() - m_pause;

            m_isRunning = true;
            m_pause     = Time::Zero;
        }
    }

    Time Clock::getElapsedTime() const
    {
        if(isRunning())
        {
            return prv::ClockImpl::uptime() - m_start - m_totalPause;
        }

        return m_pause - m_start - m_totalPause;
    }

    bool Clock::isRunning() const
    {
        return m_isRunning;
    }

    Time Clock::restart()
    {
        Time elapsed = getElapsedTime();

        m_isRunning  = true;
        m_pause      = Time::seconds(0.f);
        m_totalPause = Time::seconds(0.f);
        m_start      = prv::ClockImpl::uptime();

        return elapsed;
    }
}
