#ifndef BULL_MATH_VECTOR_VECTOR_HPP
#define BULL_MATH_VECTOR_VECTOR_HPP

#include <array>
#include <cmath>

#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    template <typename T, std::size_t S>
    class Vector
    {
    public:

        /*! \brief Get a normalized Vector
         *
         * \param vector The Vector to normalize
         *
         * \return The normalized Vector
         *
         */
        static Vector<T, S> normalize(const Vector<T, S>& vector)
        {
            return Vector<T, S>(vector).normalize();
        }

        /*! \brief Computer the dot product of two Vector
         *
         * \param left  The left Vector of the product
         * \param right The right Vector of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static T dotProduct(const Vector<T, S>& left, const Vector<T, S>& right)
        {
            return Vector<T, S>(left).dotProduct(right);
        }

    public:

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector(T value = 0)
        {
            m_components.fill(value);
        }

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, std::size_t US>
        explicit Vector(const Vector<U, US>& copy) :
            Vector<T, S>()
        {
            for(std::size_t i = 0; i < std::min(S, US); i++)
            {
                at(i) = static_cast<T>(copy.at(i));
            }
        }

        /*! \brief Basic assignment operator
         *
         * \param copy The Vector to copy
         *
         * \return This
         *
         */
        template <typename U, std::size_t US>
        Vector<T, S>& operator=(const Vector<U, US>& copy)
        {
            m_components.fill(0);

            for(std::size_t i = 0; i < std::min(S, US); i++)
            {
                at(i) = static_cast<T>(copy.at(i));
            }

            return (*this);
        }

        /*! \brief Set the value of the Vector
         *
         * \param value The value
         *
         * \return This
         *
         */
        Vector<T, S>& set(T value)
        {
            m_components.fill(value);

            return (*this);
        }

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const
        {
            float length = 0;

            for(T component : m_components)
            {
                length += std::pow(component, 2);
            }

            return std::sqrt(length);
        }

        /*! \brief Normalize the Vector
         *
         * \return This
         *
         */
        Vector<T, S>& normalize()
        {
            float length = getLength();

            if(length > 1.f)
            {
                for(T& component : m_components)
                {
                    component /= length;
                }
            }

            return (*this);
        }

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        T dotProduct(const Vector<T, S>& right) const
        {
            float sum = 0;

            for(std::size_t i = 0; i < S; i++)
            {
                sum += at(i) * right.at(i);
            }

            return sum;
        }

        /*! \brief == operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector<T, S>& right) const
        {
            return m_components == right.m_components;
        }

        /*! \brief != operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector<T, S>& right) const
        {
            return m_components != right.m_components;
        }

        /*! \brief Get a coordinate
         *
         * \param index The index of the coordinate to get
         *
         * \return The coordinate
         *
         */
        T& at(std::size_t index)
        {
            RangeCheck(index, S);

            return m_components.at(index);
        }

        /*! \brief Get a coordinate
         *
         * \param index The index of the coordinate to get
         *
         * \return The coordinate
         *
         */
        const T& at(std::size_t index) const
        {
            RangeCheck(index, S);

            return m_components.at(index);
        }

        /*! \brief Negation operator
         *
         * \return The negated Vector
         *
         */
        Vector<T, S> operator-() const
        {
            Vector<T, S> negation;

            for(std::size_t i = 0; i < S; i++)
            {
                negation.at(i) = -at(i);
            }

            return negation;
        };

        /*! \brief Addition a Vector and a scalar
         *
         * \param right The scalar to add to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator+=(T right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) += right;
            }

            return (*this);
        }

        /*! \brief Addition two Vector
         *
         * \param right The scalar to add to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator+=(const Vector<T, S>& right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) += right.at(i);
            }

            return (*this);
        }

        /*! \brief Subtract a Vector and a scalar
         *
         * \param right The scalar to subtract to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator-=(T right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) -= right;
            }

            return (*this);
        }

        /*! \brief Subtract two Vector
         *
         * \param right The Vector to subtract to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator-=(const Vector<T, S>& right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) -= right.at(i);
            }

            return (*this);
        }

        /*! \brief Multiply a Vector and a scalar
         *
         * \param right The scalar to multiply to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator*=(T right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) *= right;
            }

            return (*this);
        }

        /*! \brief Multiply two Vector
         *
         * \param right The Vector to multiply to this
         *
         * \return This
         *
         */
        Vector<T, S>& operator*=(const Vector<T, S>& right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) *= right.at(i);
            }

            return (*this);
        }

        /*! \brief Divide a Vector and a scalar
         *
         * \param right The scalar to divide with this
         *
         * \return This
         *
         */
        Vector<T, S>& operator/=(T right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) /= right;
            }

            return (*this);
        }

        /*! \brief Divide two Vector
         *
         * \param right The Vector to divide with this
         *
         * \return This
         *
         */
        Vector<T, S>& operator/=(const Vector<T, S>& right)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                at(i) /= right.at(i);
            }

            return (*this);
        }

    private:

        std::array<T, S> m_components; /*!< Components of the Vector */
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) /= right;
    };
}

#endif // BULL_MATH_VECTOR_VECTOR_HPP
