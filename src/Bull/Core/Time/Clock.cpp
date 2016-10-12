#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Time/ClockImpl.hpp>

namespace Bull
{
    /*! \brief Get the uptime
     *
     * \return Return the update
     *
     */
    Time Clock::uptime()
    {
        return prv::ClockImpl::uptime();
    }

    /*! \brief Default constructor
     *
     */
    Clock::Clock() :
        m_start(0.f),
        m_pause(0.f),
        m_totalPause(0.f),
        m_isRunning(false)
    {
        /// Nothing
    }

    /*!\brief == operator override
     *
     * \param right The clock to test
     *
     * \return Return true if this and right are equal, false otherwise
     *
     */
    bool Clock::operator==(const Clock& right) const
    {
        return (m_start == right.m_start) && (m_pause == right.m_pause) && (m_totalPause == right.m_totalPause);
    }

    /*!\brief != operator override
     *
     * \param right The clock to test
     *
     * \return Return true if this and right are not equal, false otherwise
     *
     */
    bool Clock::operator!=(const Clock& right) const
    {
        return !((*this) == right);
    }

    /*! \brief Start the clock
     *
     */
    void Clock::start()
    {
        if(!isRunning())
        {
            m_start     = Clock::uptime();
            m_isRunning = true;
        }
    }

    /*! \brief Stop the clock
     *
     */
    void Clock::pause()
    {
        if(isRunning())
        {
            m_pause     = Clock::uptime();
            m_isRunning = false;
        }
    }

    /*! \brief Resume the clock
     *
     */
    void Clock::resume()
    {
        if(!isRunning() && m_start != Time::seconds(0.f))
        {
            m_totalPause += Clock::uptime() - m_pause;

            m_pause     = Time::seconds(0.f);
            m_isRunning = true;
        }
    }

    /*! \brief Get the elapsed time since the clock is started
     *
     * \return Return the time since the clock is started
     *
     */
    Time Clock::getElapsedTime() const
    {
        if(isRunning())
        {
            return Clock::uptime() - m_start - m_totalPause;
        }

        return m_pause - m_start - m_totalPause;
    }

    /*! \brief Get the state of the clock
     *
     * \return Return true if the clock is running, else otherwise
     *
     */
    bool Clock::isRunning() const
    {
        return m_isRunning;
    }

    /*! \brief Restart the clock
     *
     * \return Return the time since the clock is started before restart
     *
     */
    Time Clock::restart()
    {
        Time elapsed = getElapsedTime();

        m_start      = Clock::uptime();
        m_pause      = Time::seconds(0.f);
        m_totalPause = Time::seconds(0.f);
        m_isRunning  = true;

        return elapsed;
    }
}
