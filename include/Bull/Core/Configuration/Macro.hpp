#ifndef BULL_CORE_CONFIGURATION_MACRO_HPP
#define BULL_CORE_CONFIGURATION_MACRO_HPP

#include <cstring>

#ifndef ZeroMemory
    #define ZeroMemory(Object) std::memset(&Object, 0, sizeof(decltype(Object)))
#endif

#ifndef ZeroMemoryPtr
    #define ZeroMemoryPtr(Pointer, Length) std::memset(Pointer, 0, Length)
#endif

#endif // BULL_CORE_CONFIGURATION_MACRO_HPP
