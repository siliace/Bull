namespace Bull
{
    template <typename T>
    EulerAngles<T> EulerAngles<T>::normalize(const EulerAngles<T>& angles)
    {
        return EulerAngles<T>(angles).normalize();
    }

    template <typename T>
    EulerAngles<T>::EulerAngles(const Quaternion<T>& quaternion)
    {
        set(quaternion);
    }

    template <typename T>
    EulerAngles<T>::EulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        set(roll, pitch, yaw);
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::set(const EulerAngles<T>& copy)
    {
        roll  = copy.roll;
        pitch = copy.pitch;
        yaw   = copy.yaw;

        return (*this);
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::set(const Quaternion<T>& quaternion)
    {
        EulerAngles<T> representation = quaternion.toEulerAngles();

        roll  = representation.roll;
        pitch = representation.pitch;
        yaw   = representation.yaw;

        return (*this);
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::set(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        this->roll  = roll;
        this->pitch = pitch;
        this->yaw   = yaw;

        return (*this);
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::normalize()
    {
        roll.normalize();
        pitch.normalize();
        yaw.normalize();

        return (*this);
    }

    template <typename T>
    Quaternion<T> EulerAngles<T>::toQuaternion() const
    {
        return Quaternion<T>((*this));
    }

    template <typename T>
    bool EulerAngles<T>::operator==(const EulerAngles<T>& right)
    {
        return (roll  == right.roll)  &&
               (pitch == right.pitch) &&
               (yaw   == right.yaw);
    }

    template <typename T>
    bool EulerAngles<T>::operator!=(const EulerAngles<T>& right)
    {
        return !((*this) == right);
    }

    template <typename T>
    EulerAngles<T> EulerAngles<T>::operator+(const EulerAngles<T>& right) const
    {
        return EulerAngles<T>((*this)) += right;
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::operator+=(const EulerAngles<T>& right)
    {
        roll  += right.roll;
        pitch += right.pitch;
        yaw   += right.yaw;


        return (*this);
    }

    template <typename T>
    EulerAngles<T> EulerAngles<T>::operator-(const EulerAngles<T>& right) const
    {
        return EulerAngles<T>((*this)) -= right;
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::operator-=(const EulerAngles<T>& right)
    {
        roll  -= right.roll;
        pitch -= right.pitch;
        yaw   -= right.yaw;

        return (*this);
    }

}