#ifndef BULL_RENDER_CONTEXT_GLX_GLXEXTENSIONSLOADER_HPP
#define BULL_RENDER_CONTEXT_GLX_GLXEXTENSIONSLOADER_HPP

#include <vector>

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Context/SurfaceHandler.hpp>

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

#endif // BULL_RENDER_CONTEXT_GLX_GLXEXTENSIONSLOADER_HPP
