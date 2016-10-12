#ifndef Bull_Date_hpp
#define Bull_Date_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/Time/Time.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    struct Date
    {
        enum Day
        {
            Monday    = 1,
            Tuesday   = 2,
            Wednesday = 3,
            Thusday   = 4,
            Friday    = 5,
            Saturday  = 6,
            Sunday    = 7
        };

        enum Month
        {
            January   = 1,
            Febuary   = 2,
            March     = 3,
            April     = 4,
            May       = 5,
            June      = 6,
            Juily     = 7,
            August    = 8,
            September = 9,
            Octover   = 10,
            November  = 11,
            December  = 12
        };

        /*! \brief Get the current date
         *
         * \return Return the current date
         *
         */
        static Date now();

        /*! \brief Default constructor
         *
         */
        Date();

        /*! \brief Compare two dates
         *
         * \param left The Date to compare with this
         *
         * \return Return true if this and left are equal, false otherwise
         *
         */
        bool operator==(const Date& left) const;

        /*! \brief Compare two dates
         *
         * \param left The Date to compare with this
         *
         * \return Return true if this and left are not equal, false otherwise
         *
         */
        bool operator!=(const Date& left) const;

        /*! \brief Compare two dates
         *
         * \param left The date to compare with this
         *
         * \return Return true if this is superior or equal to left, false otherwise
         *
         */
        bool operator>=(const Date& left) const;

        /*! \brief Compare two dates
         *
         * \param left The date to compare with this
         *
         * \return Return true if this is superior to left, false otherwise
         *
         */
        bool operator>(const Date& left) const;

        /*! \brief Compare two dates
         *
         * \param left The date to compare with this
         *
         * \return Return true if this is inferior or equal to left, false otherwise
         *
         */
        bool operator<=(const Date& left) const;

        /*! \brief Compare two dates
         *
         * \param left The date to compare with this
         *
         * \return Return true if this is inferior to left, false otherwise
         *
         */
        bool operator<(const Date& left) const;

        /*! \brief Add a date to this
         *
         * \param left The date to add to this
         *
         * \return Return this after the addition
         *
         */
        Date& operator+=(const Date& left);

        /*! \brief Addition of two dates
         *
         * \param left The date to add to this
         *
         * \return Return the sum of this and left
         *
         */
        Date operator+(const Date& left) const;

        /*! \brief Subtract a date to this
         *
         * \param left The date to subtract to this
         *
         * \return Return this after the subtraction
         *
         */
        Date& operator-=(const Date& left);

        /*! \brief Subtraction  of two dates
         *
         * \param left The date to add to this
         *
         * \return Return the difference of this and left
         *
         */
        Date operator-(const Date& left) const;

        Uint32 year;
        Month  month;
        Uint8  day;
        Day    dayOfWeek;
        Uint8  hour;
        Uint8  minute;
        Time   second;
    };
}

#endif // Bull_Date_hpp
