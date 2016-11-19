namespace Bull
{
    /*! \brief Calculate the dot(scalar) product of two Vector3
     *
     * \param left  The left Vector3 of the product
     * \param right The right Vector3 of the product
     *
     * \return The value of the dot product of left and right
     *
     */
    template<typename T>
    T Vector3<T>::dotProduct(const Vector3& left, const Vector3& right)
    {
        return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
    }

    /*! \brief Default constructor
     *
     */
    template<typename T>
    Vector3<T>::Vector3() :
        x(0),
        y(0),
        z(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param value The value of all components
     *
     */
    template<typename T>
    Vector3<T>::Vector3(T value) :
        x(value),
        y(value),
        z(value)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param x The x component
     * \param y The y component
     * \param z The z component
     *
     */
    template<typename T>
    Vector3<T>::Vector3(T x, T y, T z) :
        x(x),
        y(y),
        z(z)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param copy The vector to copy
     * \param z The z component
     *
     */
    template<typename T>
    Vector3<T>::Vector3(const Vector2<T>& copy, T z) :
        x(copy.x),
        y(copy.y),
        z(z)
    {
        /// Nothing
    }

    /*! \brief Compute the length
     *
     * \return Return the length of the vector
     *
     */
    template<typename T>
    float Vector3<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
    }

    /*! \brief Calculate the dot(scalar) product of two vectors
     *
     * \param right The other to calculate the dot product with
     *
     * \return The value of the dot product
     *
     */
    template<typename T>
    T Vector3<T>::dotProduct(const Vector3& right)
    {
        return (x * right.x) + (y * right.y) + (z * right.z);
    }

    /*! \brief == operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are equal, else return false
     *
     */
    template<typename T>
    bool Vector3<T>::operator==(const Vector3& right) const
    {
        return (x == right.x) && (y == right.y) && (z == right.z);
    }

    /*! \brief != operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are not equal, else return false
     *
     */
    template<typename T>
    bool Vector3<T>::operator!=(const Vector3& right) const
    {
        return !((*this) == right);
    }

    /*! \brief += operator override
     *
     * \param right The vector to add
     *
     * \return Return this after addition
     *
     */
    template<typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;

        return (*this);
    }

    /*! \brief Negation operator
     *
     * \return Return the opposite of this Vector3
     *
     */
    template<typename T>
    Vector3<T> Vector3<T>::operator-() const
    {
        return Vector3<T>(-x, -y, -z);
    }

    /*! \brief -= operator override
     *
     * \param right The vector to subtract
     *
     * \return Return this after subtraction
     *
     */
    template<typename T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;

        return (*this);
    }

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
    {
        return Vector3<T>(left) += right;
    }

    /*! \brief Addition two Vector3
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(float left, const Vector3<T>& right)
    {
        return Vector3<T>(left) += right;
    }

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, float right)
    {
        return Vector3<T>(left) += Vector3<T>(right);
    }

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
    {
        return Vector3<T>(left) -= right;
    }

    /*! \brief Subtract two Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(float left, const Vector3<T>& right)
    {
        return Vector3<T>(left) -= right;
    }

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, float right)
    {
        return Vector3<T>(left) -= Vector3<T>(right);
    }
}
