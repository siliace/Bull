namespace Bull
{
    /*! \brief Calculate the dot(scalar) product of two Vector2
     *
     * \param left  The left Vector2 of the product
     * \param right The right Vector2 of the product
     *
     * \return The value of the dot product of left and right
     *
     */
    template<typename TComponent>
    TComponent Vector2<TComponent>::dotProduct(const Vector2& left, const Vector2& right)
    {
        return (left.x * right.x) + (left.y * right.y);
    }


    /*! \brief Default constructor
     *
     */
    template<typename TComponent>
    Vector2<TComponent>::Vector2() :
        x(0),
        y(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param value The value of all components
     *
     */
    template<typename TComponent>
    Vector2<TComponent>::Vector2(TComponent value) :
        x(value),
        y(value)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param x The x component
     * \param y The y component
     *
     */
    template<typename TComponent>
    Vector2<TComponent>::Vector2(TComponent x, TComponent y) :
        x(x),
        y(y)
    {
        /// Nothing
    }

    /*! \brief Compute the length
     *
     * \return Return the length of the vector
     *
     */
    template<typename TComponent>
    float Vector2<TComponent>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    /*! \brief Calculate the dot(scalar) product of two vectors
     *
     * \param right The other to calculate the dot product with
     *
     * \return The value of the dot product
     *
     */
    template<typename TComponent>
    TComponent Vector2<TComponent>::dotProduct(const Vector2& right)
    {
        return (x * right.x) + (y * right.y);
    }

    /*! \brief == operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are equal, else return false
     *
     */
    template<typename TComponent>
    bool Vector2<TComponent>::operator==(const Vector2& right) const
    {
        return (x == right.x) && (y == right.y);
    }

    /*! \brief != operator override
     *
     * \param right The vector to compare
     *
     * \return Return true if this and right are not equal, else return false
     *
     */
    template<typename TComponent>
    bool Vector2<TComponent>::operator!=(const Vector2& right) const
    {
        return !((*this) == right);
    }

    /*! \brief + operator override
     *
     * \param right The vector to add
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent>& Vector2<TComponent>::operator+=(const Vector2& right)
    {
        x += right.x;
        y += right.y;

        return (*this);
    }

    /*! \brief - operator override
     *
     * \param right The vector to subtract
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent>& Vector2<TComponent>::operator-=(const Vector2& right)
    {
        x -= right.x;
        y -= right.y;

        return (*this);
    }

    /*! \brief Addition two Vector2
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator+(const Vector2<TComponent>& left, const Vector2<TComponent>& right)
    {
        return Vector2<TComponent>(left) += right;
    }

    /*! \brief Addition two Vector2
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator+(float left, const Vector2<TComponent>& right)
    {
        return Vector2<TComponent>(left) += right;
    }

    /*! \brief Addition two Vector2
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator+(const Vector2<TComponent>& left, float right)
    {
        return Vector2<TComponent>(left) += Vector2<TComponent>(right);
    }

    /*! \brief Subtract two Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator-(const Vector2<TComponent>& left, const Vector2<TComponent>& right)
    {
        return Vector2<TComponent>(left) -= right;
    }

    /*! \brief Subtract two Vector2
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator-(float left, const Vector2<TComponent>& right)
    {
        return Vector2<TComponent>(left) -= right;
    }

    /*! \brief Subtract two Vector2
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector2<TComponent> operator-(const Vector2<TComponent>& left, float right)
    {
        return Vector2<TComponent>(left) -= Vector2<TComponent>(right);
    }
}
