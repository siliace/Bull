#ifndef BULL_CORE_EXPORT_HPP
#define BULL_CORE_EXPORT_HPP

#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_BUILD
    #define BULL_CORE_API BULL_API_EXPORT
#else
    #define BULL_CORE_API BULL_API_IMPORT
#endif

#endif // BULL_CORE_EXPORT_HPP
