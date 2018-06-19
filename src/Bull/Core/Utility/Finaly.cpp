#include <Bull/Core/Utility/Finaly.hpp>

namespace Bull
{
    Finaly::Finaly()
    {
        enable(false);
    }

    Finaly::Finaly(const std::function<void()>& callback)
    {
        enable();
        reset(callback);
    }

    Finaly::~Finaly()
    {
        if(m_enable)
        {
            m_callback();
        }
    }

    void Finaly::reset(const std::function<void()>& callback)
    {
        m_callback = callback;
    }

    void Finaly::enable(bool enable)
    {
        m_enable = enable;
    }

    bool Finaly::isEnable() const
    {
        return m_enable;
    }
}
