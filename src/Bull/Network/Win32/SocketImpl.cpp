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

        SocketHandler SocketImpl::accept(SocketHandler handler, IpAddress& ip, NetPort& port)
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

        bool SocketImpl::bind(SocketHandler handler, const IpAddress& address, NetPort port)
        {
            if(handler != InvalidHandler && address.isValid() && port != NetPort_Any)
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

        bool SocketImpl::connect(SocketHandler handler, const IpAddress& address, NetPort port)
        {
            if(handler != InvalidHandler && address.isValid() && port != NetPort_Any)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght length = IpAddressImpl::toSockAddr(address, port, &addrBuffer);

                return ::connect(handler, reinterpret_cast<sockaddr*>(&addrBuffer), length) != SOCKET_ERROR;
            }

            return false;
        }

        SocketHandler SocketImpl::create(NetProtocol protocol, SocketType type)
        {
            return socket(translateProtocol(protocol), translateSocketType(type), 0);
        }

        SocketState SocketImpl::lastError()
        {
            switch(WSAGetLastError())
            {
                case WSAEWOULDBLOCK:   return SocketState_NotReady;
                case WSAEALREADY:      return SocketState_NotReady;
                case WSAECONNABORTED:  return SocketState_Disconnected;
                case WSAECONNRESET:    return SocketState_Disconnected;
                case WSAETIMEDOUT:     return SocketState_Disconnected;
                case WSAENETRESET:     return SocketState_Disconnected;
                case WSAENOTCONN:      return SocketState_Disconnected;
                case WSAEISCONN:       return SocketState_Ready;
                case WSAEADDRNOTAVAIL: return SocketState_ConnectionRefused;
                default:               return SocketState_Error;
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

        Index SocketImpl::receive(SocketHandler handler, void* data, Index length)
        {
            if(handler != InvalidHandler && data && length)
            {
                return ::recv(handler, static_cast<char*>(data), length, 0);
            }

            return 0;
        }

        Index SocketImpl::receiveFrom(SocketHandler handler, void* data, Index length, IpAddress& from, NetPort& port)
        {
            if(handler != InvalidHandler && from.isValid() && port != NetPort_Any && data && length)
            {
                IpAddressImpl::SockAddrBuffer addrBuffer;
                IpAddressImpl::SockAddrLenght addrLenght;

                Index received = ::recvfrom(handler, static_cast<char*>(data), length, 0, reinterpret_cast<sockaddr*>(&addrBuffer), &addrLenght);

                from = IpAddressImpl::fromSockAddr(reinterpret_cast<sockaddr*>(&addrBuffer), port);

                return received;
            }

            return 0;
        }

        Index SocketImpl::send(SocketHandler handler, const void* data, Index length)
        {
            if(handler != InvalidHandler)
            {
                return ::send(handler, static_cast<const char*>(data), static_cast<int>(length), 0);
            }

            return 0;
        }

        Index SocketImpl::sendTo(SocketHandler handler, const void* data, Index length, const IpAddress& to, NetPort port)
        {
            if(handler != InvalidHandler && to.isValid() && port != NetPort_Any && data && length)
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

        int SocketImpl::translateSocketType(SocketType type)
        {
            switch(type)
            {
                case SocketType_Tcp: return SOCK_STREAM;
                case SocketType_Udp: return SOCK_DGRAM;
                case SocketType_Raw: return SOCK_RAW;
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