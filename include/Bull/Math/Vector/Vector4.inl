namespace Bull
{
    /*! \brief Calculate the dot(scalar) product of two Vector4
     *
     * \param left  The left Vector4 of the product
     * \param right The right Vector4 of the product
     *
     * \return The value of the dot product of left and right
     *
     */
    template<typename T>
    T Vector4<T>::dotProduct(const Vector4& left, const Vector4& right)
    {
        return (left.x * right.x) + (left.y * right.y) + (left.z * right.z) + (left.w * right.w);
    }

    /*! \brief Default constructor
     *
     */
    template<typename T>
    Vector4<T>::Vector4() :
        x(0),
        y(0),
        z(0),
        w(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param value The value of all components
     *
     */
    template<typename T>
    Vector4<T>::Vector4(T value) :
        x(value),
        y(value),
        z(value),
        w(value)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param x The x component
     * \param y The y component
     * \param z The z component
     * \param w The w component
     *
     */
    template<typename T>
    Vector4<T>::Vector4(T x, T y, T z, T w) :
        x(x),
        y(y),
        z(z),
        w(w)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param copy The vector to copy
     * \param w The w component
     *
     */
    template<typename T>
    Vector4<T>::Vector4(const Vector3<T>& copy, T w) :
        x(copy.x),
        y(copy.y),
        z(copy.z),
        w(w)
    {
        /// Nothing
    }

    /*! \brief Compute the length
     *
     * \return Return the length of the vector
     *
     */
    template<typename T>
    float Vector4<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w, 2));
    }

    /*! \brief Calculate the dot(scalar) product of two vectors
     *
     * \param right The other to calculate the dot product with
     *
     * \return The value of the dot product
     *
     */
    template<typename T>
    T Vector4<T>::dotProduct(const Vector4& right)
    {
        return (x * right.x) + (y * right.y) + (z * right.z) + (w * right.w);
    }

    /*! \brief == operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are equal, else return false
     *
     */
    template<typename T>
    bool Vector4<T>::operator==(const Vector4& right) const
    {
        return (x == right.x) && (y == right.y) && (z == right.z) && (w == right.w);
    }

    /*! \brief != operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are not equal, else return false
     *
     */
    template<typename T>
    bool Vector4<T>::operator!=(const Vector4& right) const
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
    Vector4<T>& Vector4<T>::operator+=(const Vector4& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;
        w += right.w;

        return (*this);
    }

    /*! \brief Negation operator
     *
     * \return Return the opposite of this Vector4
     *
     */
    template<typename T>
    Vector4<T> Vector4<T>::operator-() const
    {
        return Vector4<T>(-x, -y, -z, -w);
    }

    /*! \brief -= operator override
     *
     * \param right The vector to subtract
     *
     * \return Return this after subtraction
     *
     */
    template<typename T>
    Vector4<T>& Vector4<T>::operator-=(const Vector4& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;
        w -= right.w;

        return (*this);
    }

    /*! \brief Addition two Vector4
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector4<T> operator+(const Vector4<T>& left, const Vector4<T>& right)
    {
        return Vector4<T>(left) += right;
    }

    /*! \brief Addition two Vector4
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector4<T> operator+(float left, const Vector4<T>& right)
    {
        return Vector4<T>(left) += right;
    }

    /*! \brief Addition two Vector4
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector4<T> operator+(const Vector4<T>& left, float right)
    {
        return Vector4<T>(left) += Vector4<T>(right);
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename T>
    Vector4<T> operator-(const Vector4<T>& left, const Vector4<T>& right)
    {
        return Vector4<T>(left) -= right;
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector4<T> operator-(float left, const Vector4<T>& right)
    {
        return Vector4<T>(left) -= right;
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector4<T> operator-(const Vector4<T>& left, float right)
    {
        return Vector4<T>(left) -= Vector4<T>(right);
    }
}
