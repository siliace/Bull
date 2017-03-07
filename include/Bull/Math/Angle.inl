namespace Bull
{
    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::radian(U angle)
    {
        return Angle<T>(angle, true);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::degree(U angle)
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
    template<typename U>
    Angle<T>::Angle(U angle, bool isRadian) :
        m_isRadian(isRadian)
    {
        set(angle);
    }

    template<typename T>
    template<typename U>
    Angle<T>::Angle(const Angle<U>& copy)
    {
        set(copy);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator=(Angle<U> angle)
    {
        return set(angle);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator=(U angle)
    {
        return set(angle);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::set(Angle<U> angle)
    {
        m_value    = static_cast<T>(angle.m_value);
        m_isRadian = angle.m_isRadian;

        return (*this);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::set(U angle)
    {
        m_value = static_cast<T>(angle);

        return (*this);
    }

    template<typename T>
    Angle<T> Angle<T>::asDegree() const
    {
        return Angle<T>(m_isRadian ? m_value * (static_cast<T>(180.0) / Pi) : m_value, false);
    }

    template<typename T>
    Angle<T> Angle<T>::asRadian() const
    {
        return Angle<T>(m_isRadian ? m_value : m_value * (Pi / static_cast<T>(180.0)), true);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator+(U right)
    {
        return Angle<T>((*this)) += Angle(right, m_isRadian);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator+(const Angle<U>& right)
    {
        return Angle<T>((*this)) += right;
    }

    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator+=(U right)
    {
        m_value += static_cast<T>(right);

        return (*this);
    }

    template<typename T>    template<typename U>
    Angle<T>& Angle<T>::operator+=(const Angle<U>& right)
    {
        m_value += static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator-(U right)
    {
        return Angle<T>((*this)) -= Angle(right, m_isRadian);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator-(const Angle<U>& right)
    {
        return Angle<T>((*this)) -= right;
    }

    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator-=(U right)
    {
        m_value -= static_cast<T>(right);

        return (*this);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator-=(const Angle<U>& right)
    {
        m_value -= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    template<typename T>    template<typename U>
    Angle<T> Angle<T>::operator*(U right)
    {
        return Angle<T>((*this)) *= Angle(right, m_isRadian);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator*(const Angle<U>& right)
    {
        return Angle<T>((*this)) *= right;
    }

    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator*=(U right)
    {
        m_value *= static_cast<T>(right);

        return (*this);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator*=(const Angle<U>& right)
    {
        m_value *= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    template<typename T>    template<typename U>
    Angle<T> Angle<T>::operator/(U right)
    {
        return Angle<T>((*this)) /= Angle(right, m_isRadian);
    }

    template<typename T>
    template<typename U>
    Angle<T> Angle<T>::operator/(const Angle<U>& right)
    {
        return Angle<T>((*this)) /= right;
    }

    template<typename T>
    template<typename U>    Angle<T>& Angle<T>::operator/=(U right)
    {
        m_value /= static_cast<T>(right);

        return (*this);
    }

    template<typename T>
    template<typename U>
    Angle<T>& Angle<T>::operator/=(const Angle<U>& right)
    {
        m_value /= static_cast<T>(m_isRadian ? right.asRadian() : right.asDegree());

        return (*this);
    }

    template<typename T>    Angle<T>::operator T() const
    {
        return m_value;
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
