#include <Bull/Core/Time/Date.hpp>
#include <Bull/Core/Time/DateImpl.hpp>

namespace Bull
{
    /*! \brief Get the current date
     *
     * \return Return the current date
     *
     */
    Date Date::now()
    {
        return prv::DateImpl::now();
    }

    /*! \brief Default constructor
     *
     */
    Date::Date() :
        year(1970),
        month(Month::January),
        day(1),
        dayOfWeek(Day::Thusday),
        hour(0),
        minute(0),
        second(Time::seconds(0))
    {
        /// Nothing
    }

    /*! \brief Compare two dates
     *
     * \param left The Date to compare with this
     *
     * \return Return true if this and left are equal, false otherwise
     *
     */
    bool Date::operator==(const Date& left) const
    {
        return (year   == left.year)   &&
               (month  == left.month)  &&
               (day    == left.day)    &&
               (hour   == left.hour)   &&
               (minute == left.minute) &&
               (second == left.second);
    }

    /*! \brief Compare two dates
     *
     * \param left The Date to compare with this
     *
     * \return Return true if this and left are not equal, false otherwise
     *
     */
    bool Date::operator!=(const Date& left) const
    {
        return !((*this) == left);
    }

    bool Date::operator>=(const Date& left) const
    {
        return ((*this) < left);
    }

    bool Date::operator>(const Date& left) const
    {
        return !((*this) <= left);
    }

    bool Date::operator<=(const Date& left) const
    {
        if((*this) == left)
        {
            return true;
        }

        return (*this) < left;
    }

    bool Date::operator<(const Date& left) const
    {
        if(year < left.year)
        {
            return true;
        }

        if(month < left.month)
        {
            return true;
        }

        if(day < left.day)
        {
            return true;
        }

        if(hour < left.hour)
        {
            return true;
        }

        if(minute < left.minute)
        {
            return true;
        }

        if(second < left.second)
        {
            return true;
        }

        return false;
    }

    Date& Date::operator+=(const Date& left)
    {

    }

    Date Date::operator+(const Date& left) const
    {
        return Date((*this)) += left;
    }

    Date& Date::operator-=(const Date& left)
    {

    }

    Date Date::operator-(const Date& left) const
    {
        return Date((*this)) -= left;
    }
}
