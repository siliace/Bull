#include <Bull/Core/Utility/CleanupCallback.hpp>

namespace Bull
{
    CleanupCallback::CleanupCallback() :
        m_enable(false)
    {
        /// Nothing
    }

    CleanupCallback::CleanupCallback(Functor<void> callback) :
        m_callback(callback),
        m_enable(true)
    {
        /// Nothing
    }

    CleanupCallback::~CleanupCallback()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    void CleanupCallback::reset(Functor<void> callback)
    {
        m_callback = callback;
    }

    void CleanupCallback::enable(bool enable)
    {
        m_enable = enable;
    }

    bool CleanupCallback::isEnable() const
    {
        return m_enable;
    }
}
