#include <memory>
#include <set>

#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/LocalPtr.hpp>
#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/VideoMode.hpp>

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
            thread_local std::shared_ptr<Context> internal(nullptr);
            std::set<std::shared_ptr<Context>> internals;
            Mutex internalsMutex;

            LocalPtr<GlContext> current(nullptr);

            std::shared_ptr<ContextType> shared;
            Mutex sharedContextMutex;

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

        /*! \brief Perform internal initialization
         *
         */
        void GlContext::globalInit()
        {
            Lock lock(sharedContextMutex);
            ExtensionsLoader::Instance loader = ExtensionsLoader::get();
            shared = std::make_shared<ContextType>(nullptr);
            shared->initialize();

            ContextType::requireExtensions(loader);
            loader->load(shared->getSurfaceHandler());

            /// Ensure two things:
            /// + The shared context is disabled
            /// + The internal context is enable
            shared->setActive(false);
        }

         /*! \brief Perform internal cleanup
          *
          */
         void GlContext::globalCleanup()
         {
             Lock lockInternals(internalsMutex);
             internals.clear();

             Lock lockShared(sharedContextMutex);
             shared.reset();
         }

        /*! \brief Ensure there is an active OpenGL context in this thread
         *
         */
        void GlContext::ensureContext()
        {
            if(Context::getActive() == nullptr)
            {
                getInternalContext();
            }
        }

        /*! \brief Create an OS specific instance of GlContext
         *
         * \return Return the created context
         *
         */
         GlContext* GlContext::createInstance()
         {
            ContextType* context = new ContextType(shared);
            context->initialize();

            return context;
         }

        /*! \brief Create an OS specific instance of GlContext
         *
         * \param bitsPerPixel Number of bits per pixel to use
         * \param settings     Settings to use to create the context
         *
         * \return Return the created context
         *
         */
        GlContext* GlContext::createInstance(unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            ContextType* context = new ContextType(shared, bitsPerPixel, settings);
            context->initialize();

            return context;
        }

        /*! \brief Create an OS specific instance of GlContext
         *
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         * \param settings Parameters to create the OpenGL context
         *
         * \return Return the created context
         *
         */
        GlContext* GlContext::createInstance(WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings)
        {
            ContextType* context = new ContextType(shared, window, bitsPerPixel, settings);
            context->initialize();

            return context;
        }

        /*! \brief Get an OpenGL function
         *
         * \param function The function name
         *
         * \param Return the function, nullptr if the function is not available
         *
         */
        void* GlContext::getFunction(const String& function)
        {
            return ContextType::getFunction(function);
        }

        /*! \brief Destructor
         *
         */
        GlContext::~GlContext()
        {
            /// Nothing
        }

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
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

        /*! \brief Get the ContextSettings of the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& GlContext::getSettings() const
        {
            return m_settings;
        }

        /*! \brief Constructor
         *
         * \param settings Settings to use to create the context
         *
         */
        GlContext::GlContext(const ContextSettings& settings) :
            m_settings(settings)
        {
            /// Nothing
        }

        /*! \brief Enable and perform initializations
         *
         */
        void GlContext::initialize()
        {
            setActive(true);
        }
    }
}
