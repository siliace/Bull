#ifndef Bull_Quaternion_hpp
#define Bull_Quaternion_hpp

#include <cmath>
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
        template<typename U>
        Quaternion(U value);

        /*! \brief Constructor
         *
         * \param w The value of the w axis component
         * \param x The value of the x axis component
         * \param y The value of the y axis component
         * \param z The value of the z axis component
         *
         */
        template<typename U>
        Quaternion(U w, U x, U y, U z);

        /*! \brief Set the value of the Quaternion
         *
         * \param value The value of every components
         *
         * \return Return this
         *
         */
        template<typename U>
        Quaternion<T>& set(U value);

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
        template<typename U>
        Quaternion<T>& set(U w, U x, U y, U z);

        /*! \brief Set the value of the Quaternion
         *
         * \param quat A Quaternion to copy
         *
         * \return Return this
         *
         */
        template<typename U>
        Quaternion<T>& set(const Quaternion<U>& quat);

        /*! \brief Normalize the Quaternion
         *
         * \return Return this
         *
         */
        Quaternion<T>& normalize(T* length = nullptr);

        /*! \brief Get the magnitude of the quaternion
         *
         * \return Return magnitude
         *
         */
        T getMagnitude() const;

        /*! \brief Get the squared magnitude of the quaternion
         *
         * \return Return squared magnitude
         *
         */
        T getSquaredMagnitude() const;

        /*! \brief Compare two quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        template<typename U>
        bool operator==(const Quaternion<U>& right) const;

        /*! \brief Compare two quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return Return true if this and right are not equal, false otherwise
         *
         */
        template<typename U>
        bool operator!=(const Quaternion<U>& right) const;

        /*! \brief Multiply two Quaternions
         *
         * \param right The Quaternion to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>
        Quaternion<T> operator*(const Quaternion<U>& right) const;

        /*! \brief Multiply two Quaternions and affect the result to this
         *
         * \param right The Quaternion to multiply to this
         *
         * \return Return the product of this and right
         *
         */
        template<typename U>
        Quaternion<T>& operator*=(const Quaternion<U>& right);

        T w, x, y, z;
    };
}

#include <Bull/Math/Quaternion.inl>

#endif // Bull_Quaternion_hpp
