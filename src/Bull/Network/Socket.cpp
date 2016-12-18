#include <Bull/Network/Socket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    Socket::~Socket()
    {
        close();
    }

    void Socket::close()
    {
        if(m_handler != prv::SocketImpl::InvalidHandler)
        {
            prv::SocketImpl::close(m_handler);

            m_handler = prv::SocketImpl::InvalidHandler;
        }
    }

    void Socket::enableBlockingMode(bool enable)
    {
        if(m_handler != prv::SocketImpl::InvalidHandler)
        {
            prv::SocketImpl::enableBlockingMode(m_handler, enable);

            m_blocking = enable;
        }
    }

    bool Socket::isEnableBlockingMode() const
    {
        return m_blocking;
    }

    Socket::Type Socket::getType() const
    {
        return m_type;
    }

    Socket::State Socket::getState() const
    {
        return m_state;
    }

    NetProtocol Socket::getProtocol() const
    {
        return m_protocol;
    }

    Socket::Socket(Type type) :
        m_handler(prv::SocketImpl::InvalidHandler),
        m_type(type)
    {
        enableBlockingMode(false);
    }

    bool Socket::create(NetProtocol protocol)
    {
        if(m_handler == prv::SocketImpl::InvalidHandler || m_protocol != protocol)
        {
            SocketHandler handler = prv::SocketImpl::create(protocol, m_type);

            if(handler == prv::SocketImpl::InvalidHandler)
            {
                return false;
            }

            m_protocol = protocol;
            create(handler);
        }

        return true;
    }

    void Socket::create(SocketHandler handler)
    {
        if(handler != prv::SocketImpl::InvalidHandler)
        {
            close();

            m_handler = handler;
            enableBlockingMode(m_blocking);
        }
    }
}
