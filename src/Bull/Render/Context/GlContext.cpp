#include <memory>

#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/LocalPtr.hpp>
#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/VideoMode.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Context/Wgl/WglContext.hpp>
    typedef Bull::prv::WglContext ContextType;
#else
    #include <Bull/Render/Context/Glx/GlxContext.hpp>
    typedef Bull::prv::GlxContext ContextType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        namespace
        {
            LocalPtr<Context> internal(nullptr);
            LocalPtr<GlContext> current(nullptr);
            std::shared_ptr<ContextType> shared;
            Mutex sharedContextMutex;

            LocalPtr<Context>& getInternalContext()
            {
                if(internal == nullptr)
                {
                    internal = new Context();
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
            shared = std::make_shared<ContextType>(nullptr, 0, VideoMode::getCurrent().bitsPerPixel);
            shared->initialize();

            /// Ensure two things:
            /// + The shared context is disabled
            /// + The internal context is enable
            shared->setActive(false);
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
            ContextType* context = new ContextType(shared, 0, VideoMode::getCurrent().bitsPerPixel);
            context->initialize();

            return context;
         }

        /*! \brief Create an OS specific instance of GlContext
         *
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         *
         * \return Return the created context
         *
         */
        GlContext* GlContext::createInstance(WindowHandler window, unsigned int bitsPerPixel)
        {
            ContextType* context = new ContextType(shared, window, bitsPerPixel);
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

        /*! \brief Enable and perform initializations
         *
         */
        void GlContext::initialize()
        {
            setActive(true);
        }
    }
}
