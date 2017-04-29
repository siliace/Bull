#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Target/X11/RenderWindowImplX11.hpp>

namespace Bull
{
    namespace prv
    {
        RenderWindowImplX11::RenderWindowImplX11(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            XVisualInfo* vi;
            GLXFBConfig  config;
            Display      display;

            config = GlxContext::chooseBestConfig(display, settings, mode.bitsPerPixel);

            vi = glXGetVisualFromFBConfig(display, config);

            open(mode.width, mode.height, title, style, vi);
        }
    }
}