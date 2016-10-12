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
    template<typename TComponent>
    TComponent Vector4<TComponent>::dotProduct(const Vector4& left, const Vector4& right)
    {
        return (left.x * right.x) + (left.y * right.y) + (left.z * right.z) + (left.w * right.w);
    }

    /*! \brief Default constructor
     *
     */
    template<typename TComponent>
    Vector4<TComponent>::Vector4() :
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
    template<typename TComponent>
    Vector4<TComponent>::Vector4(TComponent value) :
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
    template<typename TComponent>
    Vector4<TComponent>::Vector4(TComponent x, TComponent y, TComponent z, TComponent w) :
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
    template<typename TComponent>
    Vector4<TComponent>::Vector4(const Vector3<TComponent>& copy, TComponent w) :
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
    template<typename TComponent>
    float Vector4<TComponent>::getLength() const
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
    template<typename TComponent>
    TComponent Vector4<TComponent>::dotProduct(const Vector4& right)
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
    template<typename TComponent>
    bool Vector4<TComponent>::operator==(const Vector4& right) const
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
    template<typename TComponent>
    bool Vector4<TComponent>::operator!=(const Vector4& right) const
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
    template<typename TComponent>
    Vector4<TComponent>& Vector4<TComponent>::operator+=(const Vector4& right)
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
    template<typename TComponent>
    Vector4<TComponent> Vector4<TComponent>::operator-() const
    {
        return Vector4<TComponent>(-x, -y, -z, -w);
    }

    /*! \brief -= operator override
     *
     * \param right The vector to subtract
     *
     * \return Return this after subtraction
     *
     */
    template<typename TComponent>
    Vector4<TComponent>& Vector4<TComponent>::operator-=(const Vector4& right)
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
    template<typename TComponent>
    Vector4<TComponent> operator+(const Vector4<TComponent>& left, const Vector4<TComponent>& right)
    {
        return Vector4<TComponent>(left) += right;
    }

    /*! \brief Addition two Vector4
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator+(float left, const Vector4<TComponent>& right)
    {
        return Vector4<TComponent>(left) += right;
    }

    /*! \brief Addition two Vector4
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator+(const Vector4<TComponent>& left, float right)
    {
        return Vector4<TComponent>(left) += Vector4<TComponent>(right);
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(const Vector4<TComponent>& left, const Vector4<TComponent>& right)
    {
        return Vector4<TComponent>(left) -= right;
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(float left, const Vector4<TComponent>& right)
    {
        return Vector4<TComponent>(left) -= right;
    }

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(const Vector4<TComponent>& left, float right)
    {
        return Vector4<TComponent>(left) -= Vector4<TComponent>(right);
    }
}
