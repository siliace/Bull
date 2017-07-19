#ifndef BULL_ANGLE_HPP
#define BULL_ANGLE_HPP

#include <Bull/Math/Constants.hpp>

namespace Bull
{
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

        /*! \brief
         *
         * \param angle
         *
         * \return
         *
         */
        static Angle<T> toDegree(const Angle<T>& angle);

        /*! \brief
         *
         * \param angle
         *
         * \return
         *
         */
        static Angle<T> toRadian(const Angle<T>& angle);

        /*! \brief
         *
         * \param angle
         *
         * \return
         *
         */
        static Angle<T> normalize(const Angle<T>& angle);

        /*! \brief
         *
         * \param angle
         * \param min
         * \param max
         *
         * \return
         *
         */
        static Angle<T> clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max);

    public:

        /*! \brief Default constructor
         *
         */
        Angle();

        /*! \brief
         *
         * \return
         *
         */
        Angle<T>& toRadian();

        /*! \brief
         *
         * \return
         *
         */
        Angle<T>& toDegree();

        /*! \brief
         *
         * \return
         *
         */
        Angle<T>& normalize();

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are equal
         *
         */
        template <typename U>
        friend bool operator==(const Angle<U>& left, const Angle<U>& right);

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are equal
         *
         */
        template <typename U>
        friend bool operator==(U left, const Angle<U>& right);

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are equal
         *
         */
        template <typename U>
        friend bool operator==(const Angle<U>& left, U right);

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are not equal
         *
         */
        template <typename U>
        friend bool operator!=(const Angle<U>& left, const Angle<U>& right);

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are not equal
         *
         */
        template <typename U>
        friend bool operator!=(U left, const Angle<U>& right);

        /*! \brief Compare two Angles
         *
         * \param left
         * \param right
         *
         * \return True if left and right are not equal
         *
         */
        template <typename U>
        friend bool operator!=(const Angle<U>& left, U right);

        template <typename U>
        friend bool operator<(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend bool operator<(U left, const Angle<U>& right);

        template <typename U>
        friend bool operator<(const Angle<U>& left, U right);

        template <typename U>
        friend bool operator<=(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend bool operator<=(U left, const Angle<U>& right);

        template <typename U>
        friend bool operator<=(const Angle<U>& left, U right);

        template <typename U>
        friend bool operator>(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend bool operator>(U left, const Angle<U>& right);

        template <typename U>
        friend bool operator>(const Angle<U>& left, U right);

        template <typename U>
        friend bool operator>=(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend bool operator>=(U left, const Angle<U>& right);

        template <typename U>
        friend bool operator>=(const Angle<U>& left, U right);

        template <typename U>
        friend Angle<U> operator+(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator+(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator+(const Angle<U>& left, U right);

        template <typename U>
        friend Angle<U> operator-(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator-(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator-(const Angle<U>& left, U right);

        template <typename U>
        friend Angle<U> operator*(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator*(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator*(const Angle<U>& left, U right);

        template <typename U>
        friend Angle<U> operator/(const Angle<U>& left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator/(U left, const Angle<U>& right);

        template <typename U>
        friend Angle<U> operator/(const Angle<U>& left, U right);

        Angle<T>& operator+=(T right);

        Angle<T>& operator+=(const Angle<T>& right);

        Angle<T>& operator-=(T right);

        Angle<T>& operator-=(const Angle<T>& right);

        Angle<T>& operator*=(T right);

        Angle<T>& operator*=(const Angle<T>& right);

        Angle<T>& operator/=(T right);

        Angle<T>& operator/=(const Angle<T>& right);

        template <typename U>
        friend float std::cos(const Angle<U>& angle);

        template <typename U>
        friend float std::sin(const Angle<U>& angle);

        template <typename U>
        friend float std::tan(const Angle<U>& angle);

    protected:

        /*! \brief Constructor
         *
         * \param value    The value of the Angle
         * \param isRadian True if the Angle is in radian
         *
         */
        Angle(T value, bool isRadian);

    private:

        T    m_angle;
        bool m_isRadian;
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
