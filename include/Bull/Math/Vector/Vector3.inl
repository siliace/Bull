namespace Bull
{
    template <typename T>
    Vector3<T> Vector3<T>::crossProduct(const Vector3<T>& left, const Vector3<T>& right)
    {
        return Vector3<T>(left).crossProduct(right);
    }

    template <typename T>
    Vector3<T>::Vector3(T value)
    {
        set(value);
    }

    template <typename T>
    Vector3<T>::Vector3(T x, T y, T z)
    {
        set(x, y, z);
    }

    template <typename T>
    template <typename U, std::size_t US>
    Vector3<T>::Vector3(const Vector<U, US>& copy) :
        Vector<T, US>(copy)
    {
        /// Nothing
    }

    template <typename T>
    Vector3<T>& Vector3<T>::set(T x, T y, T z)
    {
        this->x() = x;
        this->y() = y;
        this->z() = z;

        return (*this);
    }

    template <typename T>
    Vector3<T>& Vector3<T>::crossProduct(const Vector3<T>& right)
    {
        return set((y() * right.z()) - (z() * right.y()),
                   (z() * right.x()) - (x() * right.z()),
                   (x() * right.y()) - (y() * right.x()));
    }

    template <typename T>
    T& Vector3<T>::x()
    {
        return Vector<T, 3>::at(0);
    }

    template <typename T>
    const T& Vector3<T>::x() const
    {
        return Vector<T, 3>::at(0);
    }

    template <typename T>
    T& Vector3<T>::y()
    {
        return Vector<T, 3>::at(1);
    }

    template <typename T>
    const T& Vector3<T>::y() const
    {
        return Vector<T, 3>::at(1);
    }

    template <typename T>
    T& Vector3<T>::z()
    {
        return Vector<T, 3>::at(2);
    }

    template <typename T>
    const T& Vector3<T>::z() const
    {
        return Vector<T, 3>::at(2);
    }
}
