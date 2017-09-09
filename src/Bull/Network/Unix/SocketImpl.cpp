#include <netinet/in.h>
#include <sys/ioctl.h>

#include <Bull/Network/Unix/IpAddressImpl.hpp>
#include <Bull/Network/Unix/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        SocketHandler SocketImpl::accept(SocketHandler handler, IpAddress& ip, Socket::Port& port)
        {
            return InvalidHandler;
        }

        bool SocketImpl::bind(SocketHandler handler, const IpAddress& address, Socket::Port port)
        {
            return false;
        }

        void SocketImpl::close(SocketHandler handler)
        {

        }

        bool SocketImpl::connect(SocketHandler handler, const IpAddress& address, Socket::Port port)
        {
            return false;
        }

        SocketHandler SocketImpl::create(IpAddress::NetProtocol protocol, Socket::Type type)
        {
            return false;
        }

        Socket::State SocketImpl::lastError()
        {
            return Socket::State::Error;
        }

        bool SocketImpl::listen(SocketHandler handler, unsigned int limit)
        {
            return false;
        }

        Index SocketImpl::receive(SocketHandler handler, void* data, Index length)
        {
            return 0;
        }

        Index SocketImpl::receiveFrom(SocketHandler handler, void* data, Index length, IpAddress& from, Socket::Port& port)
        {
            return 0;
        }

        Index SocketImpl::send(SocketHandler handler, const void* data, Index length)
        {
            return 0;
        }

        Index SocketImpl::sendTo(SocketHandler handler, const IpAddress& to, Socket::Port port, const void* data, Index length)
        {
            return 0;
        }

        void SocketImpl::setBlocking(SocketHandler handler, bool blocking)
        {

        }

        int SocketImpl::translateSocketType(Socket::Type type)
        {
            return 0;
        }

        int SocketImpl::translateProtocol(IpAddress::NetProtocol protocol)
        {
            return 0;
        }
    }
}