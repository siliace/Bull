#include <Bull/Network/Win32/IpAddressImpl.hpp>
#include <Bull/Network/Win32/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        struct Wsa
        {
            Wsa()
            {
                WSAData data;
                WSAStartup(MAKEWORD(2, 2), &data);
            }

            ~Wsa()
            {
                WSACleanup();
            }
        };

        Wsa wsa;

        SocketHandler SocketImpl::accept(SocketHandler handler, IpAddress& ip, Socket::Port& port)
        {
            if(handler != InvalidHandler)
            {
                SocketHandler                 client;
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght length = static_cast<int>(addrBuffer.size());

                client = ::accept(handler, reinterpret_cast<sockaddr*>(&addrBuffer), &length);

                if(client != InvalidHandler)
                {
                    ip = IpAddressImpl::fromSockAddr(reinterpret_cast<const sockaddr*>(&addrBuffer), port);

                    return client;
                }
            }

            return InvalidHandler;
        }

        bool SocketImpl::bind(SocketHandler handler, const IpAddress& address, Socket::Port port)
        {
            if(handler != InvalidHandler && address.isValid() && port != Socket::AnyPort)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght length = IpAddressImpl::toSockAddr(address, port, &addrBuffer);

                return ::bind(handler, reinterpret_cast<sockaddr*>(&addrBuffer), length) != SOCKET_ERROR;
            }

            return false;
        }

        void SocketImpl::close(SocketHandler handler)
        {
            if(handler != InvalidHandler)
            {
                closesocket(handler);
            }
        }

        bool SocketImpl::connect(SocketHandler handler, const IpAddress& address, Socket::Port port)
        {
            if(handler != InvalidHandler && address.isValid() && port != Socket::AnyPort)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght length = IpAddressImpl::toSockAddr(address, port, &addrBuffer);

                return ::connect(handler, reinterpret_cast<sockaddr*>(&addrBuffer), length) != SOCKET_ERROR;
            }

            return false;
        }

        SocketHandler SocketImpl::create(IpAddress::NetProtocol protocol, Socket::Type type)
        {
            return socket(translateProtocol(protocol), translateSocketType(type), 0);
        }

        Socket::State SocketImpl::lastError()
        {
            switch(WSAGetLastError())
            {
                case WSAEWOULDBLOCK:   return Socket::NotReady;
                case WSAEALREADY:      return Socket::NotReady;
                case WSAECONNABORTED:  return Socket::Disconnected;
                case WSAECONNRESET:    return Socket::Disconnected;
                case WSAETIMEDOUT:     return Socket::Disconnected;
                case WSAENETRESET:     return Socket::Disconnected;
                case WSAENOTCONN:      return Socket::Disconnected;
                case WSAEISCONN:       return Socket::Ready;
                case WSAEADDRNOTAVAIL: return Socket::ConnectionRefused;
                default:               return Socket::Error;
            }
        }

        bool SocketImpl::listen(SocketHandler handler, unsigned int limit)
        {
            if(handler != InvalidHandler)
            {
                return ::listen(handler, limit) != SOCKET_ERROR;
            }

            return false;
        }

        std::size_t SocketImpl::receive(SocketHandler handler, void* data, std::size_t length)
        {
            if(handler != InvalidHandler && data && length)
            {
                return ::recv(handler, static_cast<char*>(data), length, 0);
            }

            return 0;
        }

        std::size_t SocketImpl::receiveFrom(SocketHandler handler, void* data, std::size_t length, IpAddress& from, Socket::Port& port)
        {
            if(handler != InvalidHandler && from.isValid() && port != Socket::AnyPort && data && length)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght addrLenght;

                std::size_t received = ::recvfrom(handler, static_cast<char*>(data), length, 0, reinterpret_cast<sockaddr*>(&addrBuffer), &addrLenght);

                from = IpAddressImpl::fromSockAddr(reinterpret_cast<sockaddr*>(&addrBuffer), port);

                return received;
            }

            return 0;
        }

        std::size_t SocketImpl::send(SocketHandler handler, const void* data, std::size_t length)
        {
            if(handler != InvalidHandler)
            {
                return ::send(handler, static_cast<const char*>(data), static_cast<int>(length), 0);
            }

            return 0;
        }

        std::size_t SocketImpl::sendTo(SocketHandler handler, const IpAddress& to, Socket::Port port, const void* data, std::size_t length)
        {
            if(handler != InvalidHandler && to.isValid() && port != Socket::AnyPort && data && length)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght addrLenght = IpAddressImpl::toSockAddr(to, port, &addrBuffer);

                return ::sendto(handler, static_cast<const char*>(data), length, 0, reinterpret_cast<const sockaddr*>(&addrBuffer), addrLenght);
            }

            return 0;
        }

        void SocketImpl::setBlocking(SocketHandler handler, bool blocking)
        {
            if(handler != InvalidHandler)
            {
                u_long block = blocking ? 0 : 1;
                ioctlsocket(handler, FIONBIO, &block);
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