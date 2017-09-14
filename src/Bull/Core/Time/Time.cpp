#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    Time Time::Zero;

    Time Time::nanoseconds(float nanoseconds)
    {
        return Time(nanoseconds / 1000000000);
    }

    Time Time::microseconds(float microseconds)
    {
        return Time(microseconds / 1000000);
    }

    Time Time::milliseconds(float milliseconds)
    {
        return Time(milliseconds / 1000);
    }

    Time Time::seconds(float seconds)
    {
        return Time(seconds);
    }

    Time Time::minutes(float minutes)
    {
        return Time(minutes * 60);
    }

    Time Time::hours(float hours)
    {
        return Time(hours * 3600);
    }

    Time Time::days(float days)
    {
        return Time(days * 86400);
    }

    Time::Time() :
        m_time(0)
    {
        /// Nothing
    }

    Time::Time(float time) :
        m_time(time)
    {
        /// Nothing
    }

    float Time::asNanoseconds() const
    {
        return m_time * 1000000000;
    }

    float Time::asMicroseconds() const
    {
        return m_time * 1000000;
    }

    float Time::asMilliseconds() const
    {
        return m_time * 1000;
    }

    float Time::asSeconds() const
    {
        return m_time;
    }

    float Time::asMinutes() const
    {
        return m_time / 60;
    }

    float Time::asHours() const
    {
        return m_time / 3600;
    }

    float Time::asDays() const
    {
        return m_time / 86400;
    }

    Time Time::operator+(const Time& rhs) const
    {
        Time t(m_time);

        t += rhs;

        return t;
    }

    Time& Time::operator+=(const Time& rhs)
    {
        m_time += rhs.m_time;

        return (*this);
    }

    Time Time::operator-(const Time& rhs) const
    {
        Time t(m_time);

        t -= rhs;

        return t;
    }

    Time& Time::operator-=(const Time& rhs)
    {
        m_time -= rhs.m_time;

        return (*this);
    }

    Time Time::operator*(float right) const
    {
        Time t(m_time);

        t *= right;

        return t;
    }

    Time& Time::operator*=(float right)
    {
        m_time *= right;

        return (*this);
    }

    Time Time::operator/(float right) const
    {
        Time t(m_time);

        t /= right;

        return t;
    }

    Time& Time::operator/=(float right)
    {
        m_time /= right;

        return (*this);
    }

    bool Time::operator==(const Time& rhs) const
    {
        return m_time == rhs.m_time;
    }

    bool Time::operator!=(const Time& rhs) const
    {
        return !((*this) == rhs);
    }

    bool Time::operator<=(const Time& rhs) const
    {
        return m_time <= rhs.m_time;
    }

    bool Time::operator<(const Time& rhs) const
    {
        return m_time < rhs.m_time;
    }

    bool Time::operator>=(const Time& rhs) const
    {
        return m_time >= rhs.m_time;
    }

    bool Time::operator>(const Time& rhs) const
    {
        return m_time > rhs.m_time;
    }
}
