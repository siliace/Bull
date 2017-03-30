#include <GL/glx.h>

#include <Bull/Window/X11/GlxExtensionsLoader.hpp>

#include <Bull/Window/X11/Display.hpp>

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
