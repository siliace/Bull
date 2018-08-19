#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/Utility/Character.hpp>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Context/Wgl/WglContext.hpp>
    typedef Bull::prv::WglContext ContextType;
#else
    #include <Bull/Render/Context/Glx/GlxContext.hpp>
    typedef Bull::prv::GlxContext ContextType;
#endif

namespace Bull
{
    namespace prv
    {
        DeclareException(WrongOpenGLVersion);

        namespace
        {
            /// A lock to ensure to create only once the shared context
            std::mutex sharedContextMutex;

            /// The context shared with all others
            std::unique_ptr<ContextType> shared;

            /// The context activate in this thread
            thread_local const GlContext* current = nullptr;

            /// The internal context of this thread
            thread_local std::unique_ptr<Context> internal = nullptr;

            Context& getInternalContext()
            {
                if(!internal)
                {
                    ContextSettings realInternalSettings;
                    internal = std::make_unique<Context>(VideoMode::getCurrent().bitsPerPixel, ContextSettings(0, 0, 0, 3, 3));

                    realInternalSettings = internal->getSettings();

                    Uint8 major = realInternalSettings.major;
                    Uint8 minor = realInternalSettings.minor;

                    Expect(major > 3 || major == 3 && minor >= 3, Throw(WrongOpenGLVersion, "getInternalContext", "Bull needs OpenGL 3.3 or higher to work"));
                }

                return *internal;
            }
        }

        void GlContext::globalInit()
        {
            std::lock_guard<std::mutex> lock(sharedContextMutex);

            shared = std::make_unique<ContextType>(nullptr);
            shared->setActive(true);

            /// We load OpenGL functions before initialize because this method uses OpenGL functions (glEnable, glGetIntegerv...)
            ExtensionsLoader::Instance loader;

            ContextType::requireExtensions(loader);
            loader->loadFunctions();
            loader->loadExtensions(shared->getSurfaceHandler());

            shared->initialize();

            /// Ensure two things:
            /// + The shared context is disabled (and should always be)
            /// + The internal context is enable
            shared->setActive(false);
        }

        void GlContext::ensureContext()
        {
            /// This will create a context if there no one in the current thread, do nothing otherwise
            getInternalContext();
        }

        std::unique_ptr<GlContext> GlContext::createInstance()
        {
            std::unique_ptr<GlContext> context = std::make_unique<ContextType>(shared.get());
            context->initialize();

            return context;
        }

        std::unique_ptr<GlContext> GlContext::createInstance(const VideoMode& mode, const ContextSettings& settings)
        {
            std::unique_ptr<GlContext> context = std::make_unique<ContextType>(shared.get(), mode, settings);
            context->initialize();

            return context;
        }

        std::unique_ptr<GlContext> GlContext::createInstance(unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            std::unique_ptr<GlContext> context = std::make_unique<ContextType>(shared.get(), bitsPerPixel, settings);
            context->initialize(settings);

            return context;
        }

        std::unique_ptr<GlContext> GlContext::createInstance(const WindowImpl& window, unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            std::unique_ptr<GlContext> context = std::make_unique<ContextType>(shared.get(), window, bitsPerPixel, settings);
            context->initialize(settings);

            return context;
        }

        void* GlContext::getFunction(const String& function)
        {
            return ContextType::getFunction(function);
        }

        bool GlContext::isSupported(const String& extension)
        {
            return ExtensionsLoader::getInstance()->isSupported(extension);
        }

        void GlContext::debugProc(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* msg, const void* userParam)
        {
            String message(msg);
            OutStringStream oss;
            TextWriter writer(oss);

            switch(type)
            {
                case GL_DEBUG_TYPE_ERROR:               writer << "[Type: Error]"; break;
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: writer << "[Type: Deprecated Behaviour]"; break;
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  writer << "[Type: Undefined Behaviour]"; break;
                case GL_DEBUG_TYPE_PORTABILITY:         writer << "[Type: Portability]"; break;
                case GL_DEBUG_TYPE_PERFORMANCE:         writer << "[Type: Performance]"; break;
                case GL_DEBUG_TYPE_MARKER:              writer << "[Type: Marker]"; break;
                case GL_DEBUG_TYPE_PUSH_GROUP:          writer << "[Type: Push Group]"; break;
                case GL_DEBUG_TYPE_POP_GROUP:           writer << "[Type: Pop Group]"; break;
                case GL_DEBUG_TYPE_OTHER:               writer << "[Type: Other]"; break;
            }

            switch(source)
            {
                case GL_DEBUG_SOURCE_API:             writer << "[Source: API]"; break;
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   writer << "[Source: Window System]"; break;
                case GL_DEBUG_SOURCE_SHADER_COMPILER: writer << "[Source: Shader Compiler]"; break;
                case GL_DEBUG_SOURCE_THIRD_PARTY:     writer << "[Source: Third Party]"; break;
                case GL_DEBUG_SOURCE_APPLICATION:     writer << "[Source: Application]"; break;
                case GL_DEBUG_SOURCE_OTHER:           writer << "[Source: Other]"; break;
            }

            writer << message;

            if(severity == GL_DEBUG_SEVERITY_NOTIFICATION)
            {
                Log::getInstance()->info(oss.toString());
            }
            else
            {
                Log::getInstance()->error(oss.toString());
            }
        }

