namespace Bull
{
    template<typename T>
    Angle<T> Angle<T>::radian(T angle)
    {
        return Angle<T>(angle, true);
    }

    template<typename T>
    Angle<T> Angle<T>::degree(T angle)
    {
        return Angle<T>(angle, false);
    }

    template<typename T>
    Angle<T>::Angle() :
        Angle(0, false)
    {
        /// Nothing
    }

    template<typename T>
    Angle<T>::Angle(T angle, bool isRadian) :
        m_isRadian(isRadian)
    {
        set(angle);
    }

    template <typename T>
    Angle<T>& Angle<T>::set(T angle, bool isRadian)
    {
        m_value    = angle;
        m_isRadian = isRadian;

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::asDegree() const
    {
        return Angle<T>(m_isRadian ? m_value * (180.0 / Pi) : m_value, false);
    }

    template<typename T>
    Angle<T> Angle<T>::asRadian() const
    {
        return Angle<T>(m_isRadian ? m_value : m_value * (Pi / 180.0), true);
    }

    template<typename T>
    Angle<T> Angle<T>::operator+(const Angle<T>& right)
    {
        return Angle<T>((*this)) += right;
    }

    template<typename T>
    Angle<T>& Angle<T>::operator+=(const Angle<T>& right)
    {
        m_value += m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator-(const Angle<T>& right)
    {
        return Angle<T>((*this)) -= right;
    }

    template<typename T>
    Angle<T>& Angle<T>::operator-=(const Angle<T>& right)
    {
        m_value -= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator*(const Angle<T>& right)
    {
        return Angle<T>((*this)) *= right;
    }

    template<typename T>
    Angle<T>& Angle<T>::operator*=(const Angle<T>& right)
    {
        m_value *= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator/(const Angle<T>& right)
    {
        return Angle<T>((*this)) /= right;
    }

    template<typename T>
    Angle<T>& Angle<T>::operator/=(const Angle<T>& right)
    {
        m_value /= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T>::operator T() const
    {
        return m_value;
    }
}

namespace std
{
    template<typename T>
    float cos(const Bull::Angle<T>& angle)
    {
        return std::cos(angle.asRadian());
    }

    template<typename T>
    float sin(const Bull::Angle<T>& angle)
    {
        return std::sin(angle.asRadian());
    }

    template<typename T>
    float tan(const Bull::Angle<T>& angle)
    {
        return std::tan(angle.asRadian());
    }
}
