#include <limits>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/System/Library.hpp>

#include <Bull/Render/Context/Wgl/WglContext.hpp>
#include <Bull/Render/Context/Wgl/WglCreateContextARB.hpp>
#include <Bull/Render/Context/Wgl/WglMultisampleARB.hpp>
#include <Bull/Render/Context/Wgl/WglPbufferARB.hpp>
#include <Bull/Render/Context/Wgl/WglPixelFormatARB.hpp>
#include <Bull/Render/Context/Wgl/WglSwapControlEXT.hpp>

namespace Bull
{
    namespace prv
    {
        void* WglContext::getFunction(const std::string& function)
        {
            void* functionProc = reinterpret_cast<void*>(wglGetProcAddress(function.c_str()));

            if(functionProc)
            {
                return functionProc;
            }

            // wglGetProcAddress will set the last error to 127 if a function is not found but we don't care here
            SetLastError(0);

            static Library library("opengl32.dll");

            if(!library)
            {
                return nullptr;
            }

            return library.getSymbolPointer(function);
        }

        void WglContext::requireExtensions(ExtensionsLoader& loader)
        {
            loader.require(wglCreateContext);
            loader.require(wglPixelFormat);
            loader.require(wglSwapControl);
            loader.require(wglPbuffer);
        }

        int WglContext::getBestPixelFormat(HDC device, Uint8 bitsPerPixel, const ContextSettings& settings, bool usePbuffer)
        {
            int bestPixelFormat = 0;

            if(wglPixelFormat.isLoaded())
            {
                static const int attribs[] = {
                        WGL_DRAW_TO_WINDOW_ARB, 1,
                        WGL_SUPPORT_OPENGL_ARB, 1,
                        WGL_DOUBLE_BUFFER_ARB, 1,
                        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
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
                        int format[7] = {0};
                        int sample[2] = {0};
                        static const int formatAttribs[] = {
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

                        if(isSupported("WGL_ARB_multisample"))
                        {
                            static const int sampleAttribs[] = {
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
                            static const int pbufferAttribs[] = {
                                    WGL_DRAW_TO_PBUFFER_ARB
                            };

                            if(!wglGetPixelFormatAttribiv(device, formats[i], PFD_MAIN_PLANE, 1, pbufferAttribs, &pbuffer))
                            {
                                break;
                            }
                            else if(pbuffer != 1)
                            {
                                continue;
                            }
                        }

                        /// We don't care about non hardware accelerated pixel format
                        if(format[6])
                        {
                            int colors = format[0] + format[1] + format[2] + format[3];
                            int score = evaluatePixelFormat(colors, format[4], format[5], sample[0] ? sample[1] : 0, bitsPerPixel, settings);

                            if(bestScore > score)
                            {
                                bestScore = score;
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
                descriptor.nSize = sizeof(descriptor);
                descriptor.nVersion = 1;
                descriptor.iLayerType = PFD_MAIN_PLANE;
                descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
                descriptor.iPixelType = PFD_TYPE_RGBA;
                descriptor.cColorBits = bitsPerPixel;
                descriptor.cDepthBits = settings.depths;
                descriptor.cStencilBits = settings.stencil;
                descriptor.cAlphaBits = bitsPerPixel == 32 ? 8 : 0;

                bestPixelFormat = ChoosePixelFormat(device, &descriptor);
            }

            return bestPixelFormat;
        }

        WglContext::WglContext(const WglContext* shared) :
                WglContext(shared, VideoMode(Size<unsigned int>(1, 1)), ContextSettings())
        {
            /// Nothing
        }

        WglContext::WglContext(const WglContext* shared, const VideoMode& mode, const ContextSettings& settings) :
                GlContext(settings),
                m_device(nullptr),
                m_render(nullptr),
                m_pbuffer(nullptr),
                m_ownWindow(false)
        {
            createSurface(shared, mode.getSize().getWidth(), mode.getSize().getHeight(), mode.getBitsPerPixel());

            setPixelFormat(mode.getBitsPerPixel());

            createContext(shared);
        }

        WglContext::WglContext(const WglContext* shared, Uint8 bitsPerPixel, const ContextSettings& settings) :
                WglContext(shared, VideoMode(Size<unsigned int>(1, 1), bitsPerPixel), settings)
        {
            /// Nothing
        }

        WglContext::WglContext(const WglContext* shared, const WindowImpl& window, Uint8 bitsPerPixel, const ContextSettings& settings) :
                GlContext(settings),
                m_device(nullptr),
                m_render(nullptr),
                m_pbuffer(nullptr),
                m_ownWindow(false)
        {
            createSurface(window);

            setPixelFormat(bitsPerPixel);

            createContext(shared);
        }

        WglContext::~WglContext()
        {
            if(m_render)
            {
                if(wglGetCurrentContext() == m_render)
                {
                    wglMakeCurrent(nullptr, nullptr);
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
            if(wglSwapControl.isLoaded())
            {
                wglSwapInterval(active ? 1 : 0);
            }
        }

        void WglContext::makeCurrent()
        {
            if(m_pbuffer)
            {
                int flag = 0;
                wglQueryPbuffer(m_pbuffer, WGL_PBUFFER_LOST_ARB, &flag);

                Expect(!flag, Throw(InternalError, "PBuffer is became invalid"));
            }

            Expect(wglMakeCurrent(m_device, m_render), Throw(Win32Error, "Failed to make context current"));
        }

        void WglContext::createSurface(const WindowImpl& window)
        {
            m_window = window.getSystemHandler();

            m_device = GetDC(m_window);

            Expect(m_device != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to get device context from WindowImpl"));
        }

        void WglContext::createSurface(const WglContext* shared, unsigned int width, unsigned int height, Uint8 bitsPerPixel)
        {
            #ifdef BULL_WGL_PBUFFER_SUPPORT
            if(wglPbuffer.isLoaded() && shared)
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
                            Log::getInstance().warning("Failed to get device context from PBuffer");

                            wglDestroyPbuffer(m_pbuffer);
                        }
                    }
                }
            }
            #else
            BULL_UNUSED(bitsPerPixel);
            #endif

            if(!m_device)
            {
                m_window = CreateWindow("STATIC", nullptr,
                                        WS_DISABLED | WS_POPUP,
                                        0, 0,
                                        width, height,
                                        nullptr,
                                        nullptr,
                                        GetModuleHandle(nullptr),
                                        nullptr);

                Expect(m_window != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to create internal window"));

                m_device = GetDC(m_window);

                Expect(m_device != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to get device context"));

                m_ownWindow = true;
            }
        }

        void WglContext::setPixelFormat(Uint8 bitsPerPixel)
        {
            PIXELFORMATDESCRIPTOR descriptor;
            int bestFormat = getBestPixelFormat(m_device, bitsPerPixel, m_settings);

            descriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            descriptor.nVersion = 1;
            DescribePixelFormat(m_device, bestFormat, sizeof(PIXELFORMATDESCRIPTOR), &descriptor);

            Expect(SetPixelFormat(m_device, bestFormat, &descriptor), Throw(Win32Error, "Failed to set pixel format"));
        }

        void WglContext::createContext(const WglContext* shared)
        {
            Log& log = Log::getInstance();
            HGLRC sharedHandler = shared ? shared->m_render : nullptr;

            if(wglCreateContext.isLoaded())
            {
                do
                {
                    std::vector<int> attribs;

                    attribs.emplace_back(WGL_CONTEXT_MAJOR_VERSION_ARB);
                    attribs.emplace_back(m_settings.major);
                    attribs.emplace_back(WGL_CONTEXT_MINOR_VERSION_ARB);
                    attribs.emplace_back(m_settings.minor);

                    if(isSupported("WGL_ARB_create_context_profile"))
                    {
                        int flags = 0;
                        int profile = (m_settings.profile == ContextSettingsProfile_Compatibility) ? WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB : WGL_CONTEXT_CORE_PROFILE_BIT_ARB;

                        if(m_settings.type == ContextSettingsType_Debug)
                        {
                            flags |= WGL_CONTEXT_DEBUG_BIT_ARB;
                        }

                        if(m_settings.type == ContextSettingsType_ForwardCompatible)
                        {
                            flags |= WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
                        }

                        attribs.emplace_back(WGL_CONTEXT_PROFILE_MASK_ARB);
                        attribs.emplace_back(profile);
                        attribs.emplace_back(WGL_CONTEXT_FLAGS_ARB);
                        attribs.emplace_back(flags);
                    }

                    attribs.emplace_back(0);

                    m_render = wglCreateContextAttribs(m_device, sharedHandler, &attribs[0]);

                    if(!m_render)
                    {
                        log.warning("Failed to create WglContext with version " + std::to_string(m_settings.major) + "." + std::to_string(m_settings.minor));

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
                        log.info("Create WglContext with version " + std::to_string(m_settings.major) + "." + std::to_string(m_settings.minor));
                    }
                }while(!m_render && m_settings.major >= 1);
            }

            if(m_render == nullptr)
            {
                m_render = ::wglCreateContext(m_device);

                Expect(m_render, Throw(InternalError, "Failed to create legacy/shared WglContext"));

                if(shared)
                {
                    static std::mutex mutex;

                    log.info("Create legacy WglContext");

                    std::lock_guard<std::mutex> lock(mutex);

                    wglShareLists(sharedHandler, m_render);
                }
                else
                {
                    log.info("Create shared WglContext");
                }
            }

            updateSettings();
        }

        void WglContext::updateSettings()
        {
            PIXELFORMATDESCRIPTOR pfd;
            pfd.nVersion = 1;
            pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);

            int pixelFormat = GetPixelFormat(m_device);
            DescribePixelFormat(m_device, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

            if(wglPixelFormat.isLoaded())
            {
                int format[2] = {0};

                static const int formatAttribs[] = {
                        WGL_DEPTH_BITS_ARB,
                        WGL_STENCIL_BITS_ARB
                };

                if(wglGetPixelFormatAttribiv(m_device, pixelFormat, PFD_MAIN_PLANE, 2, formatAttribs, format))
                {
                    m_settings.depths = static_cast<Uint8>(format[0]);
                    m_settings.stencil = static_cast<Uint8>(format[1]);
                }
                else
                {
                    m_settings.depths = pfd.cDepthBits;
                    m_settings.stencil = pfd.cStencilBits;
                }

                if(isSupported("WGL_ARB_multisample"))
                {
                    int sample[2] = {0};
                    static const int sampleAttribs[] = {
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
                m_settings.depths = pfd.cDepthBits;
                m_settings.stencil = pfd.cStencilBits;
                m_settings.antialiasing = 0;
            }
        }
    }
}
