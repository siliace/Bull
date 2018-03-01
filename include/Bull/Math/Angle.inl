namespace Bull
{
    template <typename T>
    Angle<T> Angle<T>::degree(T value)
    {
        return Angle<T>(value, true);
    }

    template <typename T>
    Angle<T> Angle<T>::radian(T value)
    {
        return Angle<T>(value);
    }

    template <typename T>
    Angle<T> Angle<T>::normalize(const Angle<T>& angle)
    {
        return Angle<T>(angle).normalize();
    }

    template <typename T>
    Angle<T> Angle<T>::clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max)
    {
        return Angle<T>(angle).clamp(min, max);
    }

    template <typename T>
    Angle<T>::Angle() :
        Angle(0, false)
    {
        /// Nothing
    }

    template <typename T>
    Angle<T>& Angle<T>::normalize()
    {
        while(m_value >= 2 * Pi)
        {
            m_value /= 2 * Pi;
        }

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::clamp(const Angle<T>& min, const Angle<T>& max)
    {
        if(m_value < min.m_value)
        {
            m_value = min.m_value;
        }
        else if(m_value > max.m_value)
        {
            m_value = max.m_value;
        }

        return (*this);
    }

    template <typename T>
    bool Angle<T>::operator==(const Angle<T>& right)
    {
        return m_value == right.m_value;
    }

    template <typename T>
    bool Angle<T>::operator!=(const Angle<T>& right)
    {
        return m_value != right.m_value;
    }

    template <typename T>
    bool Angle<T>::operator<(const Angle<T>& right)
    {
        return m_value < right.m_value;
    }

    template <typename T>
    bool Angle<T>::operator<=(const Angle<T>& right)
    {
        return m_value <= right.m_value;
    }

    template <typename T>
    bool Angle<T>::operator>(const Angle<T>& right)
    {
        return m_value > right.m_value;
    }

    template <typename T>
    bool Angle<T>::operator>=(const Angle<T>& right)
    {
        return m_value >= right.m_value;
    }

    template <typename T>
    Angle<T> Angle<T>::operator+(const Angle<T>& right)
    {
        return Angle<T>(m_value + right.m_value);
    }

    template <typename T>
    Angle<T> Angle<T>::operator-(const Angle<T>& right)
    {
        return Angle<T>(m_value - right.m_value);
    }

    template <typename U>
    Angle<U> operator*(U left, const Angle<U>& right)
    {
        return Angle<U>(left * right.m_value);
    }

    template <typename U>
    Angle<U> operator*(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_value * right);
    }

    template <typename U>
    Angle<U> operator/(U left, const Angle<U>& right)
    {
        return Angle<U>(left / right.m_value);
    }

    template <typename U>
    Angle<U> operator/(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_value / right);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator+=(const Angle<T>& right)
    {
        m_value += right.m_value;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator-=(const Angle<T>& right)
    {
        m_value -= right.m_value;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator*=(T right)
    {
        m_value *= right;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator/=(T right)
    {
        m_value /= right;

        return (*this);
    }

    template <typename T>
    Angle<T>::Angle(T value, bool convert)
    {
        if(convert)
        {
            value = value * Pi / 180;
        }

        m_value = value;
    }
}

namespace std
{
    template <typename U>
    float cos(const Bull::Angle<U>& angle)
    {
        return std::cos(angle.m_value);
    }

    template <typename U>
    float acos(const Bull::Angle<U>& angle)
    {
        return std::acos(angle.m_value);
    }

    template <typename U>
    float sin(const Bull::Angle<U>& angle)
    {
        return std::sin(angle.m_value);
    }

    template <typename U>
    float asin(const Bull::Angle<U>& angle)
    {
        return std::asin(angle.m_value);
    }

    template <typename U>
    float tan(const Bull::Angle<U>& angle)
    {
        return std::tan(angle.m_value);
    }

    template <typename U>
    float atan(const Bull::Angle<U>& angle)
    {
        return std::atan(angle.m_value);
    }

}