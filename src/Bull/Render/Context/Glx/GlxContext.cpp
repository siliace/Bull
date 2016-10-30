#include <Bull/Render/Context/Glx/GlxContext.hpp>
#include <Bull/Render/Context/Glx/GlxCreateContextARB.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlEXT.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlMESA.hpp>
#include <Bull/Render/Context/Glx/GlxSwapControlSGI.hpp>

#include <Bull/Window/VideoMode.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get an OpenGL function
         *
         * \param function The function name
         *
         * \param Return the function, nullptr if the function is not available
         *
         */
        void* GlxContext::getFunction(const String& function)
        {
            return reinterpret_cast<void*>(glXGetProcAddressARB(reinterpret_cast<const unsigned char*>(static_cast<const char*>(function))));
        }

        /*! \brief Set the list of extensions to load
         *
         * \param loader The instance of the extension loader to use
         *
         */
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
                Log::get()->notice("VSync is not available on your system");
            }
        }

        /*! \brief Determine the best XVisualInfo
         *
         * \param bitsPerPixel Number of bits per pixel
         * \param settings     Settings to use to create the OpenGL context
         *
         * \return The XVisualInfo
         *
         */
        XVisualInfo GlxContext::getBestVisual(unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            Display::Instance display = Display::get();

            int count;
            XVisualInfo best = XVisualInfo();
            XVisualInfo* visuals = XGetVisualInfo(display->getHandler(), 0, nullptr, &count);

            if(visuals)
            {
                for(int i = 0; i < count; i++)
                {
                    int doubleBuffer;
                    int red, green, blue, alpha;
                    int depth, stencil;

                    glXGetConfig(display->getHandler(), &visuals[i], GLX_DOUBLEBUFFER, &doubleBuffer);
                    if(!doubleBuffer)
                    {
                        continue;
                    }

                    glXGetConfig(display->getHandler(), &visuals[i], GLX_RED_SIZE,   &red);
                    glXGetConfig(display->getHandler(), &visuals[i], GLX_GREEN_SIZE, &green);
                    glXGetConfig(display->getHandler(), &visuals[i], GLX_BLUE_SIZE,  &blue);
                    glXGetConfig(display->getHandler(), &visuals[i], GLX_ALPHA_SIZE, &alpha);
                    if(red + green + blue + alpha != bitsPerPixel)
                    {
                        continue;
                    }

                    glXGetConfig(display->getHandler(), &visuals[i], GLX_DEPTH_SIZE, &depth);
                    if(depth != settings.depths)
                    {
                        continue;
                    }

                    glXGetConfig(display->getHandler(), &visuals[i], GLX_STENCIL_SIZE, &stencil);
                    if(stencil != settings.stencil)
                    {
                        continue;
                    }

                    best = visuals[i];
                }
            }

            XFree(visuals);

            return best;
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         *
         */
        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared) :
            GlxContext(shared, VideoMode::getCurrent().bitsPerPixel, ContextSettings())
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param bitsPerPixel The number of bits to use per pixel
         * \param settings Parameters to create the OpenGL context
         *
         */
        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, unsigned int bitsPerPixel, const ContextSettings& settings) :
            GlContext(settings),
            m_display(Display::get()),
            m_render(0),
            m_ownWindow(false)
        {
            createSurface(bitsPerPixel);

            if(m_window)
            {
                createContext(shared);
            }
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         * \param settings Parameters to create the OpenGL context
         *
         */
        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings) :
            GlContext(settings),
            m_display(Display::get()),
            m_render(0),
            m_ownWindow(false)
        {
            createSurface(window);

            if(m_window)
            {
                createContext(shared);
            }
        }

        /*! \brief Destructor
         *
         */
        GlxContext::~GlxContext()
        {
            if(m_render)
            {
                if(glXGetCurrentContext() == m_render)
                {
                    glXMakeCurrent(m_display->getHandler(), 0, 0);
                }

                glXDestroyContext(m_display->getHandler(), m_render);
            }

            if(m_window && m_ownWindow)
            {
                XDestroyWindow(m_display->getHandler(), m_window);
            }
        }

        /*! \brief Display what has been rendered so far
         *
         */
        void GlxContext::display()
        {
            if(m_render && m_window)
            {
                glXSwapBuffers(m_display->getHandler(), m_window);
            }
        }

        /*! \brief Get the render surface of the context
         *
         * \return Return the render context
         *
         */
        SurfaceHandler GlxContext::getSurfaceHandler() const
        {
            return Display::get()->getDefaultScreen();
        }

        /*! \brief Make the context current
         *
         * \return Return true if the context is now active, false otherwise
         *
         */
        bool GlxContext::makeCurrent()
        {
            return glXMakeCurrent(Display::get()->getHandler(), m_window, m_render);
        }

        /*! \brief Create the render surface
         *
         * \param handler The window to bind to this context
         *
         */
        void GlxContext::createSurface(WindowHandler handler)
        {
            m_window = handler;
        }

        /*! \brief Create the render surface
         *
         * \param bitsPerPixel The number of bits per pixel to use
         *
         */
        void GlxContext::createSurface(unsigned int bitsPerPixel)
        {
            XSetWindowAttributes attributes;
            XVisualInfo vi = getBestVisual(bitsPerPixel, m_settings);

            attributes.colormap = XCreateColormap(m_display->getHandler(),
                                                  m_display->getRootWindow(),
                                                  vi.visual,
                                                  AllocNone);

            m_window = XCreateWindow(m_display->getHandler(),
                                     m_display->getRootWindow(),
                                     0, 0,
                                     1, 1,
                                     0,
                                     m_display->getDefaultDepth(),
                                     InputOutput,
                                     vi.visual,
                                     CWColormap,
                                     &attributes);

            m_ownWindow = true;
        }

        /*! \brief Create the render context
         *
         * \param shared The shared context
         *
         */
        void GlxContext::createContext(const std::shared_ptr<GlxContext>& shared)
        {
            int count = 0;
            XVisualInfo* visual;
            XVisualInfo  tpl;
            XWindowAttributes attribs;
            GLXContext sharedHandler = (shared.get() != nullptr) ? shared.get()->m_render : 0;

            if(isLoaded(GlxCreateContextARB))
            {
                int countConfigs;
                GLXFBConfig* config = nullptr;
                GLXFBConfig* configs = nullptr;
                configs = glXChooseFBConfig(m_display->getHandler(), m_display->getDefaultScreen(), nullptr, &countConfigs);

                for(int i = 0; i < countConfigs; i++)
                {
                    XVisualInfo* visualInfo = glXGetVisualFromFBConfig(m_display->getHandler(), configs[i]);

                    if(visualInfo && visualInfo->visualid == visual->visualid)
                    {
                        config = &configs[i];
                        XFree(visualInfo);
                        break;
                    }
                    else if(visualInfo)
                    {
                        XFree(visualInfo);
                    }
                }

                ErrorHandler::Instance handler = ErrorHandler::get();

                if(config)
                {
                    do
                    {
                        int attribs[] =
                        {
                            GLX_CONTEXT_MAJOR_VERSION_ARB, m_settings.major,
                            GLX_CONTEXT_MINOR_VERSION_ARB, m_settings.minor,
                            0
                        };

                        m_render = glXCreateContextAttribs(m_display->getHandler(), *config, sharedHandler, True, attribs);

                        if(m_render == 0)
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
                    }while(m_render == 0 && m_settings.major >= 1);
                }

                if(configs)
                {
                    XFree(configs);
                }
            }

            if(m_render == 0)
            {
                XGetWindowAttributes(m_display->getHandler(), m_window, &attribs);

                tpl.screen   = m_display->getDefaultScreen();
                tpl.visualid = XVisualIDFromVisual(attribs.visual);

                visual = XGetVisualInfo(m_display->getHandler(), VisualIDMask | VisualScreenMask, &tpl, &count);

                m_render = glXCreateContext(m_display->getHandler(), visual, sharedHandler, True);

                XFree(visual);
            }
        }
    }
}
