namespace Bull
{
    template<typename T>
    Vector2<T> Vector2<T>::normalize(const Vector2<T>& vector)
    {
        return Vector2<T>(vector).normalize();
    }

    template<typename T>
    T Vector2<T>::dotProduct(const Vector2& left, const Vector2& right)
    {
        return (left.x * right.x) + (left.y * right.y);
    }

    template<typename T>
    Vector2<T>::Vector2()
    {
        set(0);
    }

    template<typename T>
    Vector2<T>::Vector2(T value)
    {
        set(value);
    }

    template<typename T>
    Vector2<T>::Vector2(T x, T y)
    {
        set(x, y);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::set(T value)
    {
        x = y = value;

        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::set(T x, T y)
    {
        this->x = x;
        this->y = y;

        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::set(const Vector2<T>& copy)
    {
        x = copy.x;
        y = copy.y;

        return (*this);
    }

    template<typename T>
    float Vector2<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    template<typename T>
    float Vector2<T>::getRatio() const
    {
        return x / y;
    }

    template<typename T>
    Vector2<T>& Vector2<T>::normalize()
    {
        x /= getLength();
        y /= getLength();

        return (*this);
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
    Vector2<T> Vector2<T>::operator-() const
    {
        return Vector2<T>(-x, -y);
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
    Vector2<T> operator+(T left, const Vector2<T>& right)
    {
        return Vector2<T>(left) += right;
    }

    template<typename T>
    Vector2<T> operator+(const Vector2<T>& left, T right)
    {
        return Vector2<T>(left) += Vector2<T>(right);
    }

    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left) -= right;
    }

    template<typename T>
    Vector2<T> operator-(T left, const Vector2<T>& right)
    {
        return Vector2<T>(left) -= right;
    }

    template<typename T>
    Vector2<T> operator-(const Vector2<T>& left, T right)
    {
        return Vector2<T>(left) -= Vector2<T>(right);
    }

    template<typename T>
    Vector2<T> operator*(T left, const Vector2<T>& right)
    {
        Vector2<T> product = right;

        product.x *= left;
        product.y *= left;

        return right;
    }

    template<typename T>
    Vector2<T> operator*(const Vector2<T>& left, T right)
    {
        Vector2<T> product = left;

        product.x *= right;
        product.y *= right;

        return left;
    }

    template<typename T>
    Vector2<T> operator/(T left, const Vector2<T>& right)
    {
        Vector2<T> product = right;

        product.x /= left;
        product.y /= left;

        return right;
    }

    template<typename T>
    Vector2<T> operator/(const Vector2<T>& left, T right)
    {
        Vector2<T> product = left;

        product.x /= right;
        product.y /= right;

        return left;
    }
}
