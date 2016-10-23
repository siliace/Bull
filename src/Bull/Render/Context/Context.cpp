#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    LocalPtr<Context> Context::s_active;

    /*! \brief Get the active context in this thread
     *
     * \return Return the context is available, nullptr otherwise
     *
     */
    LocalPtr<Context>& Context::getActive()
    {
        return s_active;
    }

    /*! \brief Default constructor
     *
     */
    Context::Context() :
        m_impl(prv::GlContext::createInstance())
    {
        setActive();
    }

    /*! \brief Destructor
     *
     */
    Context::~Context()
    {
        setActive(false);
    }

    /*! \brief Activate or deactivate the context
     *
     * \param active True to activate, false to deactivate the context
     *
     * \return Return true if the context's status changed successfully, false otherwise
     *
     */
    bool Context::setActive(bool active)
    {
        bool result = m_impl->setActive(active);

        if(result)
        {
            s_active = result ? this : nullptr;
        }

        return result;
    }
}
