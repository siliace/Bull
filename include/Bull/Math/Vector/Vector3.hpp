#ifndef BULL_MATH_VECTOR_VECTOR3_HPP
#define BULL_MATH_VECTOR_VECTOR3_HPP

#include <Bull/Math/Vector/Vector.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct Vector3 : public Vector<T, 3>
    {
        static Vector3<T> Zero;

        static Vector3<T> Unit;
        static Vector3<T> UnitX;
        static Vector3<T> UnitY;
        static Vector3<T> UnitZ;

        static Vector3<T> Left;
        static Vector3<T> Right;

        static Vector3<T> Up;
        static Vector3<T> Down;

        static Vector3<T> Forward;
        static Vector3<T> Backward;

        /*! \brief Compute the crossProduct of two Vector3
         *
         * \param left
         * \param right
         *
         * \return The normal Vector3
         *
         */
        static Vector3<T> crossProduct(const Vector3<T>& left, const Vector3<T>& right);

        /*! \brief Default constructor
         *
         */
        Vector3() = default;

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector3(T value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         *
         */
        Vector3(T x, T y, T z);

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, Index US>
        Vector3(const Vector<U, US>& copy);

        /*! \brief Set the Vector3
         *
         * \param x The X component
         * \param y The Y component
         * \param z The Z component
         *
         * \return This
         *
         */
        Vector3<T>& set(T x, T y, T z);

        /*! \brief Compute the cross product of two Vector3
         *
         * \param right The other Vector3 to compute the cross product with
         *
         * \return This
         *
         */
        Vector3<T>& crossProduct(const Vector3<T>& right);

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        T& x();

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        const T& x() const;

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        T& y();

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        const T& y() const;

        /*! \brief Get the Z component
         *
         * \return The component
         *
         */
        T& z();

        /*! \brief Get the Z component
         *
         * \return The component
         *
         */
        const T& z() const;
    };

    template<typename T>
    Vector3<T> Vector3<T>::Zero = Vector3<T>(0, 0, 0);

    template<typename T>
    Vector3<T> Vector3<T>::Unit  = Vector3<T>(1, 1, 1);

    template<typename T>
    Vector3<T> Vector3<T>::UnitX = Vector3<T>(1, 0, 0);

    template<typename T>
    Vector3<T> Vector3<T>::UnitY = Vector3<T>(0, 1, 0);

    template<typename T>
    Vector3<T> Vector3<T>::UnitZ = Vector3<T>(0, 0, 1);

    template<typename T>
    Vector3<T> Vector3<T>::Left  = Vector3<T>(-1, 0, 0);

    template<typename T>
    Vector3<T> Vector3<T>::Right = Vector3<T>(1, 0, 0);

    template<typename T>
    Vector3<T> Vector3<T>::Up   = Vector3<T>(0, 1, 0);

    template<typename T>
    Vector3<T> Vector3<T>::Down = Vector3<T>(0, -1, 0);

    template<typename T>
    Vector3<T> Vector3<T>::Forward  = Vector3<T>(0, 0, 1);

    template<typename T>
    Vector3<T> Vector3<T>::Backward = Vector3<T>(0, 0, -1);

    typedef Vector3<int> Vector3I;
    typedef Vector3<float> Vector3F;
    typedef Vector3<double> Vector3D;
    typedef Vector3<unsigned int> Vector3UI;
}

#include <Bull/Math/Vector/Vector3.inl>

#endif // BULL_MATH_VECTOR_VECTOR3_HPP
