#ifndef BULL_CORE_TIME_TIME_HPP
#define BULL_CORE_TIME_TIME_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Time
    {
    public:

        /*! \brief Construct a Time form nanoseconds
         *
         * \param nanoseconds The number of nanoseconds
         *
         * \return Return the time
         */
        static Time nanoseconds(float nanoseconds);

        /*! \brief Construct a Time form microseconds
         *
         * \param microseconds The number of microseconds
         *
         * \return Return the time
         */
        static Time microseconds(float microseconds);

        /*! \brief Construct a Time form milliseconds
         *
         * \param milliseconds The number of milliseconds
         *
         * \return Return the time
         */
        static Time milliseconds(float milliseconds);

        /*! \brief Construct a Time form seconds
         *
         * \param seconds The number of seconds
         *
         * \return Return the time
         */
        static Time seconds(float seconds);

        /*! \brief Construct a Time form minutes
         *
         * \param minutes The number of minutes
         *
         * \return Return the time
         */
        static Time minutes(float minutes);

        /*! \brief Construct a Time form hours
         *
         * \param hours The number of hours
         *
         * \return Return the time
         */
        static Time hours(float hours);

        /*! \brief Construct a Time form days
         *
         * \param days The number of days
         *
         * \return Return the time
         */
        static Time days(float days);

        static Time Zero;

    public:

        /*! \brief Default constructor
         *
         */
        Time();

        /*! \brief Constructor
         *
         * \param time The number of seconds
         *
         */
        explicit Time(float time);

        /*! \brief Convert a time to nanoseconds
         *
         * \return Return the time converted to nanoseconds
         *
         */
        float asNanoseconds() const;

        /*! \brief Convert a time to microseconds
         *
         * \return Return the time converted to microseconds
         *
         */
        float asMicroseconds() const;

        /*! \brief Convert a time to milliseconds
         *
         * \return Return the time converted to milliseconds
         *
         */
        float asMilliseconds() const;

        /*! \brief Convert a time to seconds
         *
         * \return Return the time converted to seconds
         *
         */
        float asSeconds() const;

        /*! \brief Convert a time to minutes
         *
         * \return Return the time converted to minutes
         *
         */
        float asMinutes() const;

        /*! \brief Convert a time to hours
         *
         * \return Return the time converted to hours
         *
         */
        float asHours() const;

        /*! \brief Convert a time to days
         *
         * \return Return the time converted to days
         *
         */
        float asDays() const;

        /*! \brief Override + operator
         *
         * \param rhs The time to add
         *
         * \return Return the time added
         *
         */
        Time operator+(const Time& rhs) const;

        /*! \brief Override += operator
         *
         * \param rhs The time to add
         *
         * \return Return the time added
         *
         */
        Time& operator+=(const Time& rhs);

        /*! \brief Override - operator
         *
         * \param rhs The time to substract
         *
         * \return Return the time substracted
         *
         */
        Time operator-(const Time& rhs) const;

        /*! \brief Override -= operator
         *
         * \param rhs The time to substract
         *
         * \return Return the time substracted
         *
         */
        Time& operator-=(const Time& rhs);

        /*! \brief Override * operator
         *
         * \param rhs The time to multiply
         *
         * \return Return the time multiplied
         *
         */
        Time operator*(const Time& rhs) const;

        /*! \brief Override *= operator
         *
         * \param rhs The time to multiply
         *
         * \return Return the time multiplied
         *
         */
        Time& operator*=(const Time& rhs);

        /*! \brief Override / operator
         *
         * \param rhs The time to divide
         *
         * \return Return the time divided
         *
         */
        Time operator/(const Time& rhs) const;

        /*! \brief Override /= operator
         *
         * \param rhs The time to divide
         *
         * \return Return the time divided
         *
         */
        Time& operator/=(const Time& rhs);

        /*! \brief Override == operator
         *
         * \param rhs The time to compare
         *
         * \return Return true if times are equals, else return false
         *
         */
        bool operator==(const Time& rhs) const;

        /*! \brief Override != operator
         *
         * \param rhs The time to compare
         *
         * \return Return false if times are equals, else return true
         *
         */
        bool operator!=(const Time& rhs) const;

        /*! \brief Override <= operator
         *
         * \param rhs The time to compare
         *
         * \return Return true if times are inferior or equals, else return false
         *
         */
        bool operator<=(const Time& rhs) const;

        /*! \brief Override < operator
         *
         * \param rhs The time to compare
         *
         * \return Return true if times are inferior, else return false
         *
         */
        bool operator<(const Time& rhs) const;

        /*! \brief Override >= operator
         *
         * \param rhs The time to compare
         *
         * \return Return true if times are superior or equals, else return false
         *
         */
        bool operator>=(const Time& rhs) const;

        /*! \brief Override > operator
         *
         * \param rhs The time to compare
         *
         * \return Return true if times are superior, else return false
         *
         */
        bool operator>(const Time& rhs) const;

    private:

        float m_time;
    };
}

#endif // BULL_CORE_TIME_TIME_HPP
