namespace Bull
{
    /*! \brief Default constructor
     *
     */
    template<typename T>
    Quaternion<T>::Quaternion()
    {
        static_assert(std::is_floating_point<T>::value, "T must be a floating point type");

        set(0);
    }

    /*! \brief Constructor
     *
     * \param value The value to use to fill components
     *
     */
    template<typename T>
    Quaternion<T>::Quaternion(T value)
    {
        static_assert(std::is_floating_point<T>::value, "T must be a floating point type");

        set(value);
    }

    /*! \brief Constructor
     *
     * \param w The value of the w axis component
     * \param x The value of the x axis component
     * \param y The value of the y axis component
     * \param z The value of the z axis component
     *
     */
    template<typename T>
    Quaternion<T>::Quaternion(T w, T x, T y, T z)
    {
        static_assert(std::is_floating_point<T>::value, "T must be a floating point type");

        set(w, x, y, z);
    }

    /*! \brief Set the value of the Quaternion
     *
     * \param value The value of every components
     *
     * \return Return this
     *
     */
    template<typename T>
    Quaternion<T>& Quaternion<T>::set(T value)
    {
        w = value;
        x = value;
        y = value;
        z = value;

        return (*this);
    }

    /*! \brief Set the value of the Quaternion
     *
     * \param w The value of the w axis component
     * \param x The value of the x axis component
     * \param y The value of the y axis component
     * \param z The value of the z axis component
     *
     * \return Return this
     *
     */
    template<typename T>
    Quaternion<T>& Quaternion<T>::set(T w, T x, T y, T z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;

        return (*this);
    }

    /*! \brief Set the value of the Quaternion
     *
     * \param quat A Quaternion to copy
     *
     * \return Return this
     *
     */
    template<typename T>
    Quaternion<T>& Quaternion<T>::set(const Quaternion<T>& quat)
    {
        w = quat.w;
        x = quat.x;
        y = quat.y;
        z = quat.z;

        return (*this);
    }

    /*! \brief Compare two quaternions
     *
     * \param right The Quaternion to compare to this
     *
     * \return Return true if this and right are equal, false otherwise
     *
     */
    template<typename T>
    bool Quaternion<T>::operator==(const Quaternion<T>& right) const
    {
        return (w == right.w) &&
               (x == right.x) &&
               (y == right.y) &&
               (z == right.z);
    }

    /*! \brief Compare two quaternions
     *
     * \param right The Quaternion to compare to this
     *
     * \return Return true if this and right are not equal, false otherwise
     *
     */
    template<typename T>
    bool Quaternion<T>::operator!=(const Quaternion<T>& right) const
    {
        return !((*this) == right);
    }

    /*! \brief Multiply two Quaternions
     *
     * \param right The Quaternion to multiply to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>
    Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& right) const
    {
        return Quaternion<T>((*this)) *= right;
    }

    /*! \brief Multiply two Quaternions and affect the result to this
     *
     * \param right The Quaternion to multiply to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>
    Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& right)
    {
        Quaternion<T> product;

        product.w = w * right.w - x * right.x - y * right.y - z * right.z;
        product.x = w * right.x - x * right.w - y * right.z - z * right.y;
        product.y = w * right.y - x * right.z - y * right.w - z * right.x;
        product.z = w * right.z - x * right.y - y * right.x - z * right.w;

        return set(product);
    }
}
