#include <GL/glx.h>

#include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>

#include <Bull/Utility/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get a list of supported extensions
         *
         * \param handler The surface to use to check whether an extension is supported
         *
         * \return Return the list
         *
         */
        std::vector<String> GlxExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            return String(glXQueryExtensionsString(Display::get()->getHandler(), handler)).explode(' ');
        }
    }
}
