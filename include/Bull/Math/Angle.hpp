#ifndef Bull_Angle_hpp
#define Bull_Angle_hpp

#include <cmath>
#include <functional>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Constants.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Angle
    {
    public:

        /*! \brief Create an angle in radians
         *
         * \param angle The value in radians of the angle to create
         *
         * \return Return the created angle
         *
         */
        template<typename U>
        static Angle<T> radian(U angle);

        /*! \brief Create an angle in degrees
         *
         * \param angle The value in degrees of the angle to create
         *
         * \return Return the created angle
         *
         */
        template<typename U>
        static Angle<T> degree(U angle);

        static constexpr Angle<T> Zero = Angle();

    public:

        /*! \brief Default constructor
         *
         */
        Angle();

        /*! \brief Constructor
         *
         * \param angle
         * \param isRadian
         *
         */
        template<typename U>
        Angle(U value, bool isRadian = false);

        /*! \brief Copy constructor
         *
         * \param copy The angle to copy
         *
         */
        template<typename U>
        Angle(const Angle<U>& copy);

        /*! \brief Basic assignment operator
         *
         * \param angle The value of the angle
         *
         * \return Return this
         *
         */
        template<typename U>
        Angle& operator=(Angle<U> angle);

        /*! \brief Basic assignment operator
         *
         * \param angle The value of the angle
         *
         * \return Return this
         *
         */
        template<typename U>
        Angle& operator=(U angle);

        /*! \brief Set the value of the angle
         *
         * \param angle The value of the angle
         *
         * \return Return this
         *
         */
        template<typename U>
        Angle& set(Angle<U> angle);

        /*! \brief Set the value of the angle
         *
         * \param angle The value of the angle
         *
         * \return Return this
         *
         */
        template<typename U>
        Angle& set(U angle);

        /*! \brief Get the value of the angle in degrees
         *
         * \return Return the value of the angle
         *
         */
        Angle<T> asDegree() const;

        /*! \brief Get the value of the angle in radians
         *
         * \return Return the value of the angle
         *
         */
        Angle<T> asRadian() const;

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        template<typename U>
        Angle<T> operator+(U right);

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        template<typename U>
        Angle<T> operator+(const Angle<U>& right);

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        template<typename U>        Angle<T>& operator+=(U right);

        /*! \brief Addition two angles
         *
         * \param right The angle to add to this
         *
         * \return Return the sum of this and right
         *
         */
        template<typename U>
        Angle<T>& operator+=(const Angle<U>& right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        template<typename U>
        Angle<T> operator-(U right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        template<typename U>
        Angle<T> operator-(const Angle<U>& right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        template<typename U>        Angle<T>& operator-=(U right);

        /*! \brief Subtract two angles
         *
         * \param right The angle to subtract to this
         *
         * \return Return the difference of this and right
         *
         */
        template<typename U>
        Angle<T>& operator-=(const Angle<U>& right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>
        Angle<T> operator*(U right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>
        Angle<T> operator*(const Angle<U>& right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>        Angle<T>& operator*=(U right);

        /*! \brief Multiply two angles
         *
         * \param right The angle to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>
        Angle<T>& operator*=(const Angle<U>& right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        template<typename U>
        Angle<T> operator/(U right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        template<typename U>
        Angle<T> operator/(const Angle<U>& right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        template<typename U>        Angle<T>& operator/=(U right);

        /*! \brief Divide two angles
         *
         * \param right The angle to divide to this
         *
         * \return Return the quotient of this and right
         *
         */
        template<typename U>
        Angle<T>& operator/=(const Angle<U>& right);

        /*! \brief Convert the angle to a numeric value
         *
         * \return Return the value of the angle
         *
         */
        operator T() const;

    private:

        T    m_value;
        bool m_isRadian;
    };

    typedef Angle<int>          AngleI;
    typedef Angle<float>        AngleF;
    typedef Angle<double>       AngleD;
    typedef Angle<unsigned int> AngleUI;
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
