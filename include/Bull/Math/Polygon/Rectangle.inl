namespace Bull
{
    template<typename T>
    Rectangle<T>::Rectangle()
    {
        set(0, 0, 0, 0);
    }

    template<typename T>
    Rectangle<T>::Rectangle(T x, T y, T width, T height)
    {
        set(x, y, width, height);
    }

    template<typename T>
    Rectangle<T>::Rectangle(const Vector2<T>& size)
    {
        set(size);
    }

    template<typename T>
    Rectangle<T>::Rectangle(const Vector2<T>& topLeft, T width, T height)
    {
        set(topLeft, width, height);
    }

    template<typename T>
    Rectangle<T>::Rectangle(const Vector2<T>& topLeft, const Vector2<T>& bottomRight)
    {
        set(topLeft, bottomRight);
    }

    template<typename T>
    Rectangle<T>& Rectangle<T>::set(T x, T y, T width, T height)
    {
        this->x      = static_cast<T>(x);
        this->y      = static_cast<T>(y);
        this->width  = static_cast<T>(width);
        this->height = static_cast<T>(height);

        return (*this);
    }

    template<typename T>
    Rectangle<T>& Rectangle<T>::set(const Vector2<T>& size)
    {
        x      = static_cast<T>(0);
        y      = static_cast<T>(0);
        width  = static_cast<T>(size.x());
        height = static_cast<T>(size.y());

        return (*this);
    }

    template<typename T>
    Rectangle<T>& Rectangle<T>::set(const Vector2<T>& topLeft, T width, T height)
    {
        return set(topLeft.x, topLeft.y, width, height);
    }

    template<typename T>
    Rectangle<T>& Rectangle<T>::set(const Vector2<T>& topLeft, const Vector2<T>& bottomRight)
    {
        return set(topLeft, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
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

        throw OutOfRange("Rectangle<T>::getVertex() : index is out of range", 0, 3, index);
    }

    template<typename T>
    std::size_t Rectangle<T>::getVertexCount() const
    {
        return 4;
    }
}
