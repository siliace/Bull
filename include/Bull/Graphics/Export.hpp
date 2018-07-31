#ifndef BULL_GRAPHICS_EXPORT_HPP
#define BULL_GRAPHICS_EXPORT_HPP

#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_BUILD
    #define BULL_GRAPHICS_API BULL_API_EXPORT
#else
    #define BULL_GRAPHICS_API BULL_API_IMPORT
#endif

#endif // BULL_GRAPHICS_EXPORT_HPP

