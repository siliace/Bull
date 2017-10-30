#ifndef BULL_CORE_META_TYPETRAIT_HPP
#define BULL_CORE_META_TYPETRAIT_HPP

#include <limits>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename T>
    using IsInteger = std::is_integral<T>;

    template <typename T>
    using IsFloatingPoint = std::is_floating_point<T>;

    template <typename T>
    using IsNumber = std::is_arithmetic<T>;

    template <typename T>
    using EnableIfIsNumber = std::enable_if<IsNumber<T>::value>;

    template <typename B, typename T>
    using EnableIfBaseOf = std::enable_if<std::is_base_of<B, T>::value>;

    template <typename B, typename T>
    using EnableIfBaseOfOrConvertible = std::enable_if<std::is_base_of<B, T>::value | std::is_convertible<B, T>::value>;

    template <typename T, typename = EnableIfIsNumber<T>>
    struct BULL_CORE_API Min
    {
        static constexpr T Value = std::numeric_limits<T>::min();
    };

    template <typename T, typename = EnableIfIsNumber<T>>
    struct BULL_CORE_API Max
    {
        static constexpr T Value = std::numeric_limits<T>::max();
    };
}

#endif // BULL_CORE_META_TYPETRAIT_HPP
