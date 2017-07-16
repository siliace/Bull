#include <limits>

#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Context/Wgl/WglContext.hpp>
#include <Bull/Render/Context/Wgl/WglCreateContextARB.hpp>
#include <Bull/Render/Context/Wgl/WglMultisampleARB.hpp>
#include <Bull/Render/Context/Wgl/WglPbufferARB.hpp>
#include <Bull/Render/Context/Wgl/WglPixelFormatARB.hpp>
#include <Bull/Render/Context/Wgl/WglSwapControlEXT.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    namespace prv
    {
        void* WglContext::getFunction(const String& function)
        {
            void* functionProc = reinterpret_cast<void*>(wglGetProcAddress(function.getBuffer()));

            if(functionProc)
            {
                return functionProc;
            }

            static HMODULE module = LoadLibrary("opengl32.dll");

            if(!module)
            {
                return nullptr;
            }

            return reinterpret_cast<void*>(GetProcAddress(module, function.getBuffer()));
        }

        void WglContext::requireExtensions(const ExtensionsLoader::Instance& loader)
        {
            loader->require(WglCreateContext);
            loader->require(WglPixelFormat);
            loader->require(WglSwapControl);
            loader->require(WglPbuffer);
        }

        int WglContext::getBestPixelFormat(HDC device, Uint8 bitsPerPixel, const ContextSettings& settings, bool usePbuffer)
        {
            int bestPixelFormat = 0;

            if(isLoaded(WglPixelFormat))
            {
                static const int attribs[] =
                {
                    WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
                    WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
                    WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
                    WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
                    0
                };

                int formats[512];
                UINT count = 0;
                bool isValid = wglChoosePixelFormat(device, attribs, nullptr, 512, formats, &count) != 0;

                if(isValid && count > 0)
                {
                    int bestScore = std::numeric_limits<int>::max();

                    for(UINT i = 0; i < count; i++)
                    {
                        int format[7]  = {0};
                        int sample[2]  = {0};
                        static const int formatAttribs[] =
                        {
                            WGL_RED_BITS_ARB,
                            WGL_GREEN_BITS_ARB,
                            WGL_BLUE_BITS_ARB,
                            WGL_ALPHA_BITS_ARB,
                            WGL_DEPTH_BITS_ARB,
                            WGL_STENCIL_BITS_ARB,
                            WGL_ACCELERATION_ARB
                        };

                        if(!wglGetPixelFormatAttribiv(device, formats[i], PFD_MAIN_PLANE, 7, formatAttribs, format))
                        {
                            break;
                        }

                        if(isSupported(WglMultisample))
                        {
                            static const int sampleAttribs[] =
                            {
                                WGL_SAMPLE_BUFFERS_ARB,
                                WGL_SAMPLES_ARB
                            };

                            if(!wglGetPixelFormatAttribiv(device, formats[i], PFD_MAIN_PLANE, 2, sampleAttribs, sample))
                            {
                                break;
                            }
                        }

                        if(usePbuffer)
                        {
                            int pbuffer;
                            static const int pbufferAttribs[] =
                            {
                                WGL_DRAW_TO_PBUFFER_ARB
                            };

                            if(!wglGetPixelFormatAttribiv(device, formats[i], PFD_MAIN_PLANE, 1, pbufferAttribs, &pbuffer))
                            {
                                break;
                            }
                            else if(pbuffer != GL_TRUE)
                            {
                                continue;
                            }
                        }

                        /// We don't care about non hardware accelerated pixel format
                        if(format[6])
                        {
                            int colors = format[0] + format[1] + format[2] + format[3];
                            int score  = evaluatePixelFormat(colors, format[4], format[5], sample[0] ? sample[1] : 0, bitsPerPixel, settings);

                            if(bestScore > score)
                            {
                                bestScore       = score;
                                bestPixelFormat = formats[i];
                            }
                        }
                    }
                }
            }

            if(usePbuffer)
            {
                return bestPixelFormat;
            }

            if(!bestPixelFormat)
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

                bestPixelFormat = ChoosePixelFormat(device, &descriptor);
            }

            return bestPixelFormat;
        }

        WglContext::WglContext(const std::shared_ptr<WglContext>& shared) :
            WglContext(shared, VideoMode(1, 1), ContextSettings())
        {
            /// Nothing
        }

        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, const VideoMode& mode, const ContextSettings& settings) :
            GlContext(settings),
            m_device(0),
            m_render(0),
            m_pbuffer(0),
            m_ownWindow(false)
        {
            createSurface(shared, mode.width, mode.height, mode.bitsPerPixel);

            if(m_device)
            {
                setPixelFormat(mode.bitsPerPixel);

                createContext(shared);
            }
        }

        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, Uint8 bitsPerPixel, const ContextSettings& settings) :
            WglContext(shared, VideoMode(1, 1, bitsPerPixel), settings)
        {
            /// Nothing
        }

        WglContext::WglContext(const std::shared_ptr<WglContext>& shared, const std::unique_ptr<WindowImpl>& window, Uint8 bitsPerPixel, const ContextSettings& settings) :
            GlContext(settings),
            m_device(0),
            m_render(0),
            m_pbuffer(0),
            m_ownWindow(false)
        {
            createSurface(window);

            if(m_device)
            {
                setPixelFormat(bitsPerPixel);

                createContext(shared);
            }
        }

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
                if(m_pbuffer)
                {
                    wglReleasePbufferDC(m_pbuffer, m_device);
                    wglDestroyPbuffer(m_pbuffer);
                }
                else
                {
                    ReleaseDC(m_window, m_device);
                }
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

        void WglContext::display()
        {
            if(m_device && m_render)
            {
                SwapBuffers(m_device);
            }
        }

        void WglContext::enableVsync(bool active)
        {
            if(isLoaded(WglSwapControl))
            {
                wglSwapInterval(active ? 1 : 0);
            }
        }

        bool WglContext::makeCurrent()
        {
            return wglMakeCurrent(m_device, m_render) == TRUE;
        }

        void WglContext::createSurface(const std::unique_ptr<WindowImpl>& window)
        {
            m_window = window->getSystemHandler();

            m_device = GetDC(m_window);
        }

        void WglContext::createSurface(const std::shared_ptr<WglContext>& shared, unsigned int width, unsigned int height, Uint8 bitsPerPixel)
        {
            if(isLoaded(WglPbuffer) && shared)
            {
                int format = getBestPixelFormat(shared->m_device, bitsPerPixel, m_settings, true);

                if(format)
                {
                    m_pbuffer = wglCreatePbuffer(shared->m_device, format, width, height, nullptr);

                    if(m_pbuffer)
                    {
                        m_device = wglGetPbufferDC(m_pbuffer);

                        if(!m_device)
                        {
                            wglDestroyPbuffer(m_pbuffer);
                        }
                    }
                }
            }

            if(!m_device)
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
        }

        void WglContext::setPixelFormat(Uint8 bitsPerPixel)
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

            if(isLoaded(WglCreateContext))
            {
                do
                {
                    std::vector<int> attribs;

                    attribs.push_back(WGL_CONTEXT_MAJOR_VERSION_ARB);
                    attribs.push_back(m_settings.major);
                    attribs.push_back(WGL_CONTEXT_MINOR_VERSION_ARB);
                    attribs.push_back(m_settings.minor);

                    if(isSupported("WGL_ARB_create_context_profile"))
                    {
                        int flags   = 0;
                        int profile = (m_settings.flags & ContextSettings::Compatibility) ? WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB : WGL_CONTEXT_CORE_PROFILE_BIT_ARB;

                        if(m_settings.flags & ContextSettings::Debug)
                        {
                            flags |= WGL_CONTEXT_DEBUG_BIT_ARB;
                        }

                        if(m_settings.flags & ContextSettings::ForwardCompatible)
                        {
                            flags |= WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
                        }

                        attribs.push_back(WGL_CONTEXT_PROFILE_MASK_ARB);
                        attribs.push_back(profile);
                        attribs.push_back(WGL_CONTEXT_FLAGS_ARB);
                        attribs.push_back(flags);
                    }

                    attribs.push_back(0);
                    attribs.push_back(0);

                    m_render = wglCreateContextAttribs(m_device, sharedHandler, &attribs[0]);

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

            updateSettings();
        }

        void WglContext::updateSettings()
        {
            int pixelFormat = GetPixelFormat(m_device);
            PIXELFORMATDESCRIPTOR pfd;
            pfd.nVersion = 1;
            pfd.nSize    = sizeof(PIXELFORMATDESCRIPTOR);

            DescribePixelFormat(m_device, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

            if(isLoaded(WglPixelFormat))
            {
                int format[2] = {0};

                static const int formatAttribs[] =
                {
                    WGL_DEPTH_BITS_ARB,
                    WGL_STENCIL_BITS_ARB
                };

                if(wglGetPixelFormatAttribiv(m_device, pixelFormat, PFD_MAIN_PLANE, 2, formatAttribs, format))
                {
                    m_settings.depths  = static_cast<Uint8>(format[0]);
                    m_settings.stencil = static_cast<Uint8>(format[1]);
                }
                else
                {
                    m_settings.depths  = pfd.cDepthBits;
                    m_settings.stencil = pfd.cStencilBits;
                }

                if(isSupported(WglMultisample))
                {
                    int sample[2] = {0};
                    static const int sampleAttribs[] =
                    {
                        WGL_SAMPLE_BUFFERS_ARB,
                        WGL_SAMPLES_ARB
                    };

                    if(wglGetPixelFormatAttribiv(m_device, pixelFormat, PFD_MAIN_PLANE, 2, sampleAttribs, sample))
                    {
                        m_settings.antialiasing = sample[0] ? sample[1] : 0;
                    }
                    else
                    {
                        m_settings.antialiasing = 0;
                    }
                }
                else
                {
                    m_settings.antialiasing = 0;
                }
            }
            else
            {
                m_settings.depths       = pfd.cDepthBits;
                m_settings.stencil      = pfd.cStencilBits;
                m_settings.antialiasing = 0;
            }
        }
    }
}
