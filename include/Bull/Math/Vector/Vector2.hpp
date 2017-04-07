#ifndef Bull_Vector2_hpp
#define Bull_Vector2_hpp

#include <cmath>

namespace Bull
{
    template<typename T>
    struct Vector2
    {
        /*! \brief Get a normalized Vector2
         *
         * \param vector The Vector2 to normalize
         *
         * \return The normalized Vector2
         *
         */
        static Vector2<T> normalize(const Vector2<T>& vector);

        /*! \brief Computer the dot product of two Vector2
         *
         * \param left  The left Vector2 of the product
         * \param right The right Vector2 of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static T dotProduct(const Vector2<T>& left, const Vector2<T>& right);

        /*! \brief Default constructor
         *
         */
        Vector2();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        Vector2(T value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         *
         */
        Vector2(T x, T y);

        /*! \brief Set the Vector2
         *
         * \param value The value of all components
         *
         * \return This
         *
         */
        Vector2<T>& set(T value);

        /*! \brief Set the Vector2
         *
         * \param x The x component
         * \param y The y component
         *
         * \return This
         *
         */
        Vector2<T>& set(T x, T y);

        /*! \brief Set the Vector2
         *
         * \param copy The Vector2 to copy
         *
         * \return This
         *
         */
        Vector2<T>& set(const Vector2<T>& copy);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Normalize the Vector2
         *
         * \return This
         *
         */
        Vector2<T>& normalize();

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        T dotProduct(const Vector2& right);

        /*! \brief == operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector2& right) const;

        /*! \brief != operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector2& right) const;

        /*! \brief += operator override
         *
         * \param right The vector to add
         *
         * \return Return this after addition
         *
         */
        Vector2& operator+=(const Vector2& right);

        /*! \brief Negation operator
         *
         * \return Return the opposite of this Vector
         *
         */
        Vector2 operator-() const;

        /*! \brief -= operator override
         *
         * \param right The vector to subtract
         *
         * \return Return this after subtraction
         *
         */
        Vector2& operator-=(const Vector2& right);

        T x, y;

    };

    /*! \brief Addition two Vector2
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);

    /*! \brief Addition a scalar with a Vector2
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator+(T left, const Vector2<T>& right);

    /*! \brief Addition a scalar with a Vector2
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator+(const Vector2<T>& left, T right);

    /*! \brief Subtract two Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);

    /*! \brief Subtract a scalar with a Vector2
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator-(T left, const Vector2<T>& right);

    /*! \brief Subtract a scalar with a Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, T right);

    /*! \brief Multiply a scalar with a Vector2
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator*(T left, const Vector2<T>& right);

    /*! \brief Multiply a scalar with a Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator*(const Vector2<T>& left, T right);

    /*! \brief Divide a scalar with a Vector2
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator/(T left, const Vector2<T>& right);

    /*! \brief Divide a scalar with a Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector2<T> operator/(const Vector2<T>& left, T right);

    typedef Vector2<int> Vector2I;
    typedef Vector2<float> Vector2F;
    typedef Vector2<double> Vector2D;
    typedef Vector2<unsigned int> Vector2UI;
}

#include <Bull/Math/Vector/Vector2.inl>

#endif // Bull_Vector2_hpp
