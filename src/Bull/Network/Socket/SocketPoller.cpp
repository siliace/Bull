#include <Bull/Core/Exception/InvalidParameter.hpp>

#include <Bull/Network/Socket/SocketImpl.hpp>
#include <Bull/Network/Socket/SocketPoller.hpp>
#include <Bull/Network/Socket/SocketPollerImpl.hpp>

namespace Bull
{
    SocketPoller::SocketPoller() :
            m_impl(prv::SocketPollerImpl::createInstance())
    {
        /// Nothing
    }

    SocketPoller::~SocketPoller() = default;

    void SocketPoller::add(const Socket& socket, SocketPollerEvent event)
    {
        if(!isAdded(socket))
        {
            m_impl->add(socket.getHandler(), event);
        }
    }

    void SocketPoller::remove(const Socket& socket)
    {
        if(isAdded(socket))
        {
            m_impl->remove(socket.getHandler());
        }
    }

    void SocketPoller::clear()
    {
        m_impl->clear();
    }

    bool SocketPoller::wait()
    {
        return m_impl->wait();
    }

    bool SocketPoller::wait(const Duration& timeout)
    {
        return m_impl->wait(timeout);
    }

    bool SocketPoller::isAdded(const Socket& socket)
    {
        Expect(socket.isValid(), Throw(InvalidParameter, "Invalid Socket"));

        return m_impl->isAdded(socket.getHandler());
    }

    bool SocketPoller::isReadyToRead(const Socket& socket)
    {
        if(isAdded(socket))
        {
            return m_impl->isReadyToRead(socket.getHandler());
        }

        return false;
    }

    bool SocketPoller::isReadyToWrite(const Socket& socket)
    {
        if(isAdded(socket))
        {
            return m_impl->isReadyToWrite(socket.getHandler());
        }

        return false;
    }
}