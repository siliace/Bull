#include <Bull/Core/Utility/CallOnExit.hpp>

namespace Bull
{
    CallOnExit::CallOnExit() :
        m_enable(false)
    {
        /// Nothing
    }

    CallOnExit::CallOnExit(Functor<void> callback) :
        m_callback(callback),
        m_enable(true)
    {
        /// Nothing
    }

    CallOnExit::~CallOnExit()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    void CallOnExit::reset(Functor<void> callback)
    {
        m_callback = callback;
    }

    void CallOnExit::enable(bool enable)
    {
        m_enable = enable;
    }

    bool CallOnExit::isEnable() const
    {
        return m_enable;
    }
}
