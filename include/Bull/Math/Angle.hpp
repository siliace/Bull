#ifndef Bull_Angle_hpp
#define Bull_Angle_hpp

#include <cmath>
#include <functional>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Constants.hpp>

namespace Bull
{
    template<typename T>
    struct Angle
    {
    public:

        /*! \brief Create an angle in radians
         *
         * \param angle The value in radians of the angle to create
         *
         * \return Return the created angle
         *
         */
        static Angle<T> radian(T angle);

        /*! \brief Create an angle in degrees
         *
         * \param angle The value in degrees of the angle to create
         *
         * \return Return the created angle
         *
         */
        static Angle<T> degree(T angle);

        static Angle<T> Zero;

    public:

        /*! \brief Default constructor
         *
         */
        Angle() = default;

        /*! \brief Set the value of the angle
         *
         * \param angle    The value of the angle
         * \param isRadian Whether the angle value is in radian
         *
         * \return This
         *
         */
        Angle& set(T angle, bool isRadian = false);

        /*! \brief Get the value of the angle in degrees
         *
         * \return The value of the angle
         *
         */
        Angle<T> asDegree() const;

        /*! \brief Get the value of the angle in radians
         *
         * \return Return the value of the angle
         *
         */
        Angle<T> asRadian() const;

        /*! \brief Normalize the angle
         *
         * @return This
         *
         */
        Angle<T>& normalize();

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        Angle<T> operator+(T right);

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        Angle<T>& operator+=(T right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        Angle<T> operator-(T right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        Angle<T>& operator-=(T right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        Angle<T> operator*(T right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        Angle<T>& operator*=(T right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        Angle<T> operator/(T right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        Angle<T>& operator/=(T right);

        /*! \brief Convert the angle to a numeric value
         *
         * \return Return the value of the angle
         *
         */
        explicit operator T() const;

    private:

        /*! \brief Constructor
         *
         * \param angle    The value of the angle
         * \param isRadian Whether the angle value is in radian
         *
         */
        Angle(T value, bool isRadian = false);

        T    m_value;
        bool m_isRadian;
    };

    typedef Angle<int>          AngleI;
    typedef Angle<float>        AngleF;
    typedef Angle<double>       AngleD;
    typedef Angle<unsigned int> AngleUI;

    template<typename T>
    Angle<T> Angle<T>::Zero = Angle<T>();
}

namespace std
{
    template<typename T>
    float cos(const Bull::Angle<T>& angle);

    template<typename T>
    float sin(const Bull::Angle<T>& angle);

    template<typename T>
    float tan(const Bull::Angle<T>& angle);
}

#include <Bull/Math/Angle.inl>

#endif // Bull_Angle_hpp
