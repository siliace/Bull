#include <Bull/Core/Utility/CleanupCallback.hpp>

namespace Bull
{
    CleanupCallback::CleanupCallback()
    {
        enable(false);
    }

    CleanupCallback::CleanupCallback(const std::function<void()>& callback)
    {
        enable();
        reset(callback);
    }

    CleanupCallback::~CleanupCallback()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    void CleanupCallback::reset(const std::function<void()>& callback)
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
