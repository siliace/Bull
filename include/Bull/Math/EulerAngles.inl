namespace Bull
{
    /*! \brief Default constructor
     *
     */
    template<typename T>
    EulerAngles<T>::EulerAngles()
    {
        set(0.0);
    }

    /*! \brief Constructor
     *
     * \param value The value of the angle on every axes
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>::EulerAngles(U value)
    {
        set(value);
    }

    /*! \brief Constructor
     *
     * \param roll  The roll of the angle to create
     * \param pitch The pitch of the angle to create
     * \param yaw   The yaw of the angle to create
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>::EulerAngles(U roll, U pitch, U yaw)
    {
        set(roll, pitch, yaw);
    }

    /*! \brief Copy constructor
     *
     * \param copy The EulerAngles to copy
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>::EulerAngles(const EulerAngles<U>& copy)
    {
        set(copy);
    }

    /*! \brief Basic assignment operator
     *
     * \param copy The EulerAngles to copy
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T> EulerAngles<T>::operator=(const EulerAngles<U>& copy)
    {
        return set(copy);
    }

    /*! \brief Set the value of the EulerAngles
     *
     * \param value The value of the angle on every axes
     *
     * \return Return this
     *
     */
    template<typename T>    template<typename U>
    EulerAngles<T>& EulerAngles<T>::set(U value)
    {
        roll  = static_cast<T>(value);
        pitch = static_cast<T>(value);
        yaw   = static_cast<T>(value);

        return (*this);
    }

    /*! \brief Set the value of the EulerAngles
     *
     * \param roll  The roll of the angle to create
     * \param pitch The pitch of the angle to create
     * \param yaw   The yaw of the angle to create
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>& EulerAngles<T>::set(U roll, U pitch, U yaw)
    {
        this->roll  = static_cast<T>(roll);
        this->pitch = static_cast<T>(pitch);
        this->yaw   = static_cast<T>(yaw);

        return (*this);
    }

    /*! \brief Set the value of the EulerAngles
     *
     * \param copy The EulerAngles to copy
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>& EulerAngles<T>::set(const EulerAngles<U>& copy)
    {
        roll  = static_cast<T>(copy.roll);
        pitch = static_cast<T>(copy.pitch);
        yaw   = static_cast<T>(copy.yaw);

        return (*this);
    }

    /*! \brief Compare two EulerAngles
     *
     * \param right The EulerAngles to compare to this
     *
     * \return Return true if this and right are equal, false otherwise
     *
     */
    template<typename T>
    template<typename U>
    bool EulerAngles<T>::operator==(const EulerAngles<U>& right)
    {
        return (roll  == static_cast<T>(right.roll))  &&
               (pitch == static_cast<T>(right.pitch)) &&
               (yaw   == static_cast<T>(right.yaw));
    }

    /*! \brief Compare two EulerAngles
     *
     * \param right The EulerAngles to compare to this
     *
     * \return Return true if this and right are not equal, false otherwise
     *
     */
    template<typename T>
    template<typename U>
    bool EulerAngles<T>::operator!=(const EulerAngles<U>& right)
    {
        return !((*this) == right);
    }

    /*! \brief Addition two EulerAngles
     *
     * \param right The EulerAngles to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T> EulerAngles<T>::operator+(const EulerAngles<U>& right)
    {
        return EulerAngles((*this)) += right;
    }

    /*! \brief Addition two EulerAngles
     *
     * \param right The EulerAngles to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>& EulerAngles<T>::operator+=(const EulerAngles<U>& right)
    {
        roll  += static_cast<T>(right.roll);
        pitch += static_cast<T>(right.pitch);
        yaw   += static_cast<T>(right.yaw);

        return (*this);
    }

    /*! \brief Subtract two EulerAngles
     *
     * \param right The EulerAngles to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T> EulerAngles<T>::operator-(const EulerAngles<U>& right)
    {
        return EulerAngles((*this)) -= right;
    }

    /*! \brief Subtract two EulerAngles
     *
     * \param right The EulerAngles to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>
    EulerAngles<T>& EulerAngles<T>::operator-=(const EulerAngles<U>& right)
    {
        roll  -= static_cast<T>(right.roll);
        pitch -= static_cast<T>(right.pitch);
        yaw   -= static_cast<T>(right.yaw);

        return (*this);
    }
}
