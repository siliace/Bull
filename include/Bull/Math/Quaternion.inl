namespace Bull
{
    template <typename T>
    Quaternion<T> Quaternion<T>::conjugate(const Quaternion<T>& quaternion)
    {
        return Quaternion<T>(quaternion).conjugate();
    }

    template <typename T>
    Quaternion<T> Quaternion<T>::fromEulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        return Quaternion<T>(EulerAngles<T>(roll, pitch, yaw));
    }

    template <typename T>
    Quaternion<T>::Quaternion() :
        Quaternion<T>(0, 0, 0, 0)
    {
        /// Nothing
    }

    template <typename T>
    Quaternion<T>::Quaternion(T w, T x, T y, T z) :
        w(w),
        x(x),
        y(y),
        z(z)
    {
        /// Nothing
    }

    template <typename T>
    Quaternion<T>::Quaternion(const EulerAngles<T>& angles)
    {
        T cy = std::cos(angles.yaw   * static_cast<T>(0.5));
        T sy = std::sin(angles.yaw   * static_cast<T>(0.5));
        T cr = std::cos(angles.roll  * static_cast<T>(0.5));
        T sr = std::sin(angles.roll  * static_cast<T>(0.5));
        T cp = std::cos(angles.pitch * static_cast<T>(0.5));
        T sp = std::sin(angles.pitch * static_cast<T>(0.5));

        w = cy * cr * cp + sy * sr * sp;
        x = cy * sr * cp - sy * cr * sp;
        y = cy * cr * sp + sy * sr * cp;
        z = sy * cr * cp - cy * sr * sp;
    }

    template <typename T>
    float Quaternion<T>::getLength() const
    {
        return std::pow(w, 2) + std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
    }

    template <typename T>
    float Quaternion<T>::getSquareRootLength() const
    {
        return std::sqrt(getLength());
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::normalize()
    {
        T n = Quaternion<T>::getSquareRootLenght();

        w /= n;
        x /= n;
        y /= n;
        z /= n;

        return (*this);
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::conjugate()
    {
        x = -x;
        y = -y;
        z = -z;

        return (*this);
    }

    template <typename T>
    bool Quaternion<T>::operator==(const Quaternion<T>& right) const
    {
        return w == right.w &&
               x == right.x &&
               y == right.y &&
               z == right.z;
    }

    template <typename T>
    bool Quaternion<T>::operator!=(const Quaternion<T>& right) const
    {
        return !((*this) == right);
    }

    template <typename T>
    Quaternion<T> Quaternion<T>::operator*(T scale)
    {
        return Quaternion<T>(w * scale,
                             x * scale,
                             y * scale,
                             z * scale);
    }

    template <typename T>
    Vector3<T> Quaternion<T>::operator*(const Vector3<T>& vector)
    {
        Vector3<T> quaternionVector(x, y, z);
        Vector3<T> uv  = Vector3<T>::crossProduct(quaternionVector, vector);
        Vector3<T> uuv = Vector3<T>::crossProduct(quaternionVector, uv);

        uv  *= 2 * w;
        uuv *= 2;

        return vector + uv + uuv;
    }
}