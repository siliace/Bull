#include <GL/glx.h>

#include <Bull/Core/Support/X11/Display.hpp>

#include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>

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
