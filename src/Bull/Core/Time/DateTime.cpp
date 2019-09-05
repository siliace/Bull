#include <Bull/Core/Time/DateImpl.hpp>
#include <Bull/Core/Time/DateTime.hpp>
#include <Bull/Core/Time/TimeImpl.hpp>

namespace Bull
{
    DateTime DateTime::now()
    {
        return DateTime::make(prv::DateImpl::now(), prv::TimeImpl::now());
    }

    DateTime DateTime::make(const Bull::Date& date, const Bull::Time& time)
    {
        return {date, time};
    }

    bool DateTime::operator==(const Bull::DateTime& right) const
    {
        return m_date == right.m_date &&
               m_time == right.m_time;
    }

    bool DateTime::operator!=(const Bull::DateTime& right) const
    {
        return !(*this == right);
    }

    DateTime::DateTime(const Bull::Date& date, const Bull::Time& time) :
            m_date(date),
            m_time(time)
    {
        /// Nothing
    }

    const Date& DateTime::getDate() const
    {
        return m_date;
    }

    const Time& DateTime::getTime() const
    {
        return m_time;
    }
}