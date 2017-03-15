#include <GL/glx.h>

#include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>

#include <Bull/Utility/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        std::vector<String> GlxExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            return String(glXQueryExtensionsString(Display(), handler)).explode(' ');
        }
    }
}
