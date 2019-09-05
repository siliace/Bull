#ifndef BULL_CORE_TIME_DATE_HPP
#define BULL_CORE_TIME_DATE_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Time/DateDay.hpp>
#include <Bull/Core/Time/DateMonth.hpp>

namespace Bull
{
    class BULL_CORE_API Date
    {
    public:

        /** \brief Create a Date of now
         *
         * \return The created Date
         *
         */
        static Date now();

        /** \brief Create a Date of the given year
         *
         * \param year The year
         *
         * \return The created Date
         *
         */
        static Date make(unsigned int year);

        /** \brief Create a Date of the given year and month
         *
         * \param year  The year
         * \param month The month
         *
         * \return The created Date
         *
         */
        static Date make(unsigned int year, DateMonth month);

        /** \brief Create a Date of the given year, month and day
         *
         * \param year  The year
         * \param month The month
         * \param day   The day
         *
         * \return The created Date
         *
         */
        static Date make(unsigned int year, DateMonth month, unsigned int day);

    public:

        /** \brief Get the year of the Date
         *
         * \return Teh year
         *
         */
        inline unsigned int getYear() const
        {
            return m_year;
        }

        /** \brief Get the month of the Date
         *
         * \return The month
         *
         */
        inline DateMonth getMonth() const
        {
            return m_month;
        }

        /** \brief Get the day of the Date
         *
         * \return The day
         *
         */
        inline unsigned int getDay() const
        {
            return m_day;
        }

        /** \brief Get the day of the year
         *
         * \return The day of the year
         *
         */
        unsigned int getDayOfYear() const;

        /** \brief Tell whether the year of the Date is leap
         *
         * \return True if the year is leap
         *
         */
        bool isLeap() const;

        /** \brief Compare two dates
         *
         * \param left The Date to compare with this
         *
         * \return True if this and left are equal
         *
         */
        bool operator==(const Date& left) const;

        /** \brief Compare two dates
         *
         * \param left The Date to compare with this
         *
         * \return True if this and left are not equal
         *
         */
        bool operator!=(const Date& left) const;

    private:

        /** \brief Constructor
         *
         * \param year  The year of the Date
         * \param month The month of the Date
         * \param day   The day of the Date
         *
         */
        Date(unsigned int year, DateMonth month, unsigned int day);

        unsigned int m_year;
        DateMonth m_month;
        unsigned int m_day;
    };
}

#endif // BULL_CORE_TIME_DATE_HPP
