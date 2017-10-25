#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Network/Socket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    Socket::~Socket()
    {
        close();
    }

    Socket& Socket::enableBlocking(bool blocking)
    {
        m_isBlocking = blocking;

        if(m_handler != prv::SocketImpl::InvalidHandler)
        {
            prv::SocketImpl::setBlocking(m_handler, m_isBlocking);
        }
    }

    bool Socket::isEnableBlocking() const
    {
        return m_isBlocking;
    }

    Socket::Socket(SocketType type) :
        m_type(type),
        m_handler(prv::SocketImpl::InvalidHandler),
        m_isBlocking(true)
    {
        /// Nothing
    }

    void Socket::close()
    {
        if(m_handler != prv::SocketImpl::InvalidHandler)
        {
            prv::SocketImpl::close(m_handler);
        }
    }

    void Socket::create(NetProtocol protocol)
    {
        if(m_handler == prv::SocketImpl::InvalidHandler)
        {
            m_protocol = protocol;

            SocketHandler handler = prv::SocketImpl::create(m_protocol, m_type);

            if(handler == prv::SocketImpl::InvalidHandler)
            {
                throw RuntimeError("Failed to create the socket");
            }

            reset(handler);
        }
    }

    void Socket::reset(SocketHandler handler)
    {
        if(m_handler == prv::SocketImpl::InvalidHandler)
        {
            m_handler = handler;

            enableBlocking(m_isBlocking);
        }
    }

    SocketHandler Socket::getHandler() const
    {
        return m_handler;
    }
}