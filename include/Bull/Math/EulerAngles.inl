namespace Bull
{
    template <typename T>
    EulerAngles<T>::EulerAngles()
    {
        set(Angle<T>::degree(0), Angle<T>::degree(0), Angle<T>::degree(0));
    }

    template <typename T>
    EulerAngles<T>::EulerAngles(const EulerAngles<T>& copy)
    {
        set(copy);
    }

    template <typename T>
    EulerAngles<T>::EulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        set(roll, pitch, yaw);
    }

    template <typename T>
    EulerAngles<T>& EulerAngles<T>::operator=(const EulerAngles<T>& copy)
    {
        return set(copy);
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
    EulerAngles<T>& EulerAngles<T>::set(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
    {
        this->roll  = roll;
        this->pitch = pitch;
        this->yaw   = yaw;

        return (*this);
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
}