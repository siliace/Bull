#ifndef BULL_WINDOW_EXPORT_HPP
#define BULL_WINDOW_EXPORT_HPP

#include <Bull/Core/System/Export.hpp>

#if defined BULL_BUILD
    #define BULL_WINDOW_API BULL_API_EXPORT
#else
    #define BULL_WINDOW_API BULL_API_IMPORT
#endif

#endif // BULL_WINDOW_EXPORT_HPP
