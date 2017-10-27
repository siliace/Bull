#ifndef BULL_CORE_META_ENABLEIFBASEOF_HPP
#define BULL_CORE_META_ENABLEIFBASEOF_HPP

#include <utility>

namespace Bull
{
    template <typename B, typename T>
    using EnableIfBaseOf = std::enable_if<std::is_base_of<B, T>::value>;

    template <typename B, typename T>
    using EnableIfBaseOfOrConvertible = std::enable_if<std::is_base_of<B, T>::value | std::is_convertible<B, T>::value>;
}

#endif // BULL_CORE_META_ENABLEIFBASEOF_HPP
