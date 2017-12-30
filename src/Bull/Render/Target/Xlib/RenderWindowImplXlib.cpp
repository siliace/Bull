#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Target/Xlib/RenderWindowImplXlib.hpp>

namespace Bull
{
    namespace prv
    {
        RenderWindowImplXlib::RenderWindowImplXlib(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            XVisualInfo*      vi;
            GLXFBConfig       config;
            Display::Instance display = Display::getInstance();

            config = GlxContext::chooseBestConfig(display, settings, mode.bitsPerPixel);

            vi = glXGetVisualFromFBConfig(display->getHandler(), config);

            open(mode.width, mode.height, title, style, vi);
        }
    }
}