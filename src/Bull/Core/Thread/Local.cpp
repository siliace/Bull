#include <Bull/Core/Thread/Local.hpp>
#include <Bull/Core/Thread/LocalImpl.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param value The value to initialize the variable
     *
     */
    Local::Local(void* value) :
        m_impl(nullptr)
    {
        m_impl.reset(prv::LocalImpl::createInstance());
        set(value);
    }

    /*! \brief Destructor
     *
     */
    Local::~Local()
    {
        m_impl.reset(nullptr);
    }

    /*! \brief Set the value
     *
     * \param value The new value of the variable
     *
     */
    void Local::set(void* value)
    {
        if(m_impl)
        {
            return m_impl->set(value);
        }
    }

    /*! \brief Get the value
     *
     * \return Return the value of the variable
     *
     */
    void* Local::get() const
    {
        if(m_impl)
        {
            return m_impl->get();
        }

        return nullptr;
    }

    /*! \brief Get the system native handler
     *
     * \return Return the system native handler
     *
     */
    LocalHandler Local::getSystemHandler() const
    {
        if(m_impl)
        {
            return m_impl->getSystemHandler();
        }

        return 0;
    }
}
