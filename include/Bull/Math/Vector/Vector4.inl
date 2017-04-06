namespace Bull
{
    template<typename T>
    Vector4<T> Vector4<T>::normalize(const Vector4<T>& vector)
    {
        return Vector4<T>(vector).normalize();
    }

    template<typename T>
    T Vector4<T>::dotProduct(const Vector4& left, const Vector4& right)
    {
        return (left.x * right.x) + (left.y * right.y) + (left.z * right.z) + (left.w * right.w);
    }

    template<typename T>
    Vector4<T>::Vector4() :
        x(0),
        y(0),
        z(0),
        w(0)
    {
        /// Nothing
    }

    template<typename T>
    Vector4<T>::Vector4(T value) :
        x(value),
        y(value),
        z(value),
        w(value)
    {
        /// Nothing
    }

    template<typename T>
    Vector4<T>::Vector4(T x, T y, T z, T w) :
        x(x),
        y(y),
        z(z),
        w(w)
    {
        /// Nothing
    }

    template<typename T>
    Vector4<T>::Vector4(const Vector3<T>& copy, T w) :
        x(copy.x),
        y(copy.y),
        z(copy.z),
        w(w)
    {
        /// Nothing
    }

    template<typename T>
    float Vector4<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w, 2));
    }

    template<typename T>
    Vector4<T>& Vector4<T>::normalize()
    {
        x /= w;
        y /= w;
        z /= w;
        w  = 0.0;

        return (*this);
    }

    template<typename T>
    T Vector4<T>::dotProduct(const Vector4& right)
    {
        return (x * right.x) + (y * right.y) + (z * right.z) + (w * right.w);
    }

    template<typename T>
    bool Vector4<T>::operator==(const Vector4& right) const
    {
        return (x == right.x) && (y == right.y) && (z == right.z) && (w == right.w);
    }

    template<typename T>
    bool Vector4<T>::operator!=(const Vector4& right) const
    {
        return !((*this) == right);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator+=(const Vector4& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;
        w += right.w;

        return (*this);
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator-() const
    {
        return Vector4<T>(-x, -y, -z, -w);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator-=(const Vector4& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;
        w -= right.w;

        return (*this);
    }

    template<typename T>
    Vector4<T> operator+(const Vector4<T>& left, const Vector4<T>& right)
    {
        return Vector4<T>(left) += right;
    }

    template<typename T>
    Vector4<T> operator+(float left, const Vector4<T>& right)
    {
        return Vector4<T>(left) += right;
    }

    template<typename T>
    Vector4<T> operator+(const Vector4<T>& left, float right)
    {
        return Vector4<T>(left) += Vector4<T>(right);
    }

    template<typename T>
    Vector4<T> operator-(const Vector4<T>& left, const Vector4<T>& right)
    {
        return Vector4<T>(left) -= right;
    }

    template<typename T>
    Vector4<T> operator-(float left, const Vector4<T>& right)
    {
        return Vector4<T>(left) -= right;
    }

    template<typename T>
    Vector4<T> operator-(const Vector4<T>& left, float right)
    {
        return Vector4<T>(left) -= Vector4<T>(right);
    }
}
