#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Wgl/WglContext.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         *
         */
        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, WindowHandler window, unsigned int bitsPerPixel) :
            m_window(window),
            m_device(0),
            m_render(0),
            m_ownWindow(false)
        {
            createSurface();

            setPixelFormat(bitsPerPixel);

            createContext(shared);
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

        void WglContext::createSurface()
        {
            if(m_window == 0)
            {
                createInternalWindow(1, 1);
            }

            m_device = GetDC(m_window);

            if(m_device == 0)
            {
                ThrowException(FailToGetDeviceContext);
            }
        }

        void WglContext::createInternalWindow(unsigned int width, unsigned int height)
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
        }

        void WglContext::setPixelFormat(unsigned int bitsPerPixel)
        {
            PIXELFORMATDESCRIPTOR pfd =
            {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
                PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
                bitsPerPixel,                        //Colordepth of the framebuffer.
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                24,                        //Number of bits for the depthbuffer
                8,                        //Number of bits for the stencilbuffer
                0,                        //Number of Aux buffers in the framebuffer.
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
