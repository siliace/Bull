#ifndef BULL_MATH_NORMALIZE_HPP
#define BULL_MATH_NORMALIZE_HPP

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Quaternion.hpp>

namespace Bull
{
    template <typename T>
    Angle<T> normalize(const Angle<T>& angle)
    {
        return Angle<T>::normalize(angle);
    }

    template <typename T>
    EulerAngles<T> normalize(const EulerAngles<T>& eulerAngles)
    {
        return EulerAngles<T>::normalize(eulerAngles);
    }

    template <typename T>
    Quaternion<T> normalize(const Quaternion<T>& quaternion)
    {
        return Quaternion<T>::normalize(quaternion);
    }
}

#endif // BULL_MATH_NORMALIZE_HPP
