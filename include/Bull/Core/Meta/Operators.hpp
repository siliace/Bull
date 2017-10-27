#ifndef BULL_CORE_META_OPERATORS_HPP
#define BULL_CORE_META_OPERATORS_HPP

namespace Bull
{
    template <T, T left, T right>
    struct Add
    {
        static constexpr T value = left + right;
    };

    template <T, T left, T right>
    struct Subtract
    {
        static constexpr T value = left - right;
    };

    template <T, T left, T right>
    struct Multiply
    {
        static constexpr T value = left * right;
    };

    template <T, T left, T right>
    struct Divide
    {
        static constexpr T value = left / right;
    };

    template <T, T left, T right>
    struct Equal
    {
        static constexpr bool value = left == right;
    };

    template <T, T left, T right>
    struct NotEqual
    {
        static constexpr bool value = left != right;
    };

    template <T, T left, T right>
    struct Greater
    {
        static constexpr bool value = left > right;
    };

    template <T, T left, T right>
    struct Lower
    {
        static constexpr bool value = left < right;
    };

    template <T, T left, T right>
    struct GreaterOrEqual
    {
        static constexpr bool value = Greater<T, left, right> | Equal<T, left, right>;
    };

    template <T, T left, T right>
    struct LowerOrEqual
    {
        static constexpr bool value = Lower<T, left, right> | Equal<T, left, right>;
    };
}

#endif // BULL_CORE_META_OPERATORS_HPP
