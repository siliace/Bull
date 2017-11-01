#include <cmath>

namespace Bull
{
    template <typename T, std::size_t S>
    Vector<T, S> Vector<T, S>::normalize(const Vector<T, S>& vector)
    {
        return Vector<T, S>(vector).normalize();
    }

    template <typename T, std::size_t S>
    T Vector<T, S>::dotProduct(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left).dotProduct(right);
    }

    template <typename T, std::size_t S>
    Vector<T, S>::Vector() :
        Vector<T, S>(0)
    {
        /// Nothing
    }

    template <typename T, std::size_t S>
    Vector<T, S>::Vector(T value)
    {
        m_components.fill(value);
    }

    template <typename T, std::size_t S>
    template <typename U, std::size_t US>
    Vector<T, S>::Vector(const Vector<U, US>& copy) :
        Vector<T, S>()
    {
        for(std::size_t i = 0; i < std::min(S, US); i++)
        {
            at(i) = static_cast<T>(copy.at(i));
        }
    }

    template <typename T, std::size_t S>
    template <typename U, std::size_t US>
    Vector<T, S>& Vector<T, S>::operator=(const Vector<U, US>& copy)
    {
        m_components.fill(0);

        for(std::size_t i = 0; i < std::min(S, US); i++)
        {
            at(i) = static_cast<T>(copy.at(i));
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::set(T value)
    {
        m_components.fill(value);

        return (*this);
    }

    template <typename T, std::size_t S>
    float Vector<T, S>::getLength() const
    {
        float length = 0;

        for(T component : m_components)
        {
            length += std::pow(component, 2);
        }

        return std::sqrt(length);
    }

    template <typename T, std::size_t S>
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

    template <typename T, std::size_t S>
    T Vector<T, S>::dotProduct(const Vector<T, S>& right) const
    {
        float sum = 0;

        for(std::size_t i = 0; i < S; i++)
        {
            sum += at(i) * right.at(i);
        }

        return sum;
    }

    template <typename T, std::size_t S>
    bool Vector<T, S>::operator==(const Vector<T, S>& right) const
    {
        return m_components == right.m_components;
    }

    template <typename T, std::size_t S>
    bool Vector<T, S>::operator!=(const Vector<T, S>& right) const
    {
        return m_components != right.m_components;
    }

    template <typename T, std::size_t S>
    T& Vector<T, S>::at(std::size_t index)
    {
        RangeCheck(index, S);

        return m_components.at(index);
    }

    template <typename T, std::size_t S>
    const T& Vector<T, S>::at(std::size_t index) const
    {
        RangeCheck(index, S);

        return m_components.at(index);
    }

    template <typename T, std::size_t S>
    Vector<T, S> Vector<T, S>::operator-() const
    {
        Vector<T, S> negation;

        for(std::size_t i = 0; i < S; i++)
        {
            negation.at(i) = -at(i);
        }

        return negation;
    };

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator+=(T right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) += right;
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator+=(const Vector<T, S>& right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) += right.at(i);
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator-=(T right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) -= right;
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator-=(const Vector<T, S>& right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) -= right.at(i);
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator*=(T right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) *= right;
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator*=(const Vector<T, S>& right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) *= right.at(i);
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator/=(T right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) /= right;
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S>& Vector<T, S>::operator/=(const Vector<T, S>& right)
    {
        for(std::size_t i = 0; i < S; i++)
        {
            at(i) /= right.at(i);
        }

        return (*this);
    }

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator+(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) += right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator-(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) -= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator*(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) *= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(T left, const Vector<T, S>& right)
    {
        return Vector<T, S>(left) /= right;
    };

    template <typename T, std::size_t S>
    Vector<T, S> operator/(const Vector<T, S>& left, T right)
    {
        return Vector<T, S>(left) /= right;
    };
}