#ifndef BULL_CORE_CONFIGURATION_MACRO_HPP
#define BULL_CORE_CONFIGURATION_MACRO_HPP

#ifndef BULL_ZERO_MEMORY
    #ifndef BULL_HAS_CSTRING
        #include <cstring>
        #define BULL_HAS_CSTRING
    #endif
    #define BULL_ZERO_MEMORY(Object) std::memset(&(Object), 0, sizeof(decltype(Object)))
#endif

#ifndef BULL_ZERO_MEMORY_PTR
    #ifndef BULL_HAS_CSTRING
        #include <cstring>
        #define BULL_HAS_CSTRING
    #endif
    #define BULL_ZERO_MEMORY_PTR(Pointer, Length) std::memset(Pointer, 0, Length)
#endif

#ifndef BULL_UNUSED
    #define BULL_UNUSED(Variable) (void)Variable
#endif

#endif // BULL_CORE_CONFIGURATION_MACRO_HPP
