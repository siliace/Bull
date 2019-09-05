#include <Bull/Core/Time/Duration.hpp>
#include <limits>

namespace Bull
{
    Duration Duration::Zero = Duration::seconds(0.f);

    Duration Duration::Infinite = Duration::seconds(std::numeric_limits<float>::max());

    Duration Duration::nanoseconds(float nanoseconds)
    {
        return Duration(nanoseconds / 1000000000);
    }

    Duration Duration::microseconds(float microseconds)
    {
        return Duration(microseconds / 1000000);
    }

    Duration Duration::milliseconds(float milliseconds)
    {
        return Duration(milliseconds / 1000);
    }

    Duration Duration::seconds(float seconds)
    {
        return Duration(seconds);
    }

    Duration Duration::minutes(float minutes)
    {
        return Duration(minutes * 60);
    }

    Duration Duration::hours(float hours)
    {
        return Duration(hours * 3600);
    }

    Duration Duration::days(float days)
    {
        return Duration(days * 86400);
    }

    Duration::Duration() :
            m_duration(0.f)
    {
        /// Nothing
    }

    Duration::Duration(float time) :
            m_duration(time)
    {
        /// Nothing
    }

    float Duration::asNanoseconds() const
    {
        return m_duration * 1000000000;
    }

    float Duration::asMicroseconds() const
    {
        return m_duration * 1000000;
    }

    float Duration::asMilliseconds() const
    {
        return m_duration * 1000;
    }

    float Duration::asSeconds() const
    {
        return m_duration;
    }

    float Duration::asMinutes() const
    {
        return m_duration / 60;
    }

    float Duration::asHours() const
    {
        return m_duration / 3600;
    }

    float Duration::asDays() const
    {
        return m_duration / 86400;
    }

    Duration Duration::operator+(const Duration& right) const
    {
        Duration t(m_duration);

        t += right;

        return t;
    }

    Duration& Duration::operator+=(const Duration& right)
    {
        m_duration += right.m_duration;

        return (*this);
    }

    Duration Duration::operator-(const Duration& right) const
    {
        Duration t(m_duration);

        t -= right;

        return t;
    }

    Duration& Duration::operator-=(const Duration& right)
    {
        m_duration -= right.m_duration;

        return (*this);
    }

    Duration Duration::operator*(float right) const
    {
        Duration t(m_duration);

        t *= right;

        return t;
    }

    Duration& Duration::operator*=(float right)
    {
        m_duration *= right;

        return (*this);
    }

    Duration Duration::operator/(float right) const
    {
        Duration t(m_duration);

        t /= right;

        return t;
    }

    Duration& Duration::operator/=(float right)
    {
        m_duration /= right;

        return (*this);
    }

    bool Duration::operator==(const Duration& right) const
    {
        return m_duration == right.m_duration;
    }

    bool Duration::operator!=(const Duration& right) const
    {
        return !((*this) == right);
    }

    bool Duration::operator<=(const Duration& right) const
    {
        return m_duration <= right.m_duration;
    }

    bool Duration::operator<(const Duration& right) const
    {
        return m_duration < right.m_duration;
    }

    bool Duration::operator>=(const Duration& right) const
    {
        return m_duration >= right.m_duration;
    }

    bool Duration::operator>(const Duration& right) const
    {
        return m_duration > right.m_duration;
    }
}
