#include <Bull/Core/Utility/Finally.hpp>

namespace Bull
{
    Finally::Finally(const std::function<void()>& callback)
    {
        enable();
        reset(callback);
    }

    Finally::~Finally()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    void Finally::reset(const std::function<void()>& callback)
    {
        m_callback = callback;
    }

    void Finally::enable(bool enable)
    {
        m_enable = enable;
    }

    bool Finally::isEnable() const
    {
        return m_enable;
    }
}
