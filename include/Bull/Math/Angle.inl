namespace Bull
{
    /*! \brief Create an angle in radians
     *
     * \param angle The value in radians of the angle to create
     *
     * \return Return the created angle
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::radian(U angle)
    {
        return Angle<T>(angle, true);
    }

    /*! \brief Create an angle in degrees
     *
     * \param angle The value in degrees of the angle to create
     *
     * \return Return the created angle
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::degree(U angle)
    {
        return Angle<T>(angle, false);
    }

    /*! \brief Default constructor
     *
     */
    template<typename T>
    Angle<T>::Angle() :
        Angle(0, false)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param angle
     * \param isRadian
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>::Angle(U angle, bool isRadian) :
        m_isRadian(isRadian)
    {
        set(angle);
    }

    /*! \brief Copy constructor
     *
     * \param copy The angle to copy
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>::Angle(const Angle<U>& copy)
    {
        set(copy);
    }

    /*! \brief Basic assignment operator
     *
     * \param angle The value of the angle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator=(Angle<U> angle)
    {
        return set(angle);
    }

    /*! \brief Basic assignment operator
     *
     * \param angle The value of the angle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator=(U angle)
    {
        return set(angle);
    }

    /*! \brief Set the value of the angle
     *
     * \param angle The value of the angle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::set(Angle<U> angle)
    {
        m_value    = static_cast<T>(angle.m_value);
        m_isRadian = angle.m_isRadian;

        return (*this);
    }

    /*! \brief Set the value of the angle
     *
     * \param angle The value of the angle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::set(U angle)
    {
        m_value = static_cast<T>(angle);

        return (*this);
    }

    /*! \brief Get the value of the angle in degrees
     *
     * \return Return the angle
     *
     */
    template<typename T>
    Angle<T> Angle<T>::asDegree() const
    {
        return Angle<T>(m_isRadian ? m_value * (static_cast<T>(180) / Pi) : m_value, false);
    }

    /*! \brief Get the value of the angle in radians
     *
     * \return Return the angle
     *
     */
    template<typename T>
    Angle<T> Angle<T>::asRadian() const
    {
        return Angle<T>(m_isRadian ? m_value : m_value * (Pi / static_cast<T>(180)), true);
    }

    /*! \brief Addition two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator+(U right)
    {
        return Angle<T>((*this)) += Angle(right, m_isRadian);
    }

    /*! \brief Addition two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator+(const Angle<U>& right)
    {
        return Angle<T>((*this)) += right;
    }

    /*! \brief Addition two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator+=(U right)
    {
        m_value += static_cast<T>(right);

        return (*this);
    }

    /*! \brief Addition two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the sum of this and right
     *
     */
    template<typename T>    template<typename U>
    Angle<T>& Angle<T>::operator+=(const Angle<U>& right)
    {
        m_value += static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    /*! \brief Subtract two angles
     *
     * \param right The angle to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator-(U right)
    {
        return Angle<T>((*this)) -= Angle(right, m_isRadian);
    }

    /*! \brief Subtract two angles
     *
     * \param right The angle to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator-(const Angle<U>& right)
    {
        return Angle<T>((*this)) -= right;
    }

    /*! \brief Subtract two angles
     *
     * \param right The angle to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator-=(U right)
    {
        m_value -= static_cast<T>(right);

        return (*this);
    }

    /*! \brief Subtract two angles
     *
     * \param right The angle to subtract to this
     *
     * \return Return the difference of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator-=(const Angle<U>& right)
    {
        m_value -= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    /*! \brief Multiply two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>    template<typename U>
    Angle<T> Angle<T>::operator*(U right)
    {
        return Angle<T>((*this)) *= Angle(right, m_isRadian);
    }

    /*! \brief Multiply two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator*(const Angle<U>& right)
    {
        return Angle<T>((*this)) *= right;
    }

    /*! \brief Multiply two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator*=(U right)
    {
        m_value *= static_cast<T>(right);

        return (*this);
    }

    /*! \brief Multiply two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the product of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator*=(const Angle<U>& right)
    {
        m_value *= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    /*! \brief Divide two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the quotient of this and right
     *
     */
    template<typename T>    template<typename U>
    Angle<T> Angle<T>::operator/(U right)
    {
        return Angle<T>((*this)) /= Angle(right, m_isRadian);
    }

    /*! \brief Divide two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the quotient of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator/(const Angle<U>& right)
    {
        return Angle<T>((*this)) /= right;
    }

    /*! \brief Divide two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the quotient of this and right
     *
     */
    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator/=(U right)
    {
        m_value /= static_cast<T>(right);

        return (*this);
    }

    /*! \brief Divide two angles
     *
     * \param right The angle to add to this
     *
     * \return Return the quotient of this and right
     *
     */
    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator/=(const Angle<U>& right)
    {
        m_value /= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    /*! \brief Convert the angle to a numeric value
     *
     * \return Return the value of the angle
     *
     */
    template<typename T>    Angle<T>::operator T() const
    {
        return m_value;
    }
}

namespace std
{
    template<typename T>
    float cos(const Bull::Angle<T>& angle)
    {
        return std::cos(static_cast<T>(angle));
    }

    template<typename T>
    float sin(const Bull::Angle<T>& angle)
    {
        return std::sin(static_cast<T>(angle));
    }

    template<typename T>
    float tan(const Bull::Angle<T>& angle)
    {
        return std::tan(static_cast<T>(angle));
    }
}
