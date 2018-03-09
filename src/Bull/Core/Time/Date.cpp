#include <Bull/Core/Time/Date.hpp>
#include <Bull/Core/Time/DateImpl.hpp>

namespace Bull
{
    Date Date::now()
    {
        return prv::DateImpl::now();
    }

    Date::Date() :
        day(0),
        year(0),
        hour(0),
        minute(0),
        second(0),
        month(DateMonth_January),
        dayOfWeek(DateDay_Monday)
    {
        /// Nothing
    }

    bool Date::operator==(const Date& left) const
    {
        return year   == left.year   &&
               month  == left.month  &&
               day    == left.day    &&
               hour   == left.hour   &&
               minute == left.minute &&
               second == left.second;
    }

    bool Date::operator!=(const Date& left) const
    {
        return !((*this) == left);
    }
}
