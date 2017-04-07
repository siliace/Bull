#ifndef Bull_Vector3_hpp
#define Bull_Vector3_hpp

#include <cmath>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Vector3
    {
        /*! \brief Make a zero Vector3 (0.0, 0.0, 0.0)
         *
         * \return The zero Vector3
         *
         */
        static Vector3<T> makeZero();

        /*! \brief Make an unit Vector3 (1.0, 1.0, 1.0)
         *
         * \return The unit Vector3
         *
         */
        static Vector3<T> makeUnit();

        /*! \brief Make a X unit Vector3 (1.0, 0.0, 0.0)
         *
         * \return The X unit Vector3
         *
         */
        static Vector3<T> makeUnitX();

        /*! \brief Make a Y unit Vector3 (0.0, 1.0, 0.0)
         *
         * \return The Y unit Vector3
         *
         */
        static Vector3<T> makeUnitY();

        /*! \brief Make a Z unit Vector3 (0.0, 0.0, 1.0)
         *
         * \return The Z unit Vector3
         *
         */
        static Vector3<T> makeUnitZ();

        static Vector3<T> makeLeft();

        static Vector3<T> makeRight();

        static Vector3<T> makeUp();

        static Vector3<T> makeDown();

        static Vector3<T> makeForward();

        static Vector3<T> makeBackward();

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
        T dotProduct(const Vector3<T>& right);

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

        /*! \brief Negation operator
         *
         * \return Return the opposite of this Vector
         *
         */
        Vector3 operator-() const;

        /*! \brief -= operator override
         *
         * \param right The vector to subtract
         *
         * \return Return this after subtraction
         *
         */
        Vector3& operator-=(const Vector3& right);

        T x, y, z;
    };

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
    Vector3<T> operator+(float left, const Vector3<T>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, float right);

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
    Vector3<T> operator-(float left, const Vector3<T>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, float right);

    typedef Vector3<int> Vector3I;
    typedef Vector3<float> Vector3F;
    typedef Vector3<double> Vector3D;
    typedef Vector3<unsigned int> Vector3UI;
}

#include <Bull/Math/Vector/Vector3.inl>

#endif // Bull_Vector3_hpp