        int GlContext::evaluatePixelFormat(unsigned int bitsPerPixel, int depths, int stencil, unsigned int antialiasing, unsigned int bitsPerPixelWanted, const ContextSettings& settingsWanted)
        {
            int colorDiff        = bitsPerPixelWanted          - bitsPerPixel;
            int depthDiff        = settingsWanted.depths       - depths;
            int stencilDiff      = settingsWanted.stencil      - stencil;
            int antialiasingDiff = settingsWanted.antialiasing - antialiasing;

            colorDiff        *= ((colorDiff        > 0) ? 100000 : 1);
            depthDiff        *= ((depthDiff        > 0) ? 100000 : 1);
            stencilDiff      *= ((stencilDiff      > 0) ? 100000 : 1);
            antialiasingDiff *= ((antialiasingDiff > 0) ? 100000 : 1);

            int score = std::abs(colorDiff) + std::abs(depthDiff) + std::abs(stencilDiff) + std::abs(antialiasingDiff);

            return score;
        }

        GlContext::~GlContext() = default;

        void GlContext::setActive(bool active)
        {
            if(active)
            {
                if(current != this)
                {
                    makeCurrent();

                    current = this;
                }
            }
            else
            {
                if(current == this)
                {
                    getInternalContext().setActive(true);
                }
            }
        }

        const ContextSettings& GlContext::getSettings() const
        {
            return m_settings;
        }

        GlContext::GlContext(const ContextSettings& settings) :
            m_settings(settings)
        {
            /// Nothing
        }

        void GlContext::initialize(const ContextSettings& wanted)
        {
            setActive(true);

            gl::debugMessageCallback(&GlContext::debugProc, this);

            int majorVersion = 0;
            int minorVersion = 0;

            gl::getIntegerv(GL_MAJOR_VERSION, &majorVersion);
            gl::getIntegerv(GL_MINOR_VERSION, &minorVersion);

            if(gl::getError() != GL_INVALID_ENUM)
            {
                m_settings.major = static_cast<Uint8>(majorVersion);
                m_settings.minor = static_cast<Uint8>(minorVersion);
            }
            else
            {
                String version = reinterpret_cast<const char*>(gl::getString(GL_VERSION));

                if(!version.isEmpty())
                {
                    m_settings.major = static_cast<Uint8>(Character::charToInt(version[0]));
                    m_settings.minor = static_cast<Uint8>(Character::charToInt(version[2]));
                }
                else
                {
                    m_settings.major = 1;
                    m_settings.minor = 1;
                }
            }

            m_settings.type = ContextSettingsType_Default;

            gl::enable(GL_DEPTH_TEST);

            if(m_settings.major >= 3)
            {
                int flags;
                gl::getIntegerv(GL_CONTEXT_FLAGS, &flags);

                if(flags & GL_CONTEXT_FLAG_DEBUG_BIT)
                {
                    m_settings.type |= ContextSettingsType_Debug;
                }

                if(flags & GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT)
                {
                    m_settings.type |= ContextSettingsType_ForwardCompatible;
                }

                if(m_settings.major == 3 && m_settings.minor == 1 && isSupported("GL_ARB_compatibility"))
                {
                    m_settings.type |= ContextSettingsProfile_Compatibility;
                }
            }

            if(m_settings.antialiasing > 0 && wanted.antialiasing > 0)
            {
                gl::enable(GL_MULTISAMPLE);

                if(!gl::isEnabled(GL_MULTISAMPLE))
                {
                    m_settings.antialiasing = 0;
                }
            }
            else
            {
                m_settings.antialiasing = 0;
            }
        }
    }
}
