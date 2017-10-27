#ifndef BULL_CORE_META_OPERATORS_HPP
#define BULL_CORE_META_OPERATORS_HPP

namespace Bull
{
    template <typename T, T left, T right>
    struct Add
    {
        static constexpr T Value = left + right;
    };

    template <typename T, T left, T right>
    struct Subtract
    {
        static constexpr T Value = left - right;
    };

    template <typename T, T left, T right>
    struct Multiply
    {
        static constexpr T Value = left * right;
    };

    template <typename T, T left, T right>
    struct Divide
    {
        static constexpr T Value = left / right;
    };

    template <typename T, T left, T right>
    struct Equal
    {
        static constexpr bool Value = left == right;
    };

    template <typename T, T left, T right>
    struct NotEqual
    {
        static constexpr bool Value = left != right;
    };

    template <typename T, T left, T right>
    struct Greater
    {
        static constexpr bool Value = left > right;
    };

    template <typename T, T left, T right>
    struct Lower
    {
        static constexpr bool Value = left < right;
    };

    template <typename T, T left, T right>
    struct GreaterOrEqual
    {
        static constexpr bool Value = Greater<T, left, right>::Value | Equal<T, left, right>::Value;
    };

    template <typename T, T left, T right>
    struct LowerOrEqual
    {
        static constexpr bool Value = Lower<T, left, right>::Value | Equal<T, left, right>::Value;
    };
}

#endif // BULL_CORE_META_OPERATORS_HPP
