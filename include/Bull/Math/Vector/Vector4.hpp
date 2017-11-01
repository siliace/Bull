#ifndef BULL_MATH_VECTOR_VECTOR4_HPP
#define BULL_MATH_VECTOR_VECTOR4_HPP

#include <Bull/Math/Vector/Vector.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T>
    struct Vector4 : public Vector<T, 4>
    {
        static Vector4<T> Zero;

        static Vector4<T> Unit;

        /*! \brief Default constructor
         *
         */
        Vector4() = default;

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector4(T value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         * \param w The w component
         *
         */
        Vector4(T x, T y, T z, T w = 0);

        /*! \brief Constructor
         *
         * \param copy The X/Y/W components
         * \param w    The W component
         */
        Vector4(const Vector3<T>& copy, T w);

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, std::size_t US>
        Vector4(const Vector<U, US>& copy);

        /*! \brief Set the Vector3
         *
         * \param x The X component
         * \param y The Y component
         * \param z The Z component
         * \param w The W component
         *
         * \return This
         *
         */
        Vector4<T>& set(T x, T y, T z, T w = 0);

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

        /*! \brief Get the W component
         *
         * \return The component
         *
         */
        T& w();

        /*! \brief Get the W component
         *
         * \return The component
         *
         */
        const T& w() const;
    };

    template<typename T>
    Vector4<T> Vector4<T>::Zero = Vector4<T>(0, 0, 0, 0);

    template<typename T>
    Vector4<T> Vector4<T>::Unit = Vector4<T>(1, 1, 1, 1);

    typedef Vector4<int> Vector4I;
    typedef Vector4<float> Vector4F;
    typedef Vector4<double> Vector4D;
    typedef Vector4<unsigned int> Vector4UI;
}

#include <Bull/Math/Vector/Vector4.inl>

#endif // BULL_MATH_VECTOR_VECTOR4_HPP
