#include <map>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Time/Date.hpp>
#include <Bull/Core/Time/DateImpl.hpp>

namespace Bull
{
    namespace
    {
        std::map<DateMonth, unsigned int> monthDays = {
                {DateMonth_January, 31},
                {DateMonth_Febuary, 28},
                {DateMonth_March, 31},
                {DateMonth_April, 30},
                {DateMonth_May, 31},
                {DateMonth_June, 30},
                {DateMonth_Juily, 31},
                {DateMonth_August, 31},
                {DateMonth_September, 30},
                {DateMonth_October, 31},
                {DateMonth_November, 30},
                {DateMonth_December, 31},
        };
    }

    Date Date::now()
    {
        return prv::DateImpl::now();
    }

    Date Date::make(unsigned int year)
    {
        return Date::make(year, DateMonth::DateMonth_January);
    }

    Date Date::make(unsigned int year, DateMonth month)
    {
        return Date::make(year, month, 1);
    }

    Date Date::make(unsigned int year, DateMonth month, unsigned int day)
    {
        Expect(month <= 12, Throw(InvalidParameter, "Date::make", "Invalid month"));
        Expect(day <= 31, Throw(InvalidParameter, "Date::make", "Invalid month"));

        return {year, month, day};
    }

    unsigned int Date::getDayOfYear() const
    {
        unsigned int day = 0;

        for(DateMonth i = DateMonth_January; i < m_month; i = DateMonth(static_cast<int>(i) + 1))
        {
            day += monthDays[m_month];
        }

        if(isLeap() && m_month > DateMonth_Febuary)
        {
            day += 1;
        }

        return day;
    }

    bool Date::isLeap() const
    {
        if(m_year % 4 != 0)
        {
            return false;
        }
        else if(m_year % 100 != 0)
        {
            return true;
        }
        else if(m_year % 400 != 0)
        {
            return false;
        }

        return true;
    }

    bool Date::operator==(const Bull::Date& left) const
    {
        return m_year == left.m_year &&
               m_month == left.m_month &&
               m_day == left.m_day;
    }

    bool Date::operator!=(const Bull::Date& left) const
    {
        return !(*this == left);
    }

    Date::Date(unsigned int year, Bull::DateMonth month, unsigned int day) :
        m_year(year),
        m_month(month),
        m_day(day)
    {
        /// Nothing
    }
}
