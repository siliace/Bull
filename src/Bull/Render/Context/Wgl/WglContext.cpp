#include <iostream>

#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Wgl/WglContext.hpp>

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
            m_render(0)
        {
            createSurface(1, 1);

            if(m_device)
            {
                setPixelFormat(bitsPerPixel, m_settings);

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
            m_render(0)
        {
            createSurface(window);

            if(m_device)
            {
                setPixelFormat(bitsPerPixel, m_settings);

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

            m_ownWindow = false;
        }

        void WglContext::createSurface(unsigned int width, unsigned int height)
        {
            m_window = CreateWindow("STATIC", nullptr,
                                     WS_DISABLED | WS_POPUP,
                                     0, 0,
                                     width, height,
                                     0,
                                     0,
                                     GetModuleHandle(nullptr),
                                     nullptr);

            if(m_window == INVALID_HANDLE_VALUE)
            {
                ThrowException(FailToCreateSurface);
            }

            m_device = GetDC(m_window);

            m_ownWindow = true;
        }

        void WglContext::setPixelFormat(unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            PIXELFORMATDESCRIPTOR pfd =
            {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                bitsPerPixel,
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                settings.depths,
                settings.stencil,
                0,
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };

            if(!SetPixelFormat(m_device, ChoosePixelFormat(m_device, &pfd), &pfd))
            {
                ThrowException(FailToSetPixelFormat);
            }
        }

        void WglContext::createContext(const std::shared_ptr<WglContext>& shared)
        {
            /// TODO: check if createcontextarb is supported
            if(false)
            {

            }
            else
            {
                m_render = wglCreateContext(m_device);

                if(m_render && shared)
                {
                    static Mutex mutex;
                    Lock lock(mutex);

                    if(!wglShareLists(shared->m_render, m_render))
                    {
                        ThrowException(FailToShareContext);
                    }
                }
            }

            if(m_render == 0)
            {
                ThrowException(FailToCreateRenderContext);
            }
        }
    }
}
