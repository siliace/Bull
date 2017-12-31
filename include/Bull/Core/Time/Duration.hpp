#ifndef BULL_CORE_TIME_DURATION_HPP
#define BULL_CORE_TIME_DURATION_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Duration
    {
    public:

        /*! \brief Construct a Duration form nanoseconds
         *
         * \param nanoseconds The number of nanoseconds
         *
         * \return Return the duration
         */
        static Duration nanoseconds(float nanoseconds);

        /*! \brief Construct a Duration form microseconds
         *
         * \param microseconds The number of microseconds
         *
         * \return Return the duration
         */
        static Duration microseconds(float microseconds);

        /*! \brief Construct a Duration form milliseconds
         *
         * \param milliseconds The number of milliseconds
         *
         * \return Return the duration
         */
        static Duration milliseconds(float milliseconds);

        /*! \brief Construct a Duration form seconds
         *
         * \param seconds The number of seconds
         *
         * \return Return the duration
         */
        static Duration seconds(float seconds);

        /*! \brief Construct a Duration form minutes
         *
         * \param minutes The number of minutes
         *
         * \return Return the duration
         */
        static Duration minutes(float minutes);

        /*! \brief Construct a Duration form hours
         *
         * \param hours The number of hours
         *
         * \return Return the duration
         */
        static Duration hours(float hours);

        /*! \brief Construct a Duration form days
         *
         * \param days The number of days
         *
         * \return Return the duration
         */
        static Duration days(float days);

        static Duration Zero;

        static Duration Infinite;

    public:

        /*! \brief Default constructor
         *
         */
        Duration();

        /*! \brief Constructor
         *
         * \param duration The number of seconds
         *
         */
        explicit Duration(float duration);

        /*! \brief Convert a duration to nanoseconds
         *
         * \return Return the duration converted to nanoseconds
         *
         */
        float asNanoseconds() const;

        /*! \brief Convert a duration to microseconds
         *
         * \return Return the duration converted to microseconds
         *
         */
        float asMicroseconds() const;

        /*! \brief Convert a duration to milliseconds
         *
         * \return Return the duration converted to milliseconds
         *
         */
        float asMilliseconds() const;

        /*! \brief Convert a duration to seconds
         *
         * \return Return the duration converted to seconds
         *
         */
        float asSeconds() const;

        /*! \brief Convert a duration to minutes
         *
         * \return Return the duration converted to minutes
         *
         */
        float asMinutes() const;

        /*! \brief Convert a duration to hours
         *
         * \return Return the duration converted to hours
         *
         */
        float asHours() const;

        /*! \brief Convert a duration to days
         *
         * \return Return the duration converted to days
         *
         */
        float asDays() const;

        /*! \brief Override == operator
         *
         * \param right The duration to compare
         *
         * \return Return true if durations are equals, else return false
         *
         */
        bool operator==(const Duration& right) const;

        /*! \brief Override != operator
         *
         * \param right The duration to compare
         *
         * \return Return false if durations are equals, else return true
         *
         */
        bool operator!=(const Duration& right) const;

        /*! \brief Override <= operator
         *
         * \param right The duration to compare
         *
         * \return Return true if durations are inferior or equals, else return false
         *
         */
        bool operator<=(const Duration& right) const;

        /*! \brief Override < operator
         *
         * \param right The duration to compare
         *
         * \return Return true if durations are inferior, else return false
         *
         */
        bool operator<(const Duration& right) const;

        /*! \brief Override >= operator
         *
         * \param right The duration to compare
         *
         * \return Return true if durations are superior or equals, else return false
         *
         */
        bool operator>=(const Duration& right) const;

        /*! \brief Override > operator
         *
         * \param right The duration to compare
         *
         * \return Return true if durations are superior, else return false
         *
         */
        bool operator>(const Duration& right) const;

        /*! \brief Addition a Duration to this
         *
         * \param right The duration to add
         *
         * \return The sum of this and right
         *
         */
        Duration operator+(const Duration& right) const;

        /*! \brief Addition a Duration to this
         *
         * \param right The duration to add
         *
         * \return The sum of this and right
         *
         */
        Duration& operator+=(const Duration& right);

        /*! \brief Subtract a Duration to this
         *
         * \param right The duration to subtract
         *
         * \return The difference of this and right
         *
         */
        Duration operator-(const Duration& right) const;

        /*! \brief Subtract a Duration to this
         *
         * \param right The duration to subtract
         *
         * \return The difference of this and right
         *
         */
        Duration& operator-=(const Duration& right);

        /*! \brief Override * operator
         *
         * \param right The duration to multiply
         *
         * \return Return the duration multiplied
         *
         */
        Duration operator*(float right) const;

        /*! \brief Override *= operator
         *
         * \param right The duration to multiply
         *
         * \return Return the duration multiplied
         *
         */
        Duration& operator*=(float right);

        /*! \brief Override / operator
         *
         * \param right The duration to divide
         *
         * \return Return the duration divided
         *
         */
        Duration operator/(float right) const;

        /*! \brief Override /= operator
         *
         * \param right The duration to divide
         *
         * \return Return the duration divided
         *
         */
        Duration& operator/=(float right);

    private:

        float m_duration;
    };
}

#endif // BULL_CORE_TIME_DURATION_HPP
