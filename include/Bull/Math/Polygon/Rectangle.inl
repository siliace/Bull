namespace Bull
{
    template<typename T>
    Rectangle<T>::Rectangle()
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(0.0, 0.0, 0.0, 0.0);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(U x, U y, U width, U height)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(x, y, width, height);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& size)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(size);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& topLeft, U width, U height)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(topLeft, width, height);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Vector2<U>& topLeft, const Vector2<U>& bottomRight)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(topLeft, bottomRight);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>::Rectangle(const Rectangle<U>& rectangle)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(rectangle);
    }

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

    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& size)
    {
        x      = static_cast<T>(0);
        y      = static_cast<T>(0);
        width  = static_cast<T>(size.x);
        height = static_cast<T>(size.y);

        return (*this);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& topLeft, U width, U height)
    {
        return set(topLeft.x, topLeft.y, width, height);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Vector2<U>& topLeft, const Vector2<U>& bottomRight)
    {
        return set(topLeft, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
    }

    template<typename T>
    template<typename U>
    Rectangle<T>& Rectangle<T>::set(const Rectangle<U>& rectangle)
    {
        return set(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
    }

    template<typename T>
    Vector2<T> Rectangle<T>::getVertex(std::size_t index) const
    {
        switch(index)
        {
            case 0: return Vector2<T>(x, y);
            case 1: return Vector2<T>(x + width, y);
            case 2: return Vector2<T>(x + width, y + height);
            case 3: return Vector2<T>(x, y + height);
        }

        throw std::out_of_range("Rectangle<T>::getVertex() : index is out of range");
    }

    template<typename T>
    std::size_t Rectangle<T>::getVertexCount() const
    {
        return 4;
    }
}
