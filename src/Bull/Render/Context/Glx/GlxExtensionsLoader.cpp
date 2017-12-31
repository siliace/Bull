#include <GL/glx.h>

#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        std::vector<String> GlxExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            return String(glXQueryExtensionsString(Display::getInstance()->getHandler(), handler)).explode(' ');
        }
    }
}
