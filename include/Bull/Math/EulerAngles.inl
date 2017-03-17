namespace Bull
{
    template <typename T>
    EulerAngles<T>::EulerAngles() :
    {
        set(0.0, 0.0, 0.0);
    }

    template <typename T>
    template <typename U>
    EulerAngles<T>::EulerAngles(const EulerAngles<U>& copy)
    {
        set(copy);
    }

    template <typename T>
    template <typename U, typename V, typename W>
    EulerAngles<T>::EulerAngles(const Angle<U>& roll, const Angle<V>& pitch, const Angle<W>& yaw)
    {
        set(roll, pitch, yaw);
    }

    template <typename T>
    template <typename U>
    EulerAngles<T>& operator=(const EulerAngles<U>& copy)
    {
        return set(copy);
    }

    template <typename T>
    template <typename U>
    EulerAngles<T>& EulerAngles<T>::set(const EulerAngles<U>& copy)
    {
        roll  = copy.roll;
        pitch = copy.pitch;
        yaw   = copy.yaw;

        return (*this);
    }

    template <typename T>
    template <typename U, typename V, typename W>
    EulerAngles<T>& EulerAngles<T>::set(const Angle<U>& roll, const Angle<V>& pitch, const Angle<W>& yaw)
    {
        this->roll  = roll;
        this->pitch = pitch;
        this->yaw   = yaw;

        return (*this);
    }

    template <typename T>
    template <typename U>
    bool EulerAngles<T>::operator==(const EulerAngles<U>& right)
    {
        return (roll  == right.roll)  &&
               (pitch == right.pitch) &&
               (yaw   == right.yaw);
    }

    template <typename T>
    template <typename U>
    bool EulerAngles<T>::operator!=(const EulerAngles<U>& right)
    {
        return !((*this) == right);
    }
}