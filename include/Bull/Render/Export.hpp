#ifndef BULL_RENDER_EXPORT_HPP
#define BULL_RENDER_EXPORT_HPP

#include <Bull/Core/System/Export.hpp>

#if defined BULL_BUILD
    #define BULL_RENDER_API BULL_API_EXPORT
#else
    #define BULL_RENDER_API BULL_API_IMPORT
#endif

#endif // BULL_RENDER_EXPORT_HPP
