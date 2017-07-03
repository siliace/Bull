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

        SocketHandler SocketImpl::create(NetProtocol protocol, Socket::Type type)
        {
            return socket(translateProtocol(protocol), translateSocketType(type), 0);
        }

        bool SocketImpl::listen(SocketHandler handler, unsigned int limit)
        {
            if(handler != InvalidHandler)
            {
                return ::listen(handler, limit) != SOCKET_ERROR;
            }

            return false;
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

        int SocketImpl::translateProtocol(NetProtocol protocol)
        {
            switch(protocol)
            {
                case NetProtocol_Any:     return -1;
                case NetProtocol_IpV4:    return AF_INET;
                case NetProtocol_IpV6:    return AF_INET6;
                case NetProtocol_Unknown: return AF_UNSPEC;
            }

            return -1;
        }
    }
}