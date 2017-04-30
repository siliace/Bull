namespace Bull
{
    template <typename T>
    Quaternion<T> Quaternion<T>::conjugate(const Quaternion<T>& left, const Quaternion<T>& right)
    {
        return Quaternion<T>(left).conjugate(right);
    }

    template <typename T>
    Quaternion<T> Quaternion<T>::fromEulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        return Quaternion<T>(EulerAngles<T>(roll, pitch, yaw));
    }

    template <typename T>
    Quaternion<T>::Quaternion()
    {
        set(0, 0, 0, 0);
    }

    template <typename T>
    Quaternion<T>::Quaternion(const EulerAngles<T>& angles)
    {
        set(angles);
    }

    template <typename T>
    Quaternion<T>::Quaternion(T w, T x, T y, T z)
    {
        set(w, x, y, z);
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::set(const EulerAngles<T>& angles)
    {
        T cy = std::cos(static_cast<T>(angles.yaw.asRadian())   * 0.5);
        T sy = std::sin(static_cast<T>(angles.yaw.asRadian())   * 0.5);
        T cr = std::cos(static_cast<T>(angles.roll.asRadian())  * 0.5);
        T sr = std::sin(static_cast<T>(angles.roll.asRadian())  * 0.5);
        T cp = std::cos(static_cast<T>(angles.pitch.asRadian()) * 0.5);
        T sp = std::sin(static_cast<T>(angles.pitch.asRadian()) * 0.5);

        w = cy * cr * cp + sy * sr * sp;
        x = cy * sr * cp - sy * cr * sp;
        y = cy * cr * sp + sy * sr * cp;
        z = sy * cr * cp - cy * sr * sp;

        return (*this);
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::set(T w, T x, T y, T z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;

        return (*this);
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::set(const Quaternion& quaternion)
    {
        return set(quaternion.w, quaternion.x, quaternion.y, quaternion.z);
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
        T n = static_cast<T>(this->getSquareRootLenght()); /// We use this here to prevent GCC warning

        w /= n;
        x /= n;
        y /= n;
        z /= n;

        return (*this);
    }

    template <typename T>
    Quaternion<T>& Quaternion<T>::conjugate(const Quaternion<T>& quaternion)
    {
        w =  quaternion.w;
        x = -quaternion.x;
        y = -quaternion.y;
        z = -quaternion.z;

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
}