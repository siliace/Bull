namespace Bull
{
    template <typename T>
    Angle<T> Angle<T>::degree(T value)
    {
        return Angle<T>(value, false);
    }

    template <typename T>
    Angle<T> Angle<T>::radian(T value)
    {
        return Angle<T>(value, true);
    }

    template <typename T>
    Angle<T> Angle<T>::toDegree(const Angle<T>& angle)
    {
        return Angle<T>(angle).toDegree();
    }

    template <typename T>
    Angle<T> Angle<T>::toRadian(const Angle<T>& angle)
    {
        return Angle<T>(angle).toRadian();
    }

    template <typename T>
    Angle<T> Angle<T>::normalize(const Angle<T>& angle)
    {
        return Angle<T>(angle).normalize();
    }

    template <typename T>
    Angle<T> Angle<T>::clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max)
    {
        if(angle < min)
        {
            return min;
        }
        else if(angle > max)
        {
            return max;
        }

        return angle;
    }

    template <typename T>
    Angle<T>::Angle() :
        m_angle(0.0),
        m_isRadian(false)
    {
        /// Nothing
    }

    template <typename T>
    Angle<T>& Angle<T>::toRadian()
    {
        if(!m_isRadian)
        {
            m_isRadian = true;
            m_angle    = (m_angle * Pi) / 180.0;
        }

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::toDegree()
    {
        if(m_isRadian)
        {
            m_isRadian = true;
            m_angle    = (m_angle * 180.0) / Pi;
        }

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::normalize()
    {
        m_angle /= m_isRadian ? 2 * Pi : 360.0;

        return (*this);
    }

    template <typename U>
    bool operator==(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle == Angle<U>::toDegree().m_angle;
    }

    template <typename U>
    bool operator==(U left, const Angle<U>& right)
    {
        return left == right.m_angle;
    }

    template <typename U>
    bool operator==(const Angle<U>& left, U right)
    {
        return left.m_angle == right;
    }

    template <typename U>
    bool operator!=(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle != Angle<U>::toDegree().m_angle;
    }

    template <typename U>
    bool operator!=(U left, const Angle<U>& right)
    {
        return left != right.m_angle;
    }

    template <typename U>
    bool operator!=(const Angle<U>& left, U right)
    {
        return left.m_angle != right;
    }

    template <typename U>
    bool operator<(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle < Angle<U>::toDegree(right).m_angle;
    }

    template <typename U>
    bool operator<(U left, const Angle<U>& right)
    {
        return left < right.m_angle;
    }

    template <typename U>
    bool operator<(const Angle<U>& left, U right)
    {
        return left.m_angle < right;
    }

    template <typename U>
    bool operator<=(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle <= Angle<U>::toDegree(right).m_angle;
    }

    template <typename U>
    bool operator<=(U left, const Angle<U>& right)
    {
        return left <= right.m_angle;
    }

    template <typename U>
    bool operator<=(const Angle<U>& left, U right)
    {
        return left.m_angle <= right;
    }

    template <typename U>
    bool operator>(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle > Angle<U>::toDegree(right).m_angle;
    }

    template <typename U>
    bool operator>(U left, const Angle<U>& right)
    {
        return left > right.m_angle;
    }

    template <typename U>
    bool operator>(const Angle<U>& left, U right)
    {
        return left.m_angle > right;
    }

    template <typename U>
    bool operator>=(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::toDegree(left).m_angle >= Angle<U>::toDegree(right).m_angle;
    }

    template <typename U>
    bool operator>=(U left, const Angle<U>& right)
    {
        return left >= right.m_angle;
    }

    template <typename U>
    bool operator>=(const Angle<U>& left, U right)
    {
        return left.m_angle >= right;
    }

    template <typename U>
    Angle<U> operator+(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::degree(Angle<U>::toDegree(left).m_angle + Angle<U>::toDegree(right).m_angle);
    }

    template <typename U>
    Angle<U> operator+(U left, const Angle<U>& right)
    {
        return Angle<U>(left + right.m_angle, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator+(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_angle + right, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator-(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::degree(Angle<U>::toDegree(left).m_angle - Angle<U>::toDegree(right).m_angle);
    }

    template <typename U>
    Angle<U> operator-(U left, const Angle<U>& right)
    {
        return Angle<U>(left - right.m_angle, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator-(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_angle - right, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator*(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::degree(Angle<U>::toDegree(left).m_angle * Angle<U>::toDegree(right).m_angle);
    }

    template <typename U>
    Angle<U> operator*(U left, const Angle<U>& right)
    {
        return Angle<U>(left * right.m_angle, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator*(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_angle * right, left.m_isRadian);
    }

    template <typename U>
    Angle<U> operator/(const Angle<U>& left, const Angle<U>& right)
    {
        return Angle<U>::degree(Angle<U>::toDegree(left).m_angle / Angle<U>::toDegree(right).m_angle);
    }

    template <typename U>
    Angle<U> operator/(U left, const Angle<U>& right)
    {
        return Angle<U>(left / right.m_angle, right.m_isRadian);
    }

    template <typename U>
    Angle<U> operator/(const Angle<U>& left, U right)
    {
        return Angle<U>(left.m_angle / right, left.m_isRadian);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator+=(T right)
    {
        m_angle += right;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator+=(const Angle<T>& right)
    {
        m_angle += m_isRadian ? Angle<T>::toRadian(right).m_angle : Angle<T>::toDegree(right).m_angle;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator-=(T right)
    {
        m_angle -= right;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator-=(const Angle<T>& right)
    {
        m_angle -= m_isRadian ? Angle<T>::toRadian(right).m_angle : Angle<T>::toDegree(right).m_angle;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator*=(T right)
    {
        m_angle *= right;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator*=(const Angle<T>& right)
    {
        m_angle *= m_isRadian ? Angle<T>::toRadian(right).m_angle : Angle<T>::toDegree(right).m_angle;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator/=(T right)
    {
        m_angle /= right;

        return (*this);
    }

    template <typename T>
    Angle<T>& Angle<T>::operator/=(const Angle<T>& right)
    {
        m_angle /= m_isRadian ? Angle<T>::toRadian(right).m_angle : Angle<T>::toDegree(right).m_angle;

        return (*this);
    }

    template <typename T>
    Angle<T>::Angle(T value, bool isRadian) :
        m_angle(value),
        m_isRadian(isRadian)
    {
        /// Nothing
    }
}

namespace std
{
    template <typename U>
    float cos(const Bull::Angle<U>& angle)
    {
        return std::cos(Bull::Angle<U>::toRadian(angle).m_angle);
    }

    template <typename U>
    float sin(const Bull::Angle<U>& angle)
    {
        return std::sin(Bull::Angle<U>::toRadian(angle).m_angle);
    }

    template <typename U>
    float tan(const Bull::Angle<U>& angle)
    {
        return std::tan(Bull::Angle<U>::toRadian(angle).m_angle);
    }
}