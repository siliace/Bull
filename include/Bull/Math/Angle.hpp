#ifndef BULL_ANGLE_HPP
#define BULL_ANGLE_HPP

#include <Bull/Math/Constants.hpp>

namespace Bull
{
    /*! \class Angle
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

        /*! \brief Create a Angle in degree
         *
         * \param value The value of the Angle
         *
         * \return The Angle
         *
         */
        static Angle<T> degree(T value);

        /*! \brief Create a Angle in radian
         *
         * \param value The value of the Angle
         *
         * \return The Angle
         *
         */
        static Angle<T> radian(T value);

        /*! \brief Normalize an Angle
         *
         * \param angle The Angle to normalize
         *
         * \return The normalized Angle
         *
         */
        static Angle<T> normalize(const Angle<T>& angle);

        /*! \brief Clamp an Angle
         *
         * \param angle The Angle to clamp
         * \param min   The min value of the Angle
         * \param max   The max value of the Angle
         *
         * \return The clamped Angle
         *
         */
        static Angle<T> clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max);

    public:

        /*! \brief Default constructor
         *
         */
        Angle();

        /*! \brief Normalize the Angle
         *
         * \return This
         *
         */
        Angle<T>& normalize();

        /*! \brief Clamp the Angle
         *
         * \param min The min value of the Angle
         * \param max The max value of the Angle
         *
         * \return This
         *
         */
        Angle<T>& clamp(const Angle<T>& min, const Angle<T>& max);

        /*! \brief Compare two Angle
         *
         * \param right The Angle to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Angle<T>& right);

        /*! \brief Compare two Angle
         *
         * \param right The Angle to compare to this
         *
         * \return True if left and right are not equal
         *
         */
        bool operator!=(const Angle<T>& right);

        bool operator<(const Angle<T>& right);

        bool operator<=(const Angle<T>& right);

        bool operator>(const Angle<T>& right);

        bool operator>=(const Angle<T>& right);

        Angle<T> operator+(const Angle<T>& right);

        Angle<T> operator-(const Angle<T>& right);

        template <typename U>
        friend Angle<U> operator*(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator*(const Angle<U>& left, U right);

        template <typename U>
        friend Angle<U> operator/(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator/(const Angle<U>& left, U right);

        Angle<T>& operator+=(const Angle<T>& right);

        Angle<T>& operator-=(const Angle<T>& right);

        Angle<T>& operator*=(T right);

        Angle<T>& operator/=(T right);

        template <typename U>
        friend float std::cos(const Angle<U>& angle);

        template <typename U>
        friend float std::acos(const Angle<U>& angle);

        template <typename U>
        friend float std::sin(const Angle<U>& angle);

        template <typename U>
        friend float std::asin(const Angle<U>& angle);

        template <typename U>
        friend float std::tan(const Angle<U>& angle);

        template <typename U>
        friend float std::atan(const Angle<U>& angle);

    private:

        /*! \brief Constructor
         *
         * \param value   The value of the Angle
         * \param convert True if the value needs to be converted in radian
         *
         */
        Angle(T value, bool convert = false);

        T m_value;
    };

    template <typename T>
    Angle<T> Angle<T>::Zero = Angle<T>();

    typedef Angle<int> AngleI;
    typedef Angle<float> AngleF;
    typedef Angle<double> AngleD;
    typedef Angle<unsigned int> AngleUI;
}

#include <Bull/Math/Angle.inl>

#endif // BULL_ANGLE_HPP
