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
    Angle<T> Angle<T>::asDegree() const
    {
        return Angle<T>(m_isRadian ? m_value * (180.0 / Pi) : m_value, false);
    }

    template<typename T>
    Angle<T> Angle<T>::asRadian() const
    {
        return Angle<T>(m_isRadian ? m_value : m_value * (Pi / 180.0), true);
    }

    template <typename T>
    Angle<T>& Angle<T>::normalize()
    {
        m_value = std::fmod(m_value, (m_isRadian) ? Pi * 2 : 360);

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator+(T right)
    {
        return Angle<T>(m_value + right, m_isRadian);
    }

    template<typename T>
    Angle<T>& Angle<T>::operator+=(T right)
    {
        m_value += m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator-(T right)
    {
        return Angle<T>(m_value - right, m_isRadian);
    }

    template<typename T>
    Angle<T>& Angle<T>::operator-=(T right)
    {
        m_value -= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator*(T right)
    {
        return Angle<T>(m_value * right, m_isRadian);
    }

    template<typename T>
    Angle<T>& Angle<T>::operator*=(T right)
    {
        m_value *= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::operator/(T right)
    {
        return Angle<T>(m_value / right, m_isRadian);
    }

    template<typename T>
    Angle<T>& Angle<T>::operator/=(T right)
    {
        m_value /= m_isRadian ? right.asRadian() : right.asDegree();

        return (*this);
    }

    template<typename T>
    Angle<T>::operator T() const
    {
        return m_value;
    }

    template<typename T>
    Angle<T>::Angle(T angle, bool isRadian) :
        m_value(angle),
        m_isRadian(isRadian)
    {
        /// Nothing
    }
}

namespace std
{
    template<typename T>
    float cos(const Bull::Angle<T>& angle)
    {
        return std::cos(static_cast<T>(angle.asRadian()));
    }

    template<typename T>
    float sin(const Bull::Angle<T>& angle)
    {
        return std::sin(static_cast<T>(angle.asRadian()));
    }

    template<typename T>
    float tan(const Bull::Angle<T>& angle)
    {
        return std::tan(static_cast<T>(angle.asRadian()));
    }
}
