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
        if(m_impl)
        {
            m_impl->enableBlockingMode(enable);
        }
    }

    bool Socket::isEnableBlockingMode() const
    {
        if(m_impl)
        {
            return m_impl->isEnableBlockingMode();
        }

        return false;
    }

    Socket::Socket(SocketType type) :
        m_impl(prv::SocketImpl::createInstance()),
        m_type(type)
    {
        /// Nothing
    }

    bool Socket::create(NetProtocol protocol)
    {
        return m_impl->create(protocol, m_type);
    }

    void Socket::close()
    {
        m_impl.reset();
    }

    const std::unique_ptr<prv::SocketImpl>& Socket::getImpl() const
    {
        return m_impl;
    }
}