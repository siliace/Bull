#ifndef BULL_UTILITY_EXPORT_HPP
#define BULL_UTILITY_EXPORT_HPP

#include <Bull/Core/System/Export.hpp>

#if defined BULL_BUILD
    #define BULL_UTILITY_API BULL_API_EXPORT
#else
    #define BULL_UTILITY_API BULL_API_IMPORT
#endif

#endif // BULL_UTILITY_EXPORT_HPP
