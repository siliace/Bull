#ifndef BULL_SYSTEM_EXPORT_HPP
#define BULL_SYSTEM_EXPORT_HPP

#include <Bull/Core/Configuration/Export.hpp>

#if defined BULL_BUILD
    #define BULL_SYSTEM_API BULL_API_EXPORT
#else
    #define BULL_SYSTEM_API BULL_API_IMPORT
#endif

#endif // BULL_SYSTEM_EXPORT_HPP
