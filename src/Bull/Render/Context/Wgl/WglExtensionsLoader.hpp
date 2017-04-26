#ifndef Bull_WglExtensionsLoader_hpp
#define Bull_WglExtensionsLoader_hpp

#include <vector>

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Context/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        struct WglExtensionsLoader
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

#endif // Bull_WglExtensionsLoader_hpp
