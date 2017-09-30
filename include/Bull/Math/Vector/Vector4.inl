namespace Bull
{
    template <typename T>
    Vector4<T>::Vector4(T value)
    {
        set(value);
    }

    template <typename T>
    Vector4<T>::Vector4(T x, T y, T z, T w)
    {
        set(x, y, z, w);
    }

    template <typename T>
    Vector4<T>::Vector4(const Vector3<T>& copy, T w) :
        Vector<T, 4>(copy)
    {
        this->w() = w;
    }

    template <typename T>
    template <typename U, Index US>
    Vector4<T>::Vector4(const Vector<U, US>& copy) :
        Vector<T, 4>(copy)
    {
        /// Nothing
    }

    template <typename T>
    Vector4<T>& Vector4<T>::set(T x, T y, T z, T w)
    {
        this->x() = x;
        this->y() = y;
        this->z() = z;
        this->w() = w;

		return (*this);
    }

    template <typename T>
    T& Vector4<T>::x()
    {
        return Vector<T, 4>::at(0);
    }

    template <typename T>
    const T& Vector4<T>::x() const
    {
        return Vector<T, 4>::at(0);
    }

    template <typename T>
    T& Vector4<T>::y()
    {
        return Vector<T, 4>::at(1);
    }

    template <typename T>
    const T& Vector4<T>::y() const
    {
        return Vector<T, 4>::at(1);
    }

    template <typename T>
    T& Vector4<T>::z()
    {
        return Vector<T, 4>::at(2);
    }

    template <typename T>
    const T& Vector4<T>::z() const
    {
        return Vector<T, 4>::at(2);
    }

    template <typename T>
    T& Vector4<T>::w()
    {
        return Vector<T, 4>::at(3);
    }

    template <typename T>
    const T& Vector4<T>::w() const
    {
        return Vector<T, 4>::at(3);
    }
}
