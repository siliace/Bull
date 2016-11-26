namespace Bull
{
    /*! \brief Default constructor
     *
     */
    template<typename T>
    Rectangle<T>::Rectangle()
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(0.0, 0.0, 0.0, 0.0);
    }

    /*! \brief Constructor
     *
     * \param x      The x coordinate of the top-left corner
     * \param y      The y coordinate of the top-left corner
     * \param width  The width of the rectangle
     * \param height The height of the rectangle
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(U x, U y, U width, U height)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(x, y, width, height);
    }

    /*! \brief Constructor
     *
     * \param size The size of the rectangle
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& size)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(size);
    }

    /*! \brief Constructor
     *
     * \param topLeft Coordinates of the top left corner of rectangle
     * \param width   The width of the rectangle
     * \param height  The height of the rectangle
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& topLeft, U width, U height)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(topLeft, width, height);
    }

    /*! \brief Constructor
     *
     * \param topLeft     Coordinates of the top left corner of rectangle
     * \param bottomRight Coordinates of the top bottom right of rectangle
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& topLeft, const Vector2<U>& bottomRight)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(topLeft, bottomRight);
    }

    /*! \brief Copy constructor
     *
     * \param rectangle The rectangle to copy
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Rectangle<U>& rectangle)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(rectangle);
    }

    /*! \brief Set the rectangle
     *
     * \param x      The x coordinate of the top-left corner
     * \param y      The y coordinate of the top-left corner
     * \param width  The width of the rectangle
     * \param height The height of the rectangle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(U x, U y, U width, U height)
    {
        this->x      = static_cast<T>(x);
        this->y      = static_cast<T>(y);
        this->width  = static_cast<T>(width);
        this->height = static_cast<T>(height);

        return (*this);
    }

    /*! \brief Set the rectangle
     *
     * \param size The size of the rectangle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& size)
    {
        x      = static_cast<T>(0);
        y      = static_cast<T>(0);
        width  = static_cast<T>(size.x);
        height = static_cast<T>(size.y);
    }

    /*! \brief Set the rectangle
     *
     * \param topLeft Coordinates of the top left corner of rectangle
     * \param width   The width of the rectangle
     * \param height  The height of the rectangle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& topLeft, U width, U height)
    {
        return set(topLeft.x, topLeft.y, width, height);
    }

    /*! \brief Set the rectangle
     *
     * \param topLeft     Coordinates of the top left corner of rectangle
     * \param bottomRight Coordinates of the top bottom right of rectangle
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& topLeft, const Vector2<U>& bottomRight)
    {
        return set(topLeft, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
    }

    /*! \brief Set the rectangle
     *
     * \param rectangle The rectangle to copy
     *
     * \return Return this
     *
     */
    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Rectangle<U>& rectangle)
    {
        return set(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
    }
}
