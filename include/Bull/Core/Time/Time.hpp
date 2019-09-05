#ifndef BULL_CORE_TIME_TIME_HPP
#define BULL_CORE_TIME_TIME_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Time
    {
    public:

        /** \brief Create a Time of now
         *
         * \return The created time
         *
         */
        static Time now();

        /** \brief Create a Time of a given hour
         *
         * \param hour The hour
         *
         * \return The created Time
         *
         */
        static Time make(unsigned int hour);

        /** \brief Create a Time of a given hour and minute
         *
         * \param hour   The hour
         * \param minute The minute
         *
         * \return The created Time
         *
         */
        static Time make(unsigned int hour, unsigned int minute);

        /** \brief Create a Time of a given hour, minute, second and millisecond
         *
         * \param hour        The hour
         * \param minute      The minute
         * \param second      The second
         * \param millisecond The millisecond
         *
         * \return The created Time
         *
         */
        static Time make(unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond = 0);

    public:

        /** \brief Get the hour of the Time
         *
         * \return The hour
         *
         */
        inline unsigned int getHour() const
        {
            return m_hour;
        }

        /** \brief Get the minute of the Time
         *
         * \return The minute
         *
         */
        inline unsigned int getMinute() const
        {
            return m_minute;
        }

        /** \brief Get the second of the Time
         *
         * \return The second
         *
         */
        inline unsigned int getSecond() const
        {
            return m_second;
        }

        /** \brief Get the millisecond of the Time
         *
         * \return The millisecond
         *
         */
        inline unsigned int getMillisecond() const
        {
            return m_millisecond;
        }

        /** \brief Compare two Time
         *
         * \param right The Time to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Time& right) const;

        /** \brief Compare two Time
         *
         * \param right The Time to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Time& right) const;

    private:

        /** \brief Constructor
         *
         * \param hour        The hour of the Time
         * \param minute      The minute of the Time
         * \param second      The second of the Time
         * \param millisecond The millisecond of the Time
         *
         */
        Time(unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond);

    private:

        unsigned int m_hour;
        unsigned int m_minute;
        unsigned int m_second;
        unsigned int m_millisecond;
    };
}

#endif // BULL_CORE_TIME_TIME_HPP
