namespace Bull
{
    template<typename T>
    T Vector2<T>::dotProduct(const Vector2& left, const Vector2& right)
    {
        return (left.x * right.x) + (left.y * right.y);
    }

    template<typename T>
    Vector2<T>::Vector2() :
        x(0),
        y(0)
    {
        /// Nothing
    }

    template<typename T>
    Vector2<T>::Vector2(T value) :
        x(value),
        y(value)
    {
        /// Nothing
    }

    template<typename T>
    Vector2<T>::Vector2(T x, T y) :
        x(x),
        y(y)
    {
        /// Nothing
    }

    template<typename T>
    float Vector2<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    template<typename T>
    T Vector2<T>::dotProduct(const Vector2& right)
    {
        return (x * right.x) + (y * right.y);
    }

    template<typename T>
    bool Vector2<T>::operator==(const Vector2& right) const
    {
        return (x == right.x) && (y == right.y);
    }

    template<typename T>
    bool Vector2<T>::operator!=(const Vector2& right) const
    {
        return !((*this) == right);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2& right)
    {
        x += right.x;
        y += right.y;

        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2& right)
    {
        x -= right.x;
        y -= right.y;

        return (*this);
    }

    template<typename T>
    Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left) += right;
    }

    template<typename T>
    Vector2<T> operator+(float left, const Vector2<T>& right)
    {
        return Vector2<T>(left) += right;
    }

    template<typename T>
    Vector2<T> operator+(const Vector2<T>& left, float right)
    {
        return Vector2<T>(left) += Vector2<T>(right);
    }

    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left) -= right;
    }

    template<typename T>
    Vector2<T> operator-(float left, const Vector2<T>& right)
    {
        return Vector2<T>(left) -= right;
    }

    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, float right)
    {
        return Vector2<T>(left) -= Vector2<T>(right);
    }
}
