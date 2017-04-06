namespace Bull
{
    template<typename T>
    Vector3<T> Vector3<T>::makeZero()
    {
        return Vector3<T>(0.0, 0.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeUnit()
    {
        return Vector3<T>(1.0, 1.0, 1.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeUnitX()
    {
        return Vector3<T>(1.0, 0.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeUnitY()
    {
        return Vector3<T>(0.0, 1.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeUnitZ()
    {
        return Vector3<T>(0.0, 0.0, 1.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeLeft()
    {
        return Vector3<T>(1.0, 0.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeRight()
    {
        return Vector3<T>(-1.0, 0.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeUp()
    {
        return Vector3<T>(0.0, 1.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeDown()
    {
        return Vector3<T>(0.0, -1.0, 0.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeForward()
    {
        return Vector3<T>(0.0, 0.0, 1.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::makeBackward()
    {
        return Vector3<T>(0.0, 0.0, -1.0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::normalize(const Vector3<T>& vector)
    {
        return Vector3<T>(vector).normalize();
    }

    template<typename T>
    T Vector3<T>::dotProduct(const Vector3& left, const Vector3& right)
    {
        return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
    }

    template<typename T>
    Vector3<T>::Vector3() :
        x(0),
        y(0),
        z(0)
    {
        /// Nothing
    }

    template<typename T>
    Vector3<T>::Vector3(T value) :
        x(value),
        y(value),
        z(value)
    {
        /// Nothing
    }

    template<typename T>
    Vector3<T>::Vector3(T x, T y, T z) :
        x(x),
        y(y),
        z(z)
    {
        /// Nothing
    }

    template<typename T>
    Vector3<T>::Vector3(const Vector2<T>& copy, T z) :
        x(copy.x),
        y(copy.y),
        z(z)
    {
        /// Nothing
    }

    template<typename T>
    float Vector3<T>::getLength() const
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
    }

    template<typename T>
    Vector3<T>& Vector3<T>::normalize()
    {
        x /= getLength();
        y /= getLength();
        z /= getLength();

        return (*this);
    }

    template<typename T>
    T Vector3<T>::dotProduct(const Vector3& right)
    {
        return (x * right.x) + (y * right.y) + (z * right.z);
    }

    template<typename T>
    bool Vector3<T>::operator==(const Vector3& right) const
    {
        return (x == right.x) && (y == right.y) && (z == right.z);
    }

    template<typename T>
    bool Vector3<T>::operator!=(const Vector3& right) const
    {
        return !((*this) == right);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;

        return (*this);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-() const
    {
        return Vector3<T>(-x, -y, -z);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;

        return (*this);
    }

    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
    {
        return Vector3<T>(left) += right;
    }

    template<typename T>
    Vector3<T> operator+(float left, const Vector3<T>& right)
    {
        return Vector3<T>(left) += right;
    }

    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, float right)
    {
        return Vector3<T>(left) += Vector3<T>(right);
    }

    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
    {
        return Vector3<T>(left) -= right;
    }

    template<typename T>
    Vector3<T> operator-(float left, const Vector3<T>& right)
    {
        return Vector3<T>(left) -= right;
    }

    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, float right)
    {
        return Vector3<T>(left) -= Vector3<T>(right);
    }
}
