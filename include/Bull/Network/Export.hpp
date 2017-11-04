#ifndef BULL_NETWORK_EXPORT_HPP
#define BULL_NETWORK_EXPORT_HPP

#include <Bull/Core/Configuration/Export.hpp>

#if defined BULL_BUILD
    #define BULL_NETWORK_API BULL_API_EXPORT
#else
    #define BULL_NETWORK_API BULL_API_IMPORT
#endif

#endif // BULL_NETWORK_EXPORT_HPP

