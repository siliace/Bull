namespace Bull
{
    /*! \brief Default constructor
     *
     */
    template<typename T>
    Quaternion<T>::Quaternion()
    {
        static_assert(std::is_floating_point<T>::value, "T must be a floating point type");

        set(0.0);
    }

    /*! \brief Constructor
     *
     * \param value The value to use to fill components
     *
     */
    template<typename T>
    template<typename U>
    Quaternion<T>::Quaternion(U value)
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
    template<typename U>
    Quaternion<T>::Quaternion(U w, U x, U y, U z)
    {
        static_assert(std::is_floating_point<T>::value, "T must be a floating point type");

        set(w, x, y, z);
    }

    /*! \brief Constructor
     *
     * \param angles The EulerAngles to use create the Quaternion
     *
     */
    template<typename T>
    template<typename U>
    Quaternion<T>::Quaternion(const EulerAngles<U>& copy)
    {
        set(copy);
    }

    /*! \brief Set the value of the Quaternion
     *
     * \param value The value of every components
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Quaternion<T>& Quaternion<T>::set(U value)
    {
        w = static_cast<T>(value);
        x = static_cast<T>(value);
        y = static_cast<T>(value);
        z = static_cast<T>(value);

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
    template<typename U>
    Quaternion<T>& Quaternion<T>::set(U w, U x, U y, U z)
    {
        this->w = static_cast<T>(w);
        this->x = static_cast<T>(x);
        this->y = static_cast<T>(y);
        this->z = static_cast<T>(z);

        return (*this);
    }

    /*! \brief Constructor
     *
     * \param angles The EulerAngles to use create the Quaternion
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Quaternion<T>& Quaternion<T>::set(const EulerAngles<U>& angles)
    {
        T cosYaw   = std::cos(static_cast<T>(angles.yaw)   * static_cast<T>(0.5));
        T sinYaw   = std::sin(static_cast<T>(angles.yaw)   * static_cast<T>(0.5));
        T cosRoll  = std::cos(static_cast<T>(angles.roll)  * static_cast<T>(0.5));
        T sinRoll  = std::sin(static_cast<T>(angles.roll)  * static_cast<T>(0.5));
        T cosPitch = std::cos(static_cast<T>(angles.pitch) * static_cast<T>(0.5));
        T sinPitch = std::sin(static_cast<T>(angles.pitch) * static_cast<T>(0.5));

        w = cosYaw * cosRoll * cosPitch + sinYaw * sinRoll * sinPitch;
        x = cosYaw * sinRoll * cosPitch - sinYaw * cosRoll * sinPitch;
        y = cosYaw * cosRoll * sinPitch + sinYaw * sinRoll * cosPitch;
        z = sinYaw * cosRoll * cosPitch - cosYaw * sinRoll * sinPitch;

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
    template<typename U>    Quaternion<T>& Quaternion<T>::set(const Quaternion<U>& quat)
    {
        w = static_cast<T>(quat.w);
        x = static_cast<T>(quat.x);
        y = static_cast<T>(quat.y);
        z = static_cast<T>(quat.z);

        return (*this);
    }

    /*! \brief Normalize the Quaternion
     *
     * \return Return this
     *
     */
    template<typename T>
    Quaternion<T>& Quaternion<T>::normalize(T* length)
    {
        T normal = getMagnitude();

        if(normal > 0.0)
        {
            T inversNormal = 1.0 / normal;
            w *= inversNormal;
            x *= inversNormal;
            y *= inversNormal;
            z *= inversNormal;
        }

        if(length)
        {
            *length = normal;
        }

        return (*this);
    }

    /*! \brief Get the magnitude of the quaternion
     *
     * \return Return magnitude
     *
     */
    template<typename T>
    T Quaternion<T>::getMagnitude() const
    {
        return std::sqrt(getSquaredMagnitude());
    }

    /*! \brief Get the squared magnitude of the quaternion
     *
     * \return Return squared magnitude
     *
     */
    template<typename T>
    T Quaternion<T>::getSquaredMagnitude() const
    {
        return w * w + x * x + y * y + z * z;
    }

    /*! \brief Compare two quaternions
     *
     * \param right The Quaternion to compare to this
     *
     * \return Return true if this and right are equal, false otherwise
     *
     */
    template<typename T>
    template<typename U>
    bool Quaternion<T>::operator==(const Quaternion<U>& right) const
    {
        return (w == static_cast<T>(right.w)) &&
               (x == static_cast<T>(right.x)) &&
               (y == static_cast<T>(right.y)) &&
               (z == static_cast<T>(right.z));
    }

    /*! \brief Compare two quaternions
     *
     * \param right The Quaternion to compare to this
     *
     * \return Return true if this and right are not equal, false otherwise
     *
     */
    template<typename T>
    template<typename U>
    bool Quaternion<T>::operator!=(const Quaternion<U>& right) const
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
    template<typename U>
    Quaternion<T> Quaternion<T>::operator*(const Quaternion<U>& right) const
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
    template<typename U>
    Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<U>& right)
    {
        Quaternion<T> product;

        product.w = w * static_cast<T>(right.w) - x * static_cast<T>(right.x) - y * static_cast<T>(right.y) - z * static_cast<T>(right.z);
        product.x = w * static_cast<T>(right.x) - x * static_cast<T>(right.w) - y * static_cast<T>(right.z) - z * static_cast<T>(right.y);
        product.y = w * static_cast<T>(right.y) - x * static_cast<T>(right.z) - y * static_cast<T>(right.w) - z * static_cast<T>(right.x);
        product.z = w * static_cast<T>(right.z) - x * static_cast<T>(right.y) - y * static_cast<T>(right.x) - z * static_cast<T>(right.w);

        return set(product);
    }
}
