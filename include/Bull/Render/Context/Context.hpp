#ifndef Bull_Context_hpp
#define Bull_Context_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/LocalPtr.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext;
    }

    class Context : public ContextResource, public NonCopyable
    {
    public:

        /*! \brief Get the active context in this thread
         *
         * \return Return the context is available, nullptr otherwise
         *
         */
        static LocalPtr<Context>& getActive();

    private:

        static LocalPtr<Context> s_active;

    public:

        /*! \brief Default constructor
         *
         */
        Context();

        /*! \brief Destructor
         *
         */
        ~Context();

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true);

    private:

        std::unique_ptr<prv::GlContext> m_impl;
    };
}

#endif // Bull_Context_hpp
