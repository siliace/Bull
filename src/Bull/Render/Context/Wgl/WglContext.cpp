#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Wgl/WglContext.hpp>
#include <Bull/Render/Context/Wgl/WglCreateContextARB.hpp>

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
        void* WglContext::getFunction(const String& function)
        {
            void* functionProc = reinterpret_cast<void*>(wglGetProcAddress(function));

            if(functionProc)
            {
                return functionProc;
            }

            static HMODULE module = LoadLibrary("opengl32.dll");

            if(!module)
            {
                return nullptr;
            }

            return reinterpret_cast<void*>(GetProcAddress(module, function));
        }

        /*! \brief Set the list of extensions to load
         *
         * \param loader The instance of the extension loader to use
         *
         */
        void WglContext::requireExtensions(const ExtensionsLoader::Instance& loader)
        {
            loader->require(WglCreateContextARB);
        }

        /*! \brief Get the best pixel format for a device handler
         *
         * \param device       The device handler
         * \param bitsPerPixel The number of bits per pixel to use to create colors
         * \param settings     Settings to use to create the OpenGL context
         *
         * \return Return the pixel format
         *
         */
        int WglContext::getBestPixelFormat(HDC device, unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            PIXELFORMATDESCRIPTOR descriptor;
            ZeroMemory(&descriptor, sizeof(descriptor));
            descriptor.nSize        = sizeof(descriptor);
            descriptor.nVersion     = 1;
            descriptor.iLayerType   = PFD_MAIN_PLANE;
            descriptor.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            descriptor.iPixelType   = PFD_TYPE_RGBA;
            descriptor.cColorBits   = static_cast<BYTE>(bitsPerPixel);
            descriptor.cDepthBits   = static_cast<BYTE>(settings.depths);
            descriptor.cStencilBits = static_cast<BYTE>(settings.stencil);
            descriptor.cAlphaBits   = bitsPerPixel == 32 ? 8 : 0;

            return ChoosePixelFormat(device, &descriptor);
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         *
         */
        WglContext::WglContext(const std::shared_ptr<WglContext>& shared) :
            WglContext(shared, VideoMode::getCurrent().bitsPerPixel, ContextSettings())
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
        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, unsigned int bitsPerPixel, const ContextSettings& settings) :
            GlContext(settings),
            m_device(0),
            m_render(0),
            m_ownWindow(false)
        {
            createSurface(1, 1, bitsPerPixel);

            if(m_device)
            {
                setPixelFormat(bitsPerPixel);

                createContext(shared);
            }
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         * \param settings Settings to use to create the OpenGL context
         *
         */
        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings) :
            m_device(0),
            m_render(0),
            m_ownWindow(false)
        {
            createSurface(window);

            if(m_device)
            {
                setPixelFormat(bitsPerPixel);

                createContext(shared);
            }
        }

        /*! \brief Destructor
         *
         */
        WglContext::~WglContext()
        {
            if(m_render)
            {
                if(wglGetCurrentContext() == m_render)
                {
                    wglMakeCurrent(0, 0);
                }

                wglDeleteContext(m_render);
            }

            if(m_device)
            {
                ReleaseDC(m_window, m_device);
            }

            if(m_window && m_ownWindow)
            {
                DestroyWindow(m_window);
            }
        }

        SurfaceHandler WglContext::getSurfaceHandler() const
        {
            return m_device;
        }

        /*! \brief Display what has been rendered so far
         *
         */
        void WglContext::display()
        {
            if(m_device && m_render)
            {
                SwapBuffers(m_device);
            }
        }

        /*! \brief Make the context current
         *
         * \return Return true if the context is now active, false otherwise
         *
         */
        bool WglContext::makeCurrent()
        {
            return wglMakeCurrent(m_device, m_render);
        }

        void WglContext::createSurface(WindowHandler window)
        {
            m_window = window;

            m_device = GetDC(m_window);
        }

        void WglContext::createSurface(unsigned int width, unsigned int height, unsigned int bitsPerPixel)
        {
            m_window = CreateWindow("STATIC", nullptr,
                                     WS_DISABLED | WS_POPUP,
                                     0, 0,
                                     width, height,
                                     0,
                                     0,
                                     GetModuleHandle(nullptr),
                                     nullptr);

            m_device = GetDC(m_window);

            m_ownWindow = true;
        }

        void WglContext::setPixelFormat(unsigned int bitsPerPixel)
        {
            PIXELFORMATDESCRIPTOR descriptor;
            int bestFormat = getBestPixelFormat(m_device, bitsPerPixel, m_settings);

            descriptor.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
            descriptor.nVersion = 1;
            DescribePixelFormat(m_device, bestFormat, sizeof(PIXELFORMATDESCRIPTOR), &descriptor);

            SetPixelFormat(m_device, bestFormat, &descriptor);
        }

        void WglContext::createContext(const std::shared_ptr<WglContext>& shared)
        {
            HGLRC sharedHandler = shared ? shared->m_render : 0;

            if(ExtensionsLoader::get()->isLoaded(WglCreateContextARB))
            {
                static const int attribs[] =
                {
                    WGL_CONTEXT_MAJOR_VERSION_ARB, m_settings.major,
                    WGL_CONTEXT_MINOR_VERSION_ARB, m_settings.minor,
                    WGL_CONTEXT_FLAGS_ARB,         0,
                    0
                };

                m_render = wglCreateContextAttribsARB(m_device, sharedHandler, attribs);
            }

            if(m_render == 0)
            {
                m_render = wglCreateContext(m_device);

                if(m_render && shared)
                {
                    static Mutex mutex;
                    Lock lock(mutex);

                    wglShareLists(sharedHandler, m_render);
                }
            }
        }
    }
}
