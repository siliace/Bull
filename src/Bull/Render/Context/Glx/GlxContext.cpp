#include <limits>

#include <Bull/Core/Log.hpp>

#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Context/Glx/GlxCreateContextARB.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlEXT.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlMESA.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlSGI.hpp>

#include <Bull/Utility/Window/X11/ErrorHandler.hpp>

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
            else
            {
                Log::get()->write("VSync is not available on your system", Log::Level::Notice);
            }
        }

        GLXFBConfig GlxContext::chooseBestConfig(Display::Instance display, const ContextSettings& settings, unsigned int bitsPerPixel)
        {
            int attributes[] =
            {
                GLX_X_RENDERABLE  , True,
                GLX_DRAWABLE_TYPE , GLX_WINDOW_BIT,
                GLX_RENDER_TYPE   , GLX_RGBA_BIT,
                GLX_X_VISUAL_TYPE , GLX_TRUE_COLOR,
                GLX_RED_SIZE      , static_cast<int>(bitsPerPixel) / 4,
                GLX_GREEN_SIZE    , static_cast<int>(bitsPerPixel) / 4,
                GLX_BLUE_SIZE     , static_cast<int>(bitsPerPixel) / 4,
                GLX_ALPHA_SIZE    , static_cast<int>(bitsPerPixel) / 4,
                GLX_DEPTH_SIZE    , settings.depths,
                GLX_STENCIL_SIZE  , settings.stencil,
                GLX_DOUBLEBUFFER  , True,
                GLX_SAMPLE_BUFFERS, settings.antialiasing == 0 ? 0 : 1,
                GLX_SAMPLES       , settings.antialiasing,
                0
            };

            int fbCounts = 0;
            int bestConfig = 0, bestScore = std::numeric_limits<int>::max();
            GLXFBConfig config;
            GLXFBConfig* configs = glXChooseFBConfig(display->getHandler(), display->getDefaultScreen(), attributes, &fbCounts);

            for(int i = 0; i < fbCounts; i++)
            {
                XVisualInfo* visual = glXGetVisualFromFBConfig(display->getHandler(), configs[i]);

                if(visual)
                {
                    int red, green, blue, alpha;
                    int sampleBuffers, samples;
                    int depths, stencil;

                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_RED_SIZE,   &red);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_GREEN_SIZE, &green);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_BLUE_SIZE,  &blue);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_ALPHA_SIZE, &alpha);

                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_SAMPLE_BUFFERS, &sampleBuffers);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_SAMPLES, &samples);

                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_DEPTH_SIZE,   &depths);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_STENCIL_SIZE, &stencil);

                    int currentBitsPerPixel = red + green + blue + alpha;
                    int score = evaluatePixelFormat(currentBitsPerPixel, depths, stencil, sampleBuffers ? samples : 0, bitsPerPixel, settings);

                    if(score < bestScore)
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
            m_display(Display::get()),
            m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, mode.bitsPerPixel);

            createSurface(mode.width, mode.height, mode.bitsPerPixel);

            if(m_window)
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
            m_display(Display::get()),
            m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, bitsPerPixel);

            createSurface(window);

            if(window)
            {
                createContext(shared);
            }
        }

        GlxContext::~GlxContext()
        {
            if(m_ownWindow)
            {
                XDestroyWindow(m_display->getHandler(), m_window);
            }

            if(m_render)
            {
                if(glXGetCurrentContext() == m_render)
                {
                    glXMakeCurrent(m_display->getHandler(), 0, 0);
                }

                glXDestroyContext(m_display->getHandler(), m_render);
            }
        }

        void GlxContext::display()
        {
            if(m_window && m_render)
            {
                glXSwapBuffers(m_display->getHandler(), m_window);
            }
        }

        void GlxContext::enableVsync(bool active)
        {

        }

        SurfaceHandler GlxContext::getSurfaceHandler() const
        {
            return m_display->getDefaultScreen();
        }

        bool GlxContext::makeCurrent()
        {
            if(m_window && m_render)
            {
                ErrorHandler handler;
                return glXMakeCurrent(m_display->getHandler(), m_window, m_render) == True;
            }

            return false;
        }

        void GlxContext::createSurface(WindowHandler handler)
        {
            m_window = handler;
        }

        void GlxContext::createSurface(unsigned int width, unsigned int height, unsigned int bitsPerPixel)
        {
            XVisualInfo*         vi;
            GLXFBConfig          config;
            ErrorHandler         handler;
            XSetWindowAttributes attributes;

            config = GlxContext::chooseBestConfig(m_display, m_settings, bitsPerPixel);

            vi = glXGetVisualFromFBConfig(m_display->getHandler(), config);

            attributes.background_pixel = 0;
            attributes.border_pixel     = 0;
            attributes.colormap         = XCreateColormap(m_display->getHandler(), m_display->getRootWindow(vi->screen), vi->visual, AllocNone);

            m_window = XCreateWindow(m_display->getHandler(),
                                     m_display->getRootWindow(),
                                     0, 0,
                                     width, height,
                                     0,
                                     vi->depth,
                                     InputOnly,
                                     vi->visual,
                                     CWBackPixel | CWBorderPixel | CWColormap,
                                     &attributes);
        }

        void GlxContext::createContext(const std::shared_ptr<GlxContext>& shared)
        {
            GLXContext sharedHandler = shared.get() != nullptr ? shared->m_render : 0;

            int glxMajor, glxMinor;

            glXQueryVersion(m_display->getHandler(), &glxMajor, &glxMinor);

            if(isSupported(GlxCreateContextARB) && (glxMajor > 1 || glxMinor >= 3))
            {
                do
                {
                    ErrorHandler handler;
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

                    attribs.push_back(0);

                    m_render = glXCreateContextAttribs(m_display->getHandler(), m_config, sharedHandler, True, &attribs[0]);

                    if(!m_render)
                    {
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
                ErrorHandler handler;
                m_render = glXCreateNewContext(m_display->getHandler(), m_config, GLX_RGBA_TYPE, sharedHandler, True);
            }

            m_isDirect = glXIsDirect(m_display->getHandler(), m_render);
        }
    }
}
