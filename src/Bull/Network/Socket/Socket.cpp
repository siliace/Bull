#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    Socket::~Socket()
    {
        close();
    }

    SocketType Socket::getType() const
    {
        return m_type;
    }

    void Socket::enableBlockingMode(bool enable)
    {
        if(m_impl->isValid())
        {
            m_impl->enableBlockingMode(enable);
        }
    }

    bool Socket::isEnableBlockingMode() const
    {
        if(m_impl->isValid())
        {
            return m_impl->isEnableBlockingMode();
        }

        return false;
    }

    std::size_t Socket::getPendingLength() const
    {
        if(m_impl->isValid())
        {
            return m_impl->getPendingLength();
        }

        return 0;
    }

    Socket::Socket(SocketType type) :
        m_impl(prv::SocketImpl::createInstance()),
        m_type(type)
    {
        /// Nothing
    }

    bool Socket::create(NetProtocol protocol)
    {
        if(m_impl->isValid())
        {
            close();
        }

        return m_impl->create(protocol, m_type);
    }

    bool Socket::create(SocketHandler handler)
    {
        if(m_impl->isValid())
        {
            close();
        }

        return m_impl->create(handler);
    }

    void Socket::close()
    {
        m_impl.reset();
    }

    const ImplPtr<prv::SocketImpl>& Socket::getImpl() const
    {
        return m_impl;
    }
}