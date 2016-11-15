#include <Bull/Utility/CallOnExit.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param callback The function to call when the instance is destroyed
     *
     */
    CallOnExit::CallOnExit(Functor<void> callback) :
        m_callback(callback),
        m_enable(true)
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     * Call the callback if enable
     *
     */
    CallOnExit::~CallOnExit()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    /*! \brief Change the callback
     *
     * \param callback The new callback
     *
     */
    void CallOnExit::reset(Functor<void> callback)
    {
        m_callback = callback;
    }

    /*! \brief Enable or disable the callback
     *
     * \param enable Is the callback is enable?
     *
     */
    void CallOnExit::enable(bool enable)
    {
        m_enable = enable;
    }

    /*! \brief Check if the callback is enable
     *
     * \return Return true if the callback is enable, false otherwise
     *
     */
    bool CallOnExit::isEnable() const
    {
        return m_enable;
    }
}
