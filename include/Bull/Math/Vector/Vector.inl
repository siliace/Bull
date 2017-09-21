#include <cmath>

namespace Bull
{
    template <typename T, Index S>
    Vector<T, S> Vector<T, S>::normalize(const Vector<T, S>& vector)
    {
        return Vector<T, S>(vector).normalize();
    }

    template <typename T, Index S>
    T Vector<T, S>::dotProduct(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left).dotProduct(right);
    }

    template <typename T, Index S>
    Vector<T, S>::Vector() :
        Vector<T, S>(0)
    {
        /// Nothing
    }

    template <typename T, Index S>
    Vector<T, S>::Vector(T value)
    {
        m_components.fill(value);
    }

    template <typename T, Index S>
    template <typename U, Index US>
    Vector<T, S>::Vector(const Vector<U, US>& copy) :
        Vector<T, S>()
    {
        for(Index i = 0; i < std::min(S, US); i++)
        {
            at(i) = static_cast<T>(copy.at(i));
        }
    }

    template <typename T, Index S>
    template <typename U, Index US>
    Vector<T, S>& Vector<T, S>::operator=(const Vector<U, US>& copy)
    {
        m_components.fill(0);

        for(Index i = 0; i < std::min(S, US); i++)
        {
            at(i) = static_cast<T>(copy.at(i));
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::set(T value)
    {
        m_components.fill(value);

        return (*this);
    }

    template <typename T, Index S>
    float Vector<T, S>::getLength() const
    {
        float length = 0;

        for(T component : m_components)
        {
            length += std::pow(component, 2);
        }

        return std::sqrt(length);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::normalize()
    {
        float length = getLength();

        if(length > 1.f)
        {
            for(T& component : m_components)
            {
                component /= length;
            }
        }

        return (*this);
    }

    template <typename T, Index S>
    T Vector<T, S>::dotProduct(const Vector<T, S>& right) const
    {
        float sum = 0;

        for(Index i = 0; i < S; i++)
        {
            sum += at(i) * right.at(i);
        }

        return sum;
    }

    template <typename T, Index S>
    bool Vector<T, S>::operator==(const Vector<T, S>& right) const
    {
        return m_components == right.m_components;
    }

    template <typename T, Index S>
    bool Vector<T, S>::operator!=(const Vector<T, S>& right) const
    {
        return m_components != right.m_components;
    }

    template <typename T, Index S>
    T& Vector<T, S>::at(Index index)
    {
        RangeCheck(index, S);

        return m_components.at(index);
    }

    template <typename T, Index S>
    const T& Vector<T, S>::at(Index index) const
    {
        RangeCheck(index, S);

        return m_components.at(index);
    }

    template <typename T, Index S>
    Vector<T, S> Vector<T, S>::operator-() const
    {
        Vector<T, S> negation;

        for(Index i = 0; i < S; i++)
        {
            negation.at(i) = -at(i);
        }

        return negation;
    };

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator+=(T right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) += right;
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator+=(const Vector<T, S>& right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) += right.at(i);
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator-=(T right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) -= right;
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator-=(const Vector<T, S>& right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) -= right.at(i);
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator*=(T right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) *= right;
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator*=(const Vector<T, S>& right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) *= right.at(i);
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator/=(T right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) /= right;
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S>& Vector<T, S>::operator/=(const Vector<T, S>& right)
    {
        for(Index i = 0; i < S; i++)
        {
            at(i) /= right.at(i);
        }

        return (*this);
    }

    template <typename T, Index S>
    Vector<T, S> operator+(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, Index S>
    Vector<T, S> operator+(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, Index S>
    Vector<T, S> operator+(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, Index S>
    Vector<T, S> operator-(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator-(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator-(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator*(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator*(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator*(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator/(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator/(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, Index S>
    Vector<T, S> operator/(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) /= right;
    };
}