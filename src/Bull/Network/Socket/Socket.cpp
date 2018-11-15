#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    Socket::~Socket()
    {
        close();
    }

    bool Socket::isValid() const
    {
        return m_impl->isValid();
    }

    void Socket::enableBlockingMode(bool enable)
    {
        Expect(isValid(), Throw(LogicError, "Invalid Socket"));

        m_impl->enableBlockingMode(enable);
    }

    bool Socket::isEnableBlockingMode() const
    {
        Expect(isValid(), Throw(LogicError, "Invalid Socket"));

        return m_impl->isEnableBlockingMode();
    }

    std::size_t Socket::getPendingLength() const
    {
        Expect(isValid(), Throw(LogicError, "Invalid Socket"));

        return m_impl->getPendingLength();
    }

    SocketType Socket::getType() const
    {
        return m_type;
    }

    Socket::Socket(SocketType type) :
        m_impl(prv::SocketImpl::createInstance()),
        m_type(type)
    {
        /// Nothing
    }

    void Socket::create(NetProtocol protocol)
    {
        if(m_impl->isValid())
        {
            close();
        }

        m_impl->create(protocol, m_type);
    }

    void Socket::create(SocketHandler handler)
    {
        if(m_impl->isValid())
        {
            close();
        }

        m_impl->create(handler);
    }

    void Socket::close()
    {
        m_impl.reset();
    }

    Socket::Socket(Socket&& move) noexcept
    {
        std::swap(m_impl, move.m_impl);
        std::swap(m_type, move.m_type);
    }

    Socket& Socket::operator=(Socket&& move) noexcept
    {
        std::swap(m_impl, move.m_impl);
        std::swap(m_type, move.m_type);

        return *this;
    }

    SocketHandler Socket::getHandler() const
    {
        Expect(isValid(), Throw(LogicError, "Invalid Socket"));

        return m_impl->getHandler();
    }
}