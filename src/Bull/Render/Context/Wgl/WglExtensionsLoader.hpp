#ifndef BULL_RENDER_CONTEXT_WGL_WGLEXTENSIONSLOADER_HPP
#define BULL_RENDER_CONTEXT_WGL_WGLEXTENSIONSLOADER_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Context/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class WglExtensionsLoader
        {
        public:

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

#endif // BULL_RENDER_CONTEXT_WGL_WGLEXTENSIONSLOADER_HPP
