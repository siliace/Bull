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

    bool SocketPoller::add(const Socket& socket, SocketPollerEvent event)
    {
        if(!isAdded(socket) && socket.getImpl().isValid())
        {
            m_impl->add(socket.getImpl().getHandler(), event);

            return true;
        }

        return false;
    }

    void SocketPoller::remove(const Socket& socket)
    {
        if(isAdded(socket) && socket.getImpl().isValid())
        {
            m_impl->remove(socket.getImpl().getHandler());
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
        return m_impl->isAdded(socket.getImpl().getHandler());
    }

    bool SocketPoller::isReadyToRead(const Socket& socket)
    {
        if(isAdded(socket) && socket.getImpl().isValid())
        {
            return m_impl->isReadyToRead(socket.getImpl().getHandler());
        }

        return false;
    }

    bool SocketPoller::isReadyToWrite(const Socket& socket)
    {
        if(isAdded(socket) && socket.getImpl().isValid())
        {
            return m_impl->isReadyToWrite(socket.getImpl().getHandler());
        }

        return false;
    }
}