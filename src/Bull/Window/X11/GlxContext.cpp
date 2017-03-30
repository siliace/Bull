#include <limits>

#include <Bull/Core/Log/Log.hpp>

#include <Bull/Window/X11/GlxContext.hpp>
#include <Bull/Window/X11/GlxCreateContextARB.hpp>
#include <Bull/Window/X11/GlxPBufferSGIX.hpp>
#include <Bull/Window/X11/GlxSwapControlEXT.hpp>
#include <Bull/Window/X11/GlxSwapControlMESA.hpp>
#include <Bull/Window/X11/GlxSwapControlSGI.hpp>

#include <Bull/Window/X11/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        void* GlxContext::getFunction(const String& function)
        {
            return reinterpret_cast<void*>(glXGetProcAddressARB(reinterpret_cast<const unsigned char*>(static_cast<const char*>(function))));
        }

        void GlxContext::requireExtensions(const ExtensionsLoader::Instance& loader)
        {
            loader->require(GlxCreateContextARB);
            loader->require(GlxPbuffer);

            if(isSupported(GlxSwapControlEXT))
            {
                loader->require(GlxSwapControlEXT);
            }
            else if(isSupported(GlxSwapControlMESA))
            {
                loader->require(GlxSwapControlMESA);
            }
            else if(isSupported(GlxSwapControlSGI))
            {
                loader->require(GlxSwapControlSGI);
            }
        }

        GLXFBConfig GlxContext::chooseBestConfig(Display display, const ContextSettings& settings, unsigned int bitsPerPixel)
        {
            int fbCounts = 0;
            GLXFBConfig config;
            ErrorHandler handler;
            GLXFBConfig* configs = nullptr;
            unsigned int antialiasing = settings.antialiasing;
            int bestConfig = 0, bestScore = std::numeric_limits<int>::max();

            while(fbCounts == 0)
            {
                int attributes[] =
                {
                    GLX_X_RENDERABLE  , True,
                    GLX_DRAWABLE_TYPE , GLX_WINDOW_BIT,
                    GLX_RENDER_TYPE   , GLX_RGBA_BIT,
                    GLX_X_VISUAL_TYPE , GLX_TRUE_COLOR,
                    GLX_BUFFER_SIZE   , static_cast<int>(bitsPerPixel),
                    GLX_ALPHA_SIZE    , bitsPerPixel == 32 ? 8 : 0,
                    GLX_DEPTH_SIZE    , settings.depths,
                    GLX_STENCIL_SIZE  , settings.stencil,
                    GLX_DOUBLEBUFFER  , True,
                    GLX_SAMPLE_BUFFERS, antialiasing > 0 ? True : False,
                    GLX_SAMPLES       , static_cast<int>(antialiasing),
                    0
                };

                configs = glXChooseFBConfig(display, display.getDefaultScreen(), attributes, &fbCounts);

                if(fbCounts == 0)
                {
                    antialiasing /= 2;
                }
            }

            for(int i = 0; i < fbCounts; i++)
            {
                XVisualInfo* vi = glXGetVisualFromFBConfig(display, configs[i]);

                if(vi)
                {
                    int depths, stencil;
                    int sampleBuffers, samples;
                    int red, green, blue, alpha;

                    glXGetFBConfigAttrib(display, configs[i], GLX_RED_SIZE,   &red);
                    glXGetFBConfigAttrib(display, configs[i], GLX_GREEN_SIZE, &green);
                    glXGetFBConfigAttrib(display, configs[i], GLX_BLUE_SIZE,  &blue);
                    glXGetFBConfigAttrib(display, configs[i], GLX_ALPHA_SIZE, &alpha);

                    glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sampleBuffers);
                    glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES,        &samples);

                    glXGetFBConfigAttrib(display, configs[i], GLX_DEPTH_SIZE,   &depths);
                    glXGetFBConfigAttrib(display, configs[i], GLX_STENCIL_SIZE, &stencil);

                    int currentBitsPerPixel = red + green + blue + alpha;
                    int score = evaluatePixelFormat(currentBitsPerPixel, depths, stencil, sampleBuffers ? samples : 0, bitsPerPixel, settings);

                    if(bestScore > score)
                    {
                        bestScore  = score;
                        bestConfig = i;
                    }
                }
            }

            config = configs[bestConfig];

            XFree(configs);

            return config;
        }

        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared) :
            GlxContext(shared, VideoMode(1, 1), ContextSettings())
        {
            /// Nothing
        }

        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, const VideoMode& mode, const ContextSettings& settings) :
            GlContext(settings),
            m_window(0),
            m_render(0),
            m_config(nullptr),
            m_pbuffer(0),
            m_colormap(0),
            m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, mode.bitsPerPixel);

            createSurface(shared, mode.width, mode.height, mode.bitsPerPixel);

            if(m_window || m_pbuffer)
            {
                createContext(shared);
            }
        }

        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, unsigned int bitsPerPixel, const ContextSettings& settings) :
            GlxContext(shared, VideoMode(1, 1, bitsPerPixel), settings)
        {
            /// Nothing
        }

        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings) :
            GlContext(settings),
            m_window(0),
            m_render(0),
            m_config(nullptr),
            m_pbuffer(0),
            m_colormap(0),
            m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, bitsPerPixel);

            createSurface(window, bitsPerPixel);

            if(m_window)
            {
                createContext(shared);
            }
        }

        GlxContext::~GlxContext()
        {
            ErrorHandler handler;

            if(m_render)
            {
                if(glXGetCurrentContext() == m_render)
                {
                    glXMakeCurrent(m_display, XNone, nullptr);
                }

                glXDestroyContext(m_display, m_render);
            }

            if(m_pbuffer)
            {
                glXDestroyPbuffer(m_display, m_pbuffer);
            }

            if(m_ownWindow && m_window)
            {
                XFreeColormap(m_display, m_colormap);
                XDestroyWindow(m_display, m_window);

                m_display.flush();
            }
        }

        void GlxContext::display()
        {
            ErrorHandler handler;

            if(m_window)
            {
                glXSwapBuffers(m_display, m_window);
            }
            else if(m_pbuffer)
            {
                glXSwapBuffers(m_display, m_pbuffer);
            }
        }

        void GlxContext::enableVsync(bool active)
        {
            ErrorHandler handler;

            if(isSupported(GlxSwapControlEXT))
            {
                ext::glXSwapInterval(m_display, glXGetCurrentDrawable(), active ? 1 : 0);
            }
            else if(isSupported(GlxSwapControlMESA))
            {
                mesa::glXSwapInterval(active ? 1 : 0);
            }
            else if(isSupported(GlxSwapControlSGI))
            {
                sgi::glXSwapInterval(active ? 1 : 0);
            }
            else
            {
                Log::get()->write("VSync is not available on your system", Log::Level::Notice);
            }
        }

        SurfaceHandler GlxContext::getSurfaceHandler() const
        {
            return m_display.getDefaultScreen();
        }

        bool GlxContext::makeCurrent()
        {
            ErrorHandler handler;
            bool success = false;

            if(m_render)
            {
                if(m_window)
                {
                    success = glXMakeCurrent(m_display, m_window, m_render) == True;
                }
                else if(m_pbuffer)
                {
                    success = glXMakeContextCurrent(m_display, m_pbuffer, m_pbuffer, m_render) == True;
                }
            }

            return success;
        }

        void GlxContext::createSurface(WindowHandler handler, unsigned int bitsPerPixel)
        {
            m_window = handler;
        }

        void GlxContext::createSurface(const std::shared_ptr<GlxContext>& shared, unsigned int width, unsigned int height, unsigned int bitsPerPixel)
        {
            ErrorHandler handler;

            if(isSupported(GlxPbuffer) && shared)
            {
                int fbCounts         = 0;
                GLXFBConfig* configs = glXChooseFBConfig(m_display, m_display.getDefaultScreen(), nullptr, &fbCounts);

                if(fbCounts && configs)
                {
                    int attributes[] =
                    {
                        GLX_PBUFFER_WIDTH,  static_cast<int>(width),
                        GLX_PBUFFER_HEIGHT, static_cast<int>(height),
                        0
                    };

                    m_config = configs[0];

                    m_pbuffer = glXCreatePbuffer(m_display, m_config, attributes);

                    XFree(configs);
                }
            }

            if(!m_pbuffer)
            {
                XVisualInfo*         vi;
                ErrorHandler         handler;
                XSetWindowAttributes attributes;

                vi = glXGetVisualFromFBConfig(m_display, m_config);

                m_colormap = XCreateColormap(m_display, m_display.getRootWindow(vi->screen), vi->visual, AllocNone);

                attributes.background_pixmap = XNone;
                attributes.colormap          = m_colormap;
                attributes.border_pixel      = 0;
                attributes.event_mask        = StructureNotifyMask;

                m_window = XCreateWindow(m_display,
                                         m_display.getRootWindow(vi->screen),
                                         0, 0,
                                         width, height,
                                         0,
                                         vi->depth,
                                         InputOutput,
                                         vi->visual,
                                         CWColormap | CWEventMask | CWBorderPixel,
                                         &attributes);

                m_ownWindow = true;

                XFree(vi);
            }
        }

        void GlxContext::createContext(const std::shared_ptr<GlxContext>& shared)
        {
            ErrorHandler handler;
            int glxMajor, glxMinor;
            GLXContext sharedHandler = shared.get() != nullptr ? shared->m_render : 0;

            glXQueryVersion(m_display, &glxMajor, &glxMinor);

            if(isSupported(GlxCreateContextARB) && (glxMajor > 1 || glxMinor >= 3))
            {
                do
                {
                    std::vector<int> attribs;

                    attribs.push_back(GLX_CONTEXT_MAJOR_VERSION_ARB);
                    attribs.push_back(m_settings.major);
                    attribs.push_back(GLX_CONTEXT_MINOR_VERSION_ARB);
                    attribs.push_back(m_settings.minor);

                    if(isSupported("GLX_ARB_create_context_profile"))
                    {
                        int flags   = 0;
                        int profile = (m_settings.flags & ContextSettings::Compatibility) ? GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB : GLX_CONTEXT_CORE_PROFILE_BIT_ARB;

                        if(m_settings.flags & ContextSettings::Debug)
                        {
                            flags |= GLX_CONTEXT_DEBUG_BIT_ARB;
                        }

                        if(m_settings.flags & ContextSettings::ForwardCompatible)
                        {
                            flags |= GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
                        }

                        attribs.push_back(GLX_CONTEXT_PROFILE_MASK_ARB);
                        attribs.push_back(profile);
                        attribs.push_back(GLX_CONTEXT_FLAGS_ARB);
                        attribs.push_back(flags);
                    }
                    else
                    {
                        m_settings.flags = ContextSettings::Default;
                    }

                    attribs.push_back(0);

                    m_render = glXCreateContextAttribs(m_display, m_config, sharedHandler, True, &attribs[0]);

                    if(!m_render)
                    {
                        Log::get()->write("Failed to create GlxContext with version " + String::number(m_settings.major) + "." + String::number(m_settings.minor), Log::Level::Warning);

                        if(m_settings.minor == 0)
                        {
                            m_settings.major -= 1;
                            m_settings.minor  = 9;
                        }
                        else
                        {
                            m_settings.minor -= 1;
                        }
                    }
                }while(!m_render && m_settings.major >= 1);
            }

            if(!m_render)
            {
                m_render = glXCreateNewContext(m_display, m_config, GLX_RGBA_TYPE, sharedHandler, True);
            }

            m_isDirect = glXIsDirect(m_display, m_render) == True;

            updateSettings();
        }

        void GlxContext::updateSettings()
        {
            int depths, stencil;
            int sampleBuffers, samples;

            glXGetFBConfigAttrib(m_display, m_config, GLX_SAMPLE_BUFFERS, &sampleBuffers);
            glXGetFBConfigAttrib(m_display, m_config, GLX_SAMPLES,        &samples);

            glXGetFBConfigAttrib(m_display, m_config, GLX_DEPTH_SIZE,   &depths);
            glXGetFBConfigAttrib(m_display, m_config, GLX_STENCIL_SIZE, &stencil);

            m_settings.depths       = static_cast<Uint8>(depths);
            m_settings.stencil      = static_cast<Uint8>(stencil);
            m_settings.antialiasing = static_cast<Uint8>(sampleBuffers > 0 ? samples : 0);
        }
    }
}
