#ifndef Bull_GlxExtensionsLoader_hpp
#define Bull_GlxExtensionsLoader_hpp

#include <vector>

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Window/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        struct GlxExtensionsLoader
        {
            /*! \brief Get a list of supported extensions
             *
             * \param handler The surface to use to check whether an extension is supported
             *
             * \return Return the list
             *
             */
            static std::vector<String> getExtensions(SurfaceHandler handler);
        };
    }
}

#endif // Bull_GlxExtensionsLoader_hpp
