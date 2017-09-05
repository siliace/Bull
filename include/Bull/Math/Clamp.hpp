#ifndef BULL_MATH_CLAMP_HPP
#define BULL_MATH_CLAMP_HPP

#include <type_traits>

#include <Bull/Math/Angle.hpp>

namespace Bull
{
    template <typename T>
    Angle<T> clamp(const Angle<T>& angle, const Angle<T>& min, const Angle<T>& max)
    {
        return Angle<T>::clamp(angle, min, max);
    }

    template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
    T clamp(T value, T min, T max)
    {
        if(value < min)
        {
            return min;
        }
        else if(value > max)
        {
            return max;
        }

        return value;
    };
}

#endif // BULL_MATH_CLAMP_HPP
