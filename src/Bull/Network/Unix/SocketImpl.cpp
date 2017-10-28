#include <netinet/in.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <Bull/Network/Unix/IpAddressImpl.hpp>
#include <Bull/Network/Unix/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        SocketHandler SocketImpl::accept(SocketHandler handler, IpAddress& ip, NetPort& port)
        {
            return InvalidHandler;
        }

        bool SocketImpl::bind(SocketHandler handler, const IpAddress& address, NetPort port)
        {
            if(handler != InvalidHandler)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLength length = IpAddressImpl::toSockAddr(address, port, &addrBuffer);

                return ::bind(handler, reinterpret_cast<sockaddr*>(&addrBuffer), length) == -1;
            }

            return false;
        }

        void SocketImpl::close(SocketHandler handler)
        {
            if(handler != InvalidHandler)
            {
                ::close(handler);
            }
        }

        bool SocketImpl::connect(SocketHandler handler, const IpAddress& address, NetPort port)
        {
            if(handler != InvalidHandler)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLength length = IpAddressImpl::toSockAddr(address, port, &addrBuffer);

                return ::connect(handler, reinterpret_cast<sockaddr*>(&addrBuffer), length) != -1;
            }

            return false;
        }

        SocketHandler SocketImpl::create(IpAddress::NetProtocol protocol, Socket::Type type)
        {
            return socket(translateProtocol(protocol), translateSocketType(type), 0);
        }

        Socket::State SocketImpl::lastError()
        {
            return Socket::State::Error;
        }

        bool SocketImpl::listen(SocketHandler handler, unsigned int limit)
        {
            if(handler != InvalidHandler)
            {
                return ::listen(handler, limit) != -1;
            }

            return false;
        }

        Index SocketImpl::receive(SocketHandler handler, void* data, Index length)
        {
            if(handler != InvalidHandler)
            {
                ssize_t read = ::recv(handler, data, length, 0);

                if(read != - 1)
                {
                    return static_cast<Index>(read);
                }
            }

            return 0;
        }

        Index SocketImpl::receiveFrom(SocketHandler handler, void* data, Index length, IpAddress& from, NetPort& port)
        {
            return 0;
        }

        Index SocketImpl::send(SocketHandler handler, const void* data, Index length)
        {
            if(handler != InvalidHandler)
            {
                ssize_t sent = ::send(handler, data, length, 0);

                if(sent != -1)
                {
                    return static_cast<Index>(sent);
                }
            }

            return 0;
        }

        Index SocketImpl::sendTo(SocketHandler handler, const IpAddress& to, NetPort port, const void* data, Index length)
        {
            return 0;
        }

        void SocketImpl::setBlocking(SocketHandler handler, bool blocking)
        {
            if(handler != InvalidHandler)
            {
                ioctl(handler, FIONBIO, blocking ? 1 : 0);
            }
        }

        int SocketImpl::translateSocketType(Socket::Type type)
        {
            switch(type)
            {
                case Socket::Tcp: return SOCK_STREAM;
                case Socket::Udp: return SOCK_DGRAM;
                case Socket::Raw: return SOCK_RAW;
            }

            return -1;
        }

        int SocketImpl::translateProtocol(IpAddress::NetProtocol protocol)
        {
            switch(protocol)
            {
                case IpAddress::Any:     return -1;
                case IpAddress::IpV4:    return AF_INET;
                case IpAddress::IpV6:    return AF_INET6;
                case IpAddress::Unknown: return AF_UNSPEC;
            }

            return -1;
        }
    }
}