#ifndef BULL_MATH_VECTOR_VECTOR_HPP
#define BULL_MATH_VECTOR_VECTOR_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>
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
        static Vector<T, S> normalize(const Vector<T, S>& vector);

        /*! \brief Computer the dot product of two Vector
         *
         * \param left  The left Vector of the product
         * \param right The right Vector of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static T dotProduct(const Vector<T, S>& left, const Vector<T, S>& right);

    public:

        /*! \brief Default constructor
         *
         */
        Vector();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        explicit Vector(T value);

        /*! \brief Copy constructor
         *
         * \param copy The Vector to copy
         *
         */
        template <typename U, std::size_t US>
        explicit Vector(const Vector<U, US>& copy);

        /*! \brief Basic assignment operator
         *
         * \param copy The Vector to copy
         *
         * \return This
         *
         */
        template <typename U, std::size_t US>
        Vector<T, S>& operator=(const Vector<U, US>& copy);

        /*! \brief Set the value of the Vector
         *
         * \param value The value
         *
         * \return This
         *
         */
        Vector<T, S>& set(T value);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Normalize the Vector
         *
         * \return This
         *
         */
        Vector<T, S>& normalize();

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        T dotProduct(const Vector<T, S>& right) const;

        /*! \brief == operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector<T, S>& right) const;

        /*! \brief != operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector<T, S>& right) const;

        /*! \brief Get a coordinate
         *
         * \param index The index of the coordinate to get
         *
         * \return The coordinate
         *
         */
        T& at(std::size_t index);

        /*! \brief Get a coordinate
         *
         * \param index The index of the coordinate to get
         *
         * \return The coordinate
         *
         */
        const T& at(std::size_t index) const;

        Vector<T, S> operator-() const;

        Vector<T, S>& operator+=(T right);

        Vector<T, S>& operator+=(const Vector<T, S>& right);

        Vector<T, S>& operator-=(T right);

        Vector<T, S>& operator-=(const Vector<T, S>& right);

        Vector<T, S>& operator*=(T right);

        Vector<T, S>& operator*=(const Vector<T, S>& right);

        Vector<T, S>& operator/=(T right);

        Vector<T, S>& operator/=(const Vector<T, S>& right);

    private:

        std::array<T, S> m_components; /*!< Components of the Vector */
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator+(T left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, T right);

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator-(T left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, T right);

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator*(T left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, T right);

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator/(T left, const Vector<T, S>& right);

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, T right);
}

#include <Bull/Math/Vector/Vector.inl>

#endif // BULL_MATH_VECTOR_VECTOR_HPP
