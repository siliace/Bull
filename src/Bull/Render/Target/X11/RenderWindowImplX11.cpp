#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Target/X11/RenderWindowImplX11.hpp>

#include <Bull/Window/X11/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        RenderWindowImplX11::RenderWindowImplX11(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            XVisualInfo*         vi;
            GLXFBConfig          config;
            ErrorHandler         handler;
            XSetWindowAttributes attributes;

            config = GlxContext::chooseBestConfig(m_display, settings, mode.bitsPerPixel);

            vi = glXGetVisualFromFBConfig(m_display, config);

            m_colormap = XCreateColormap(m_display,
                                         m_display.getRootWindow(vi->screen),
                                         vi->visual,
                                         AllocNone);

            attributes.border_pixel      = 0;
            attributes.background_pixmap = XNone;
            attributes.colormap          = m_colormap;
            attributes.event_mask        = WindowImplX11::EventsMasks;

            m_handler = XCreateWindow(m_display,
                                      m_display.getRootWindow(vi->screen),
                                      0, 0,
                                      mode.width, mode.height,
                                      0,
                                      vi->depth,
                                      InputOutput,
                                      vi->visual,
                                      CWColormap | CWEventMask | CWBorderPixel,
                                      &attributes);

            if(m_handler == 0)
            {
                throw std::runtime_error("Failed to create window");
            }

            setProtocols();

            setTitle(title);

            m_lastSize     = getSize();
            m_lastPosition = getPosition();

            setVisible(true);
        }
    }
}