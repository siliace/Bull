#include <GL/glx.h>

#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        std::vector<std::string> GlxExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            return std::string(glXQueryExtensionsString(Display::getInstance().getHandler(), handler)).explode(' ');
        }
    }
}
