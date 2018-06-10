#ifndef BULL_CORE_TIME_DATETIME_HPP
#define BULL_CORE_TIME_DATETIME_HPP

#include <Bull/Core/Time/Date.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    class BULL_CORE_API DateTime
    {
    public:

        /*! \brief Create a DateTime of now
         *
         * \return The created DateTime
         */
        static DateTime now();

        /*! \brief Create a DateTime form a Date and a Time
         *
         * \param date The Date
         * \param time The Time
         *
         * \return The created DateTime
         *
         */
        static DateTime make(const Bull::Date& date, const Bull::Time& time);

    public:

        /*! \brief Get the Date of the DateTime
         *
         * \return The Date
         *
         */
        const Date& getDate() const;

        /*! \brief Get the Time of the DateTime
         *
         * \return The Time
         *
         */
        const Time& getTime() const;

        /*! \brief Compare two DateTime
         *
         * \param right The DateTime to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const DateTime& right) const;

        /*! \brief Compare two DateTime
         *
         * \param right The DateTime to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const DateTime& right) const;

    private:

        /*! \brief Constructor
         *
         * \param date The Date
         * \param time The Time
         *
         */
        DateTime(const Date& date, const Time& time);

    private:

        Date m_date;
        Time m_time;
    };
}

#endif // BULL_CORE_TIME_DATETIME_HPP
