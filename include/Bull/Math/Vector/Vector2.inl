namespace Bull
{
    template <typename T>
    Vector2<T>::Vector2(T x, T y)
    {
        set(x, y);
    }

    template <typename T>
    template <typename U, Index US>
    Vector2<T>::Vector2(const Vector<U, US>& copy) :
        Vector<T, 2>(copy)
    {
        /// Nothing
    }

    template <typename T>
    Vector2<T>& Vector2<T>::set(T x, T y)
    {
        this->x() = x;
        this->y() = y;

        return (*this);
    }

    template <typename T>
    float Vector2<T>::getRatio() const
    {
        return static_cast<float>(x()) / static_cast<float>(y());
    }

    template <typename T>
    T& Vector2<T>::x()
    {
        return Vector<T, 2>::at(0);
    }

    template <typename T>
    const T& Vector2<T>::x() const
    {
        return Vector<T, 2>::at(0);
    }

    template <typename T>
    T& Vector2<T>::y()
    {
        return Vector<T, 2>::at(1);
    }

    template <typename T>
    const T& Vector2<T>::y() const
    {
        return Vector<T, 2>::at(1);
    }
}
