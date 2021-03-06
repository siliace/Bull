#include <limits>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Support/Xlib/ErrorHandler.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Context/Glx/GlxCreateContextARB.hpp>
#include <Bull/Render/Context/Glx/GlxPBufferSGIX.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlEXT.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlMESA.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlSGI.hpp>

namespace Bull
{
    namespace prv
    {
        void* GlxContext::getFunction(const std::string& function)
        {
            return reinterpret_cast<void*>(
                    glXGetProcAddressARB(
                            reinterpret_cast<const unsigned char*>(function.getBuffer())
                    )
            );
        }

        void GlxContext::requireExtensions(ExtensionsLoader& loader)
        {
            loader.require(glxCreateContextARB);
            loader.require(glxPbuffer);
            loader.require(glxSwapControlEXT);
            loader.require(glxSwapControlMESA);
            loader.require(glxSwapControlSGI);
        }

        GLXFBConfig GlxContext::chooseBestConfig(Display& display, const ContextSettings& settings, Uint8 bitsPerPixel)
        {
            int fbCounts = 0;
            GLXFBConfig config;
            ErrorHandler handler;
            GLXFBConfig* configs = nullptr;
            unsigned int antialiasing = settings.antialiasing;
            int bestConfig = -1, bestScore = std::numeric_limits<int>::max();

            do
            {
                int attributes[] = {
                        GLX_X_RENDERABLE, True,
                        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                        GLX_RENDER_TYPE, GLX_RGBA_BIT,
                        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
                        GLX_BUFFER_SIZE, static_cast<int>(bitsPerPixel),
                        GLX_ALPHA_SIZE, bitsPerPixel == 32 ? 8 : 0,
                        GLX_DEPTH_SIZE, settings.depths,
                        GLX_STENCIL_SIZE, settings.stencil,
                        GLX_DOUBLEBUFFER, True,
                        GLX_SAMPLE_BUFFERS, antialiasing > 0 ? True : False,
                        GLX_SAMPLES, static_cast<int>(antialiasing),
                        0
                };

                configs = glXChooseFBConfig(display.getHandler(), display.getDefaultScreen(), attributes, &fbCounts);

                if(fbCounts == 0)
                {
                    antialiasing /= 2;
                }
            }while(fbCounts == 0);

            for(int i = 0; i < fbCounts; i++)
            {
                XVisualInfo* vi = glXGetVisualFromFBConfig(display.getHandler(), configs[i]);

                if(vi)
                {
                    int depths, stencil;
                    int sampleBuffers, samples;
                    int red, green, blue, alpha;

                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_RED_SIZE, &red);
                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_GREEN_SIZE, &green);
                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_BLUE_SIZE, &blue);
                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_ALPHA_SIZE, &alpha);

                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_SAMPLE_BUFFERS, &sampleBuffers);
                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_SAMPLES, &samples);

                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_DEPTH_SIZE, &depths);
                    glXGetFBConfigAttrib(display.getHandler(), configs[i], GLX_STENCIL_SIZE, &stencil);

                    int currentBitsPerPixel = red + green + blue + alpha;
                    int score = evaluatePixelFormat(currentBitsPerPixel, depths, stencil, sampleBuffers ? samples : 0, bitsPerPixel, settings);

                    if(bestScore > score)
                    {
                        bestScore = score;
                        bestConfig = i;
                    }
                }

                XFree(vi);
            }

            Expect(bestConfig != -1, Throw(InternalError, "Failed to get best framebuffer configuration"))

            config = configs[bestConfig];

            XFree(configs);

            return config;
        }

        GlxContext::GlxContext(const GlxContext* shared) :
                GlxContext(shared, VideoMode(Size<unsigned int>(1, 1)), ContextSettings::Worst)
        {
            /// Nothing
        }

        GlxContext::GlxContext(const GlxContext* shared, const VideoMode& mode, const ContextSettings& settings) :
                GlContext(settings),
                m_log(Log::getInstance()),
                m_window(0),
                m_render(nullptr),
                m_config(nullptr),
                m_pbuffer(0),
                m_display(Display::getInstance()),
                m_colormap(0),
                m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, mode.bitsPerPixel);

            createSurface(shared, mode.size);

            if(m_window || m_pbuffer)
            {
                createContext(shared);
            }
        }

        GlxContext::GlxContext(const GlxContext* shared, Uint8 bitsPerPixel, const ContextSettings& settings) :
                GlxContext(shared, VideoMode(Size<unsigned int>(1, 1), bitsPerPixel), settings)
        {
            /// Nothing
        }

        GlxContext::GlxContext(const GlxContext* shared, const WindowImpl& window, Uint8 bitsPerPixel, const ContextSettings& settings) :
                GlContext(settings),
                m_log(Log::getInstance()),
                m_window(0),
                m_render(nullptr),
                m_config(nullptr),
                m_pbuffer(0),
                m_display(Display::getInstance()),
                m_colormap(0),
                m_ownWindow(false)
        {
            m_config = chooseBestConfig(m_display, m_settings, bitsPerPixel);

            createSurface(window);

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
                    Expect(glXMakeCurrent(m_display.getHandler(), XNone, nullptr), Throw(InternalError, "Failed to disable current context"));
                }

                glXDestroyContext(m_display.getHandler(), m_render);
            }

            if(m_pbuffer)
            {
                glXDestroyPbuffer(m_display.getHandler(), m_pbuffer);
            }

            if(m_ownWindow)
            {
                XDestroyWindow(m_display.getHandler(), m_window);
                XFreeColormap(m_display.getHandler(), m_colormap);

                m_display.flush();
            }
        }

        void GlxContext::display()
        {
            ErrorHandler handler;

            if(m_window)
            {
                glXSwapBuffers(m_display.getHandler(), m_window);
            }
            else if(m_pbuffer)
            {
                glXSwapBuffers(m_display.getHandler(), m_pbuffer);
            }
        }

        void GlxContext::enableVsync(bool active)
        {
            ErrorHandler handler;

            if(glxSwapControlEXT.isLoaded())
            {
                ext::glXSwapInterval(m_display.getHandler(), glXGetCurrentDrawable(), active ? 1 : 0);
            }
            else if(glxSwapControlMESA.isLoaded())
            {
                mesa::glXSwapInterval(active ? 1 : 0);
            }
            else if(glxSwapControlSGI.isLoaded())
            {
                sgi::glXSwapInterval(active ? 1 : 0);
            }
            else
            {
                m_log.warning("VSync is not available on your system");
            }
        }

        SurfaceHandler GlxContext::getSurfaceHandler() const
        {
            return m_display.getDefaultScreen();
        }

        void GlxContext::makeCurrent()
        {
            ErrorHandler handler;

            if(m_window)
            {
                Expect(glXMakeCurrent(m_display.getHandler(), m_window, m_render), Throw(InternalError, "Failed to make context current"));
            }
            else if(m_pbuffer)
            {
                Expect(glXMakeContextCurrent(m_display.getHandler(), m_pbuffer, m_pbuffer, m_render), Throw(InternalError, "Failed to make context current"));
            }
        }

        void GlxContext::createSurface(const WindowImpl& window)
        {
            m_window = window.getSystemHandler();
        }

        void GlxContext::createSurface(const GlxContext* shared, const Size<unsigned int>& size)
        {
            ErrorHandler handler;

            if(glxPbuffer.isLoaded() && shared)
            {
                int fbCounts = 0;
                GLXFBConfig* configs = glXChooseFBConfig(m_display.getHandler(), m_display.getDefaultScreen(), nullptr, &fbCounts);

                if(fbCounts && configs)
                {
                    int attributes[] = {
                            GLX_PBUFFER_WIDTH, static_cast<int>(size.width),
                            GLX_PBUFFER_HEIGHT, static_cast<int>(size.height),
                            0
                    };

                    m_config = configs[0];

                    m_pbuffer = glXCreatePbuffer(m_display.getHandler(), m_config, attributes);

                    XFree(configs);
                }
            }

            if(!m_pbuffer)
            {
                XVisualInfo* vi;
                XSetWindowAttributes attributes;

                vi = glXGetVisualFromFBConfig(m_display.getHandler(), m_config);

                m_colormap = XCreateColormap(m_display.getHandler(), m_display.getRootWindow(vi->screen), vi->visual, AllocNone);

                attributes.border_pixel = 0;
                attributes.background_pixmap = XNone;
                attributes.colormap = m_colormap;
                attributes.event_mask = StructureNotifyMask;

                m_window = XCreateWindow(m_display.getHandler(),
                                         m_display.getRootWindow(vi->screen),
                                         0, 0,
                                         size.width, size.height,
                                         0,
                                         vi->depth,
                                         InputOutput,
                                         vi->visual,
                                         CWColormap | CWEventMask | CWBorderPixel,
                                         &attributes);

                m_ownWindow = true;

                XFree(vi);
            }

            Expect(m_ownWindow && m_window || m_pbuffer, Throw(InternalError, "Failed to create rendering surface"));
        }

        void GlxContext::createContext(const GlxContext* shared)
        {
            ErrorHandler handler;
            int glxMajor, glxMinor;
            GLXContext sharedHandler = shared ? shared->m_render : nullptr;

            glXQueryVersion(m_display.getHandler(), &glxMajor, &glxMinor);

            if(glxCreateContextARB.isLoaded() && (glxMajor > 1 || glxMinor >= 3))
            {
                do
                {
                    std::vector<int> attribs;

                    attribs.emplace_back(GLX_CONTEXT_MAJOR_VERSION_ARB);
                    attribs.emplace_back(m_settings.major);
                    attribs.emplace_back(GLX_CONTEXT_MINOR_VERSION_ARB);
                    attribs.emplace_back(m_settings.minor);

                    if(isSupported("GLX_ARB_create_context_profile"))
                    {
                        int flags = 0;
                        int profile = (m_settings.profile & ContextSettingsProfile_Compatibility) ? GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB : GLX_CONTEXT_CORE_PROFILE_BIT_ARB;

                        if(m_settings.type & ContextSettingsType_Debug)
                        {
                            flags |= GLX_CONTEXT_DEBUG_BIT_ARB;
                        }

                        if(m_settings.type & ContextSettingsType_ForwardCompatible)
                        {
                            flags |= GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
                        }

                        attribs.emplace_back(GLX_CONTEXT_PROFILE_MASK_ARB);
                        attribs.emplace_back(profile);
                        attribs.emplace_back(GLX_CONTEXT_FLAGS_ARB);
                        attribs.emplace_back(flags);
                    }
                    else
                    {
                        m_settings.type = ContextSettingsType_Default;
                    }

                    attribs.emplace_back(0);

                    m_render = glXCreateContextAttribs(m_display.getHandler(), m_config, sharedHandler, True, &attribs[0]);

                    if(!m_render)
                    {
                        m_log.warning("Failed to create GlxContext with version " + std::to_string(m_settings.major) + "." + std::to_string(m_settings.minor));

                        if(m_settings.minor == 0)
                        {
                            m_settings.major -= 1;
                            m_settings.minor = 9;
                        }
                        else
                        {
                            m_settings.minor -= 1;
                        }
                    }
                    else
                    {
                        m_log.info("Create GlxContext with version " + std::to_string(m_settings.major) + "." + std::to_string(m_settings.minor));
                    }
                }while(!m_render && m_settings.major >= 1);
            }

            if(!m_render)
            {
                m_render = glXCreateNewContext(m_display.getHandler(), m_config, GLX_RGBA_TYPE, sharedHandler, True);

                Expect(m_render, Throw(InternalError, "Failed to create legacy/shared GlxContext"));

                if(shared)
                {
                    m_log.info("Create shared GlxContext");
                }
                else
                {
                    m_log.info("Create legacy GlxContext");
                }
            }

            updateSettings();
        }

        void GlxContext::updateSettings()
        {
            int depths, stencil;
            int sampleBuffers, samples;

            glXGetFBConfigAttrib(m_display.getHandler(), m_config, GLX_SAMPLE_BUFFERS, &sampleBuffers);
            glXGetFBConfigAttrib(m_display.getHandler(), m_config, GLX_SAMPLES, &samples);

            glXGetFBConfigAttrib(m_display.getHandler(), m_config, GLX_DEPTH_SIZE, &depths);
            glXGetFBConfigAttrib(m_display.getHandler(), m_config, GLX_STENCIL_SIZE, &stencil);

            m_settings.depths = static_cast<Uint8>(depths);
            m_settings.stencil = static_cast<Uint8>(stencil);
            m_settings.antialiasing = static_cast<Uint8>(sampleBuffers > 0 ? samples : 0);
        }
    }
}
