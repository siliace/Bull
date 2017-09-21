#ifndef BULL_MATH_VECTOR_VECTOR2_HPP
#define BULL_MATH_VECTOR_VECTOR2_HPP

#include <Bull/Math/Vector/Vector.hpp>

namespace Bull
{
    template <typename T>
    struct Vector2 : public Vector<T, 2>
    {
        static Vector2<T> Zero;

        /*! \brief Default constructor
         *
         */
        Vector2() = default;

        /*! \brief Constructor
         *
         * \param x The X component
         * \param y The Y component
         *
         */
        Vector2(T x, T y);

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, Index US>
        Vector2(const Vector<U, US>& copy);

        /*! \brief Set the Vector2
         *
         * \param x The X component
         * \param y The Y component
         *
         * \return This
         *
         */
        Vector2<T>& set(T x, T y);

        /*! \brief Get the ratio of the Vector
         *
         * \return The ratio
         *
         */
        float getRatio() const;

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
    };

    template <typename T>
    Vector2<T> Vector2<T>::Zero = Vector2<T>();

    typedef Vector2<int> Vector2I;
    typedef Vector2<float> Vector2F;
    typedef Vector2<double> Vector2D;
    typedef Vector2<unsigned int> Vector2UI;
}

#include <Bull/Math/Vector/Vector2.inl>

#endif // BULL_MATH_VECTOR_VECTOR2_HPP
