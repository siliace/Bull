#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    Time Time::Zero;

    /*! \brief Construct a Time form nanoseconds
     *
     * \param nanoseconds The number of nanoseconds
     *
     * \return Return the time
     */
    Time Time::nanoseconds(float nanoseconds)
    {
        return Time(nanoseconds / 1000000000);
    }

    /*! \brief Construct a Time form microseconds
     *
     * \param microseconds The number of microseconds
     *
     * \return Return the time
     */
    Time Time::microseconds(float microseconds)
    {
        return Time(microseconds / 1000000);
    }

    /*! \brief Construct a Time form milliseconds
     *
     * \param milliseconds The number of milliseconds
     *
     * \return Return the time
     */
    Time Time::milliseconds(float milliseconds)
    {
        return Time(milliseconds / 1000);
    }

    /*! \brief Construct a Time form seconds
     *
     * \param seconds The number of seconds
     *
     * \return Return the time
     */
    Time Time::seconds(float seconds)
    {
        return Time(seconds);
    }

    /*! \brief Construct a Time form minutes
     *
     * \param minutes The number of minutes
     *
     * \return Return the time
     */
    Time Time::minutes(float minutes)
    {
        return Time(minutes * 60);
    }

    /*! \brief Construct a Time form hours
     *
     * \param hours The number of hours
     *
     * \return Return the time
     */
    Time Time::hours(float hours)
    {
        return Time(hours * 3600);
    }

    /*! \brief Construct a Time form days
     *
     * \param days The number of days
     *
     * \return Return the time
     */
    Time Time::days(float days)
    {
        return Time(days * 86400);
    }

    /*! \brief Default constructor
     *
     */
    Time::Time() :
        m_time(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param time The number of seconds
     *
     */
    Time::Time(float time) :
        m_time(time)
    {
        /// Nothing
    }

    /*! \brief Convert a time to nanoseconds
     *
     * \return Return the time converted to nanoseconds
     *
     */
    float Time::asNanoseconds() const
    {
        return m_time * 1000000000;
    }

    /*! \brief Convert a time to microseconds
     *
     * \return Return the time converted to microseconds
     *
     */
    float Time::asMicroseconds() const
    {
        return m_time * 1000000;
    }

    /*! \brief Convert a time to milliseconds
     *
     * \return Return the time converted to milliseconds
     *
     */
    float Time::asMilliseconds() const
    {
        return m_time * 1000;
    }

    /*! \brief Convert a time to seconds
     *
     * \return Return the time converted to seconds
     *
     */
    float Time::asSeconds() const
    {
        return m_time;
    }

    /*! \brief Convert a time to minutes
     *
     * \return Return the time converted to minutes
     *
     */
    float Time::asMinutes() const
    {
        return m_time / 60;
    }

    /*! \brief Convert a time to hours
     *
     * \return Return the time converted to hours
     *
     */
    float Time::asHours() const
    {
        return m_time / 3600;
    }

    /*! \brief Convert a time to days
     *
     * \return Return the time converted to days
     *
     */
    float Time::asDays() const
    {
        return m_time / 86400;
    }

    /*! \brief Override + operator
     *
     * \param rhs The time to add
     *
     * \return Return the time added
     *
     */
    Time Time::operator+(const Time& rhs) const
    {
        Time t(m_time);

        t += rhs;

        return t;
    }

    /*! \brief Override += operator
     *
     * \param rhs The time to add
     *
     * \return Return the time added
     *
     */
    Time& Time::operator+=(const Time& rhs)
    {
        m_time += rhs.m_time;

        return (*this);
    }

    /*! \brief Override - operator
     *
     * \param rhs The time to substract
     *
     * \return Return the time substracted
     *
     */
    Time Time::operator-(const Time& rhs) const
    {
        Time t(m_time);

        t -= rhs;

        return t;
    }

    /*! \brief Override -= operator
     *
     * \param rhs The time to substract
     *
     * \return Return the time substracted
     *
     */
    Time& Time::operator-=(const Time& rhs)
    {
        m_time -= rhs.m_time;

        return (*this);
    }

    /*! \brief Override * operator
     *
     * \param rhs The time to multiply
     *
     * \return Return the time multiplied
     *
     */
    Time Time::operator*(const Time& rhs) const
    {
        Time t(m_time);

        t *= rhs;

        return t;
    }

    /*! \brief Override *= operator
     *
     * \param rhs The time to multiply
     *
     * \return Return the time multiplied
     *
     */
    Time& Time::operator*=(const Time& rhs)
    {
        m_time *= rhs.m_time;

        return (*this);
    }

    /*! \brief Override / operator
     *
     * \param rhs The time to divide
     *
     * \return Return the time divided
     *
     */
    Time Time::operator/(const Time& rhs) const
    {
        Time t(m_time);

        t /= rhs;

        return t;
    }

    /*! \brief Override /= operator
     *
     * \param rhs The time to divide
     *
     * \return Return the time divided
     *
     */
    Time& Time::operator/=(const Time& rhs)
    {
        m_time /= rhs.m_time;

        return (*this);
    }

    /*! \brief Override == operator
     *
     * \param rhs The time to compare
     *
     * \return Return true if times are equals, else return false
     *
     */
    bool Time::operator==(const Time& rhs) const
    {
        return m_time == rhs.m_time;
    }

    /*! \brief Override != operator
     *
     * \param rhs The time to compare
     *
     * \return Return false if times are equals, else return true
     *
     */
    bool Time::operator!=(const Time& rhs) const
    {
        return !((*this) == rhs);
    }

    /*! \brief Override <= operator
     *
     * \param rhs The time to compare
     *
     * \return Return true if times are inferior or equals, else return false
     *
     */
    bool Time::operator<=(const Time& rhs) const
    {
        return m_time <= rhs.m_time;
    }

    /*! \brief Override < operator
     *
     * \param rhs The time to compare
     *
     * \return Return true if times are inferior, else return false
     *
     */
    bool Time::operator<(const Time& rhs) const
    {
        return m_time < rhs.m_time;
    }

    /*! \brief Override >= operator
     *
     * \param rhs The time to compare
     *
     * \return Return true if times are superior or equals, else return false
     *
     */
    bool Time::operator>=(const Time& rhs) const
    {
        return m_time >= rhs.m_time;
    }

    /*! \brief Override > operator
     *
     * \param rhs The time to compare
     *
     * \return Return true if times are superior, else return false
     *
     */
    bool Time::operator>(const Time& rhs) const
    {
        return m_time > rhs.m_time;
    }
}
