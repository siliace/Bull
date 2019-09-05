#ifndef BULL_ANGLE_HPP
#define BULL_ANGLE_HPP

#include <Bull/Math/Constants.hpp>

namespace Bull
{
    /** \class Angle
     *
     * \brief Implement an universal Angle to handle both degree and radian angles
     *
     * \tparam T The type of the Angle value
     *
     */
    template <typename T>
    class Angle
    {
    public:

        static Angle<T> Zero;

        /** \brief Create a Angle in degree
         *
         * \param value The value of the Angle
         *
         * \return The Angle
         *
         */
        static Angle<T> degree(T value)
        {
            return Angle<T>(value, true);
        }

        /** \brief Create a Angle in radian
         *
         * \param value The value of the Angle
         *
         * \return The Angle
         *
         */
        static Angle<T> radian(T value)
        {
            return Angle<T>(value);
        }

        /** \brief Normalize an Angle
         *
         * \param angle The Angle to normalize
         *
         * \return The normalized Angle
         *
         */
        static Angle<T> normalize(const Angle<T>& angle)
        {
            return Angle<T>(angle).normalize();
        }

        /** \brief Clamp an Angle
         *
         * \param angle The Angle to clamp
         * \param min   The min value of the Angle
         * \param max   The max value of the Angle
         *
         * \return The clamped Angle
         *
         */
        static Angle<T> clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max)
        {
            return Angle<T>(angle).clamp(min, max);
        }

    public:

        /** \brief Default constructor
         *
         */
        Angle() :
                Angle(0, false)
        {
            /// Nothing
        }

        /** \brief Normalize the Angle
         *
         * \return This
         *
         */
        Angle<T>& normalize()
        {
            const float pi2 = 2 * Pi;

            while(m_value >= 2 * Pi)
            {
                m_value -= 2 * Pi;
            }

            return (*this);
        }

        float toDegree() const
        {
            return m_value * 180 / Pi;
        }

        float toRadian() const
        {
            return m_value;
        }

        /** \brief Clamp the Angle
         *
         * \param min The min value of the Angle
         * \param max The max value of the Angle
         *
         * \return This
         *
         */
        Angle<T>& clamp(const Angle<T>& min, const Angle<T>& max)
        {
            if(m_value < min.m_value)
            {
                m_value = min.m_value;
            }
            else if(m_value > max.m_value)
            {
                m_value = max.m_value;
            }

            return (*this);
        }

        /** \brief Compare two Angle
         *
         * \param right The Angle to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Angle<T>& right)
        {
            return m_value == right.m_value;
        }

        /** \brief Compare two Angle
         *
         * \param right The Angle to compare to this
         *
         * \return True if left and right are not equal
         *
         */
        bool operator!=(const Angle<T>& right)
        {
            return m_value != right.m_value;
        }

        bool operator<(const Angle<T>& right)
        {
            return m_value < right.m_value;
        }

        bool operator<=(const Angle<T>& right)
        {
            return m_value <= right.m_value;
        }

        bool operator>(const Angle<T>& right)
        {
            return m_value > right.m_value;
        }

        bool operator>=(const Angle<T>& right)
        {
            return m_value >= right.m_value;
        }

        Angle<T> operator+(const Angle<T>& right)
        {
            return Angle<T>(m_value + right.m_value);
        }

        Angle<T> operator-(const Angle<T>& right)
        {
            return Angle<T>(m_value - right.m_value);
        }

        template <typename U>
        friend Angle<U> operator*(U left, const Angle<U>& right)
        {
            return Angle<U>(left * right.m_value);
        }

        template <typename U>
        friend Angle<U> operator*(const Angle<U>& left, U right)
        {
            return Angle<U>(left.m_value * right);
        }

        template <typename U>
        friend Angle<U> operator/(U left, const Angle<U>& right)
        {
            return Angle<U>(left / right.m_value);
        }

        template <typename U>
        friend Angle<U> operator/(const Angle<U>& left, U right)
        {
            return Angle<U>(left.m_value / right);
        }

        Angle<T>& operator+=(const Angle<T>& right)
        {
            m_value += right.m_value;

            return (*this);
        }

        Angle<T>& operator-=(const Angle<T>& right)
        {
            m_value -= right.m_value;

            return (*this);
        }

        Angle<T>& operator*=(T right)
        {
            m_value *= right;

            return (*this);
        }

        Angle<T>& operator/=(T right)
        {
            m_value /= right;

            return (*this);
        }

        template <typename U>
        friend float std::cos(const Bull::Angle<U>& angle);

        template <typename U>
        friend float std::acos(const Bull::Angle<U>& angle);

        template <typename U>
        friend float std::sin(const Bull::Angle<U>& angle);

        template <typename U>
        friend float std::asin(const Bull::Angle<U>& angle);

        template <typename U>
        friend float std::tan(const Bull::Angle<U>& angle);

        template <typename U>
        friend float std::atan(const Bull::Angle<U>& angle);

    private:

        /** \brief Constructor
         *
         * \param value   The value of the Angle
         * \param convert True if the value needs to be converted in radian
         *
         */
        explicit Angle(T value, bool convert = false)
        {
            if(convert)
            {
                value = value * Pi / 180;
            }

            m_value = value;
        }

        T m_value;
    };

    template <typename T>
    Angle<T> Angle<T>::Zero = Angle<T>();

    typedef Angle<int> AngleI;
    typedef Angle<float> AngleF;
    typedef Angle<double> AngleD;
    typedef Angle<unsigned int> AngleUI;
}

namespace std
{
    template <typename U>
    float cos(const Bull::Angle<U>& angle)
    {
        return std::cos(angle.m_value);
    }

    template <typename U>
    float acos(const Bull::Angle<U>& angle)
    {
        return std::acos(angle.m_value);
    }

    template <typename U>
    float sin(const Bull::Angle<U>& angle)
    {
        return std::sin(angle.m_value);
    }

    template <typename U>
    float asin(const Bull::Angle<U>& angle)
    {
        return std::asin(angle.m_value);
    }

    template <typename U>
    float tan(const Bull::Angle<U>& angle)
    {
        return std::tan(angle.m_value);
    }

    template <typename U>
    float atan(const Bull::Angle<U>& angle)
    {
        return std::atan(angle.m_value);
    }

}

#endif // BULL_ANGLE_HPP
