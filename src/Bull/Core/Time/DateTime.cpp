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
        return static_cast<const Date&>(*this) == static_cast<const Date&>(right) &&
               static_cast<const Time&>(*this) == static_cast<const Time&>(right);
    }

    bool DateTime::operator!=(const Bull::DateTime& right) const
    {
        return !(*this == right);
    }

    DateTime::DateTime(const Bull::Date& date, const Bull::Time& time) :
        Date(date),
        Time(time)
    {
        /// Nothing
    }
}