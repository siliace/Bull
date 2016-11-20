#ifndef Bull_Quaternion_hpp
#define Bull_Quaternion_hpp

#include <functional>

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Quaternion
    {
        /*! \brief Default constructor
         *
         */
        Quaternion();

        /*! \brief Constructor
         *
         * \param value The value to use to fill components
         *
         */
        Quaternion(T value);

        /*! \brief Constructor
         *
         * \param w The value of the w axis component
         * \param x The value of the x axis component
         * \param y The value of the y axis component
         * \param z The value of the z axis component
         *
         */
        Quaternion(T w, T x, T y, T z);

        /*! \brief Set the value of the Quaternion
         *
         * \param value The value of every components
         *
         * \return Return this
         *
         */
        Quaternion<T>& set(T value);

        /*! \brief Set the value of the Quaternion
         *
         * \param w The value of the w axis component
         * \param x The value of the x axis component
         * \param y The value of the y axis component
         * \param z The value of the z axis component
         *
         * \return Return this
         *
         */
        Quaternion<T>& set(T w, T x, T y, T z);

        /*! \brief Set the value of the Quaternion
         *
         * \param quat A Quaternion to copy
         *
         * \return Return this
         *
         */
        Quaternion<T>& set(const Quaternion<T>& quat);

        /*! \brief Compare two quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        bool operator==(const Quaternion<T>& right) const;

        /*! \brief Compare two quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return Return true if this and right are not equal, false otherwise
         *
         */
        bool operator!=(const Quaternion<T>& right) const;

        /*! \brief Multiply two Quaternions
         *
         * \param right The Quaternion to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        Quaternion<T> operator*(const Quaternion<T>& right) const;

        /*! \brief Multiply two Quaternions and affect the result to this
         *
         * \param right The Quaternion to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        Quaternion<T>& operator*=(const Quaternion<T>& right);

        T w, x, y, z;
    };
}

#include <Bull/Math/Quaternion.inl>

#endif // Bull_Quaternion_hpp
