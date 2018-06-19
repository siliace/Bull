#ifndef BULL_CORE_UTILITY_FUNCTION_HPP
#define BULL_CORE_UTILITY_FUNCTION_HPP

#include <functional>

namespace Bull
{
    template <typename T>
    using Provider = std::function<T()>;

    template <typename T>
    using Consumer = std::function<void(T)>;
}

#endif // BULL_CORE_UTILITY_FUNCTION_HPP
