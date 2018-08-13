#ifndef BULL_MATH_VECTOR_VECTOR2_HPP
#define BULL_MATH_VECTOR_VECTOR2_HPP

#include <Bull/Math/Vector/Vector.hpp>

namespace Bull
{
    template <typename T>
    struct Vector2 : public Vector<T, 2>
    {
        static Vector2<T> Zero;

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector2(T value = 0)
        {
            set(value, value);
        }

        /*! \brief Constructor
         *
         * \param x The X component
         * \param y The Y component
         *
         */
        Vector2(T x, T y)
        {
            set(x, y);
        }

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, std::size_t US>
        Vector2(const Vector<U, US>& copy) :
            Vector<T, 2>(copy)
        {
            /// Nothing
        }

        /*! \brief Set the Vector2
         *
         * \param x The X component
         * \param y The Y component
         *
         * \return This
         *
         */
        Vector2<T>& set(T x, T y)
        {
            this->x() = x;
            this->y() = y;

            return (*this);
        }

        /*! \brief Get the ratio of the Vector
         *
         * \return The ratio
         *
         */
        float getRatio() const
        {
            return static_cast<float>(x()) / static_cast<float>(y());
        }

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        T& x()
        {
            return this->at(0);
        }

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        const T& x() const
        {
            return this->at(0);
        }

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        T& y()
        {
            return this->at(1);
        }

        /*! \brief Get the X component
         *
         * \return The component
         *
         */
        const T& y() const
        {
            return this->at(1);
        }
    };

    template <typename T>
    Vector2<T> Vector2<T>::Zero = Vector2<T>();

    typedef Vector2<int> Vector2I;
    typedef Vector2<float> Vector2F;
    typedef Vector2<double> Vector2D;
    typedef Vector2<unsigned int> Vector2UI;
}

#endif // BULL_MATH_VECTOR_VECTOR2_HPP
