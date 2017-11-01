#ifndef BULL_CORE_CONFIGURATION_MACRO_HPP
#define BULL_CORE_CONFIGURATION_MACRO_HPP

#include <cstring>

#ifndef BULL_ZERO_MEMORY
    #define BULL_ZERO_MEMORY(Object) std::memset(&Object, 0, sizeof(decltype(Object)))
#endif

#ifndef BULL_ZERO_MEMORY_PTR
    #define BULL_ZERO_MEMORY_PTR(Pointer, Length) std::memset(Pointer, 0, Length)
#endif

#endif // BULL_CORE_CONFIGURATION_MACRO_HPP
