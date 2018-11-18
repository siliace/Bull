#ifndef BULL_MATH_VECTOR_VECTOR4_HPP
#define BULL_MATH_VECTOR_VECTOR4_HPP

#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Vector/Vector.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T>
    class Vector4 : public Vector<T, 4>
    {
    public:

        static Vector4<T> Zero;

        static Vector4<T> Unit;

        /*! \brief Create a Vector4 from a Color
         *
         * \param color The color
         *
         * \return The created Vector4
         *
         */
        static Vector4<T> makeFromColor(const Color& color)
        {
            return Vector4<T>(
                    static_cast<T>(color.red)   / 255,
                    static_cast<T>(color.green) / 255,
                    static_cast<T>(color.blue)  / 255,
                    static_cast<T>(color.alpha) / 255
            );
        }

    public:

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector4(T value = 0)
        {
            set(value, value, value, value);
        }

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         * \param w The w component
         *
         */
        Vector4(T x, T y, T z, T w = 0)
        {
            set(x, y, z, w);
        }

        /*! \brief Constructor
         *
         * \param copy The X/Y/W components
         * \param w    The W component
         */
        Vector4(const Vector3<T>& copy, T w) :
            Vector<T, 4>(copy)
        {
            this->w() = w;
        }

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, std::size_t US>
        Vector4(const Vector<U, US>& copy) :
            Vector<T, 4>(copy)
        {
            /// Nothing
        }

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
        Vector4<T>& set(T x, T y, T z, T w = 0)
        {
            this->x() = x;
            this->y() = y;
            this->z() = z;
            this->w() = w;

            return (*this);
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

        /*! \brief Get the Z component
         *
         * \return The component
         *
         */
        T& z()
        {
            return this->at(2);
        }

        /*! \brief Get the Z component
         *
         * \return The component
         *
         */
        const T& z() const
        {
            return this->at(2);
        }

        /*! \brief Get the W component
         *
         * \return The component
         *
         */
        T& w()
        {
            return this->at(3);
        }

        /*! \brief Get the W component
         *
         * \return The component
         *
         */
        const T& w() const
        {
            return this->at(3);
        }
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

#endif // BULL_MATH_VECTOR_VECTOR4_HPP
