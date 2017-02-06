#include <memory>
#include <set>

#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/GlLoader.hpp>

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
        namespace
        {
            Mutex internalsMutex;
            Mutex sharedContextMutex;
            std::shared_ptr<ContextType> shared;
            std::set<std::shared_ptr<Context>> internals;
            thread_local const GlContext* current(nullptr);
            thread_local std::shared_ptr<Context> internal(nullptr);

            std::shared_ptr<Context> getInternalContext()
            {
                if(internal == nullptr)
                {
                    internal = std::make_shared<Context>();

                    Lock lock(internalsMutex);
                    internals.insert(internal);
                }

                return internal;
            }
        }

        void GlContext::globalInit()
        {
            Lock lock(sharedContextMutex);

            shared = std::make_shared<ContextType>(nullptr);
            shared->setActive(true);

            /// We load OpenGL functions before initialize because this method uses OpenGL functions (glEnable, glGetIntegerv...)
            ExtensionsLoader::Instance loader = ExtensionsLoader::get(shared->getSurfaceHandler());
            ContextType::requireExtensions(loader);
            GlLoader::load();
            loader->load();

            shared->initialize();

            /// Ensure two things:
            /// + The shared context is disabled
            /// + The internal context is enable
            shared->setActive(false);
        }

         void GlContext::globalCleanup()
         {
             Lock lockInternals(internalsMutex);
             internals.clear();

             Lock lockShared(sharedContextMutex);
             shared.reset();
         }

        void GlContext::ensureContext()
        {
            if(Context::getActive() == nullptr)
            {
                getInternalContext();
            }
        }

         GlContext* GlContext::createInstance()
         {
            ContextType* context = new ContextType(shared);
            context->initialize();

            return context;
         }

        GlContext* GlContext::createInstance(const VideoMode& mode, const ContextSettings& settings)
        {
            ContextType* context = new ContextType(shared, mode, settings);
            context->initialize();

            return context;
        }

        GlContext* GlContext::createInstance(unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            ContextType* context = new ContextType(shared, bitsPerPixel, settings);
            context->initialize(settings);

            return context;
        }

        GlContext* GlContext::createInstance(WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            ContextType* context = new ContextType(shared, window, bitsPerPixel, settings);
            context->initialize(settings);

            return context;
        }

        void* GlContext::getFunction(const String& function)
        {
            return ContextType::getFunction(function);
        }

        bool GlContext::isLoaded(const String& extension)
        {
            return ExtensionsLoader::isSet() ? ExtensionsLoader::get()->isLoaded(extension) : false;
        }

        bool GlContext::isLoaded(const ExtensionsLoader::Extension& extension)
        {
            return ExtensionsLoader::isSet() ? ExtensionsLoader::get()->isLoaded(extension) : false;
        }

        bool GlContext::isSupported(const String& extension)
        {
            return ExtensionsLoader::isSet() ? ExtensionsLoader::get()->isSupported(extension) : false;
        }

        bool GlContext::isSupported(const ExtensionsLoader::Extension& extension)
        {
            return ExtensionsLoader::isSet() ? ExtensionsLoader::get()->isSupported(extension) : false;
        }

        int GlContext::evaluatePixelFormat(unsigned int bitsPerPixel, int depths, int stencil, unsigned int antialiasing, unsigned int bitsPerPixelWanted, const ContextSettings& settingsWanted)
        {
            int colorDiff        = static_cast<int>(bitsPerPixelWanted)          - bitsPerPixel;
            int depthDiff        = static_cast<int>(settingsWanted.depths)       - depths;
            int stencilDiff      = static_cast<int>(settingsWanted.stencil)      - stencil;
            int antialiasingDiff = static_cast<int>(settingsWanted.antialiasing) - antialiasing;

            colorDiff        *= ((colorDiff        > 0) ? 100000 : 1);
            depthDiff        *= ((depthDiff        > 0) ? 100000 : 1);
            stencilDiff      *= ((stencilDiff      > 0) ? 100000 : 1);
            antialiasingDiff *= ((antialiasingDiff > 0) ? 100000 : 1);

            int score = std::abs(colorDiff) + std::abs(depthDiff) + std::abs(stencilDiff) + std::abs(antialiasingDiff);

            return score;
        }

        GlContext::~GlContext()
        {
            /// Nothing
        }

        bool GlContext::setActive(bool active)
        {
            if(active)
            {
                if(current != this)
                {
                    if(makeCurrent())
                    {
                       current = this;

                       return true;
                    }

                    return false;
                }

                return true;
            }
            else
            {
                if(current == this)
                {
                    return getInternalContext()->setActive(true);
                }

                return true;
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
            if(setActive(true))
            {
                int majorVersion = 0;
                int minorVersion = 0;

                gl::getIntegerv(GL_MAJOR_VERSION, &majorVersion);
                gl::getIntegerv(GL_MINOR_VERSION, &minorVersion);

                if(gl::getError() != GL_INVALID_ENUM)
                {
                    m_settings.major = static_cast<unsigned int>(majorVersion);
                    m_settings.minor = static_cast<unsigned int>(minorVersion);
                }
                else
                {
                    const GLubyte* version = gl::getString(GL_VERSION);

                    if (version)
                    {
                        m_settings.major = String::intToChar(version[0]);
                        m_settings.minor = String::intToChar(version[2]);
                    }
                    else
                    {
                        m_settings.major = 1;
                        m_settings.minor = 1;
                    }
                }

                m_settings.flags = ContextSettings::Default;

                if(m_settings.major >= 3)
                {
                    int flags;
                    gl::getIntegerv(GL_CONTEXT_FLAGS, &flags);

                    if(flags && GL_CONTEXT_FLAG_DEBUG_BIT)
                    {
                        m_settings.flags |= ContextSettings::Debug;
                    }

                    if(flags && GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT)
                    {
                        m_settings.flags |= ContextSettings::ForwardCompatible;
                    }

                    if(m_settings.major == 3 && m_settings.minor == 1 && isSupported("GL_ARB_compatibility"))
                    {
                        m_settings.flags |= ContextSettings::Compatibility;
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
}
