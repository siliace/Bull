#include <Bull/Core/Time/Date.hpp>
#include <Bull/Core/Time/DateImpl.hpp>

namespace Bull
{
    Date Date::now()
    {
        return prv::DateImpl::now();
    }

    Date::Date() :
        Date(Date::now())
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
