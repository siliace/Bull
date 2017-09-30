#ifndef BULL_MATH_CONSTANTS_HPP
#define BULL_MATH_CONSTANTS_HPP

#include <cmath>

namespace Bull
{
    constexpr float Pi = std::acos(-1.f);

    constexpr float Pi2 = Pi / 2.f;

    constexpr float Pi3 = Pi / 3.f;

    constexpr float PiPow2 = std::pow(Pi, 2.f);

    constexpr float PiPow3 = std::pow(Pi, 3.f);

    constexpr float Sqrt2 = std::sqrt(2.f);

    constexpr float Sqrt3 = std::sqrt(3.f);
}

#endif // BULL_MATH_CONSTANTS_HPP
