#ifndef BULL_VECTOR3_HPP
#define BULL_VECTOR3_HPP

#include <cmath>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct Vector3
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

        /*! \brief Get a normalized Vector3
         *
         * \param vector The Vector3 to normalize
         *
         * \return The normalized Vector3
         *
         */
        static Vector3<T> normalize(const Vector3<T>& vector);

        /*! \brief Calculate the dot(scalar) product of two Vector3
         *
         * \param left  The left Vector3 of the product
         * \param right The right Vector3 of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static T dotProduct(const Vector3<T>& left, const Vector3<T>& right);

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
        Vector3();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        Vector3(T value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         *
         */
        Vector3(T x, T y, T z);

        /*! \brief Constructor
         *
         * \param copy The vector to copy
         * \param z    The z component
         *
         */
        Vector3(const Vector2<T>& copy, T z = 0);

        /*! \brief Set the Vector3
         *
         * \param value The value of all components
         *
         * \return This
         *
         */
        Vector3<T>& set(T value);

        /*! \brief Set the Vector3
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         *
         * \return This
         *
         */
        Vector3<T>& set(T x, T y, T z);

        /*! \brief Set the Vector3
         *
         * \param copy The Vector3 to copy
         *
         * \return This
         *
         */
        Vector3<T>& set(const Vector3<T>& copy);

        /*! \brief Set the Vector3
         *
         * \param copy The vector to copy
         * \param z    The z component
         *
         * \return This
         *
         */
        Vector3<T>& set(const Vector2<T>& copy, T z);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Normalize the Vector3
         *
         * \return This
         *
         */
        Vector3<T>& normalize();

        /*! \brief Compute the dot product of two Vector3
         *
         * \param right The other Vector3 to computer the dot product with
         *
         * \return This
         *
         */
        T dotProduct(const Vector3<T>& right) const;

        /*! \brief Compute the cross product of two Vector3
         *
         * \param right The other Vector3 to compute the cross product with
         *
         * \return This
         *
         */
        Vector3<T>& crossProduct(const Vector3<T>& right);

        /*! \brief == operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector3& right) const;

        /*! \brief != operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector3& right) const;

        /*! \brief += operator override
         *
         * \param right The vector to add
         *
         * \return Return this after addition
         *
         */
        Vector3& operator+=(const Vector3& right);

        Vector3& operator-=(const Vector3& right);

        Vector3& operator*=(const Vector3& right);

        Vector3& operator/=(const Vector3& right);

        /*! \brief Negation operator
         *
         * \return Return the opposite of this Vector
         *
         */
        Vector3 operator-() const;

        T x, y, z;
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

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(T left, const Vector3<T>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, T right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(T left, const Vector3<T>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, T right);

    /*! \brief Multiply a scalar with a Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator*(T left, const Vector3<T>& right);

    /*! \brief Multiply a scalar with a Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator*(const Vector3<T>& left, T right);

    /*! \brief Divide a scalar with a Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator/(T left, const Vector3<T>& right);

    /*! \brief Divide a scalar with a Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator/(const Vector3<T>& left, T right);

    typedef Vector3<int> Vector3I;
    typedef Vector3<float> Vector3F;
    typedef Vector3<double> Vector3D;
    typedef Vector3<unsigned int> Vector3UI;
}

#include <Bull/Math/Vector/Vector3.inl>

#endif // BULL_VECTOR3_HPP
