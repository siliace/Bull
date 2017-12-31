#ifndef BULL_CORE_TIME_DATE_HPP
#define BULL_CORE_TIME_DATE_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Time/DateDay.hpp>
#include <Bull/Core/Time/DateMonth.hpp>
#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    struct BULL_CORE_API Date
    {
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

        Uint8     day;
        Uint8     hour;
        Uint32    year;
        DateMonth month;
        Uint8     minute;
        Duration      second;
        DateDay   dayOfWeek;
    };
}

#endif // BULL_CORE_TIME_DATE_HPP
