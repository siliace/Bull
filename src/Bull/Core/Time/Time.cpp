
#include <Bull/Core/Exception/InvalidParameter.hpp>

#include <Bull/Core/Time/Time.hpp>
#include <Bull/Core/Time/TimeImpl.hpp>

namespace Bull
{
    Time Time::now()
    {
        return prv::TimeImpl::now();
    }

    Time Time::make(unsigned int hour)
    {
        return Time::make(hour, 0);
    }

    Time Time::make(unsigned int hour, unsigned int minute)
    {
        return Time::make(hour, minute, 0);
    }

    Time Time::make(unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond)
    {
        Expect(hour < 24, Throw(InvalidParameter, "Time::make", "Invalid hour"));
        Expect(minute < 60, Throw(InvalidParameter, "Time::make", "Invalid minute"));
        Expect(second < 60, Throw(InvalidParameter, "Time::make", "Invalid second"));
        Expect(millisecond < 1000, Throw(InvalidParameter, "Time::make", "Invalid millisecond"));

        return {hour, minute, second, millisecond};
    }

    bool Time::operator==(const Time& right) const {
        return m_hour == right.m_hour &&
               m_minute == right.m_minute &&
               m_second == right.m_second &&
               m_millisecond == right.m_millisecond;
    }

    bool Time::operator!=(const Time& right) const {
        return !(*this == right);
    }

    Time::Time(unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond) :
        m_hour(hour),
        m_minute(minute),
        m_second(second),
        m_millisecond(millisecond)
    {
        /// Nothing
    }
}