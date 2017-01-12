#include <Bull/Core/Log.hpp>

#include <Bull/Network/Win32/IpAddressImpl.hpp>
#include <Bull/Network/Win32/SocketImpl.hpp>
#include <Bull/Network/Win32/Wsa.hpp>

namespace Bull
{
    namespace prv
    {
        SocketHandler SocketImpl::accept(SocketHandler socket, IpAddress& clientAddress, Uint16& clientPort, Socket::Error* error)
        {
            sockaddr  clientSocketAddress;
            socklen_t bufferLength = sizeof(sockaddr);

            SocketHandler client = ::accept(socket, &clientSocketAddress, &bufferLength);

            if(client != InvalidHandler && bufferLength)
            {
                clientAddress = IpAddressImpl::fromSocketAddress(&clientSocketAddress, clientPort);

                if(error)
                {
                    (*error) = Socket::Error::Ok;
                }
            }

            return client;
        }

        SocketHandler SocketImpl::create(NetProtocol protocol, Socket::Type type)
        {
            SocketHandler handler = socket(netProtocolToAF(protocol), socketTypeToSock(type), 0);

            if(handler == InvalidHandler)
            {
                Log::get()->write("Failed to create socket (" + String::number(Wsa::getLastError()) + ")", Log::Level::Warning);
            }

            return handler;
        }

        Socket::State SocketImpl::connect(SocketHandler socket, const IpAddress& remote, Uint16 port, Socket::Error* error)
        {
            socklen_t bufferLenght;
            IpAddressImpl::SocketAddressBuffer buffer;

            bufferLenght = IpAddressImpl::toSocketAddress(remote, port, &buffer[0]);

            if(::connect(socket, reinterpret_cast<const sockaddr*>(&buffer), bufferLenght) == SOCKET_ERROR)
            {
                return Socket::State::NotConnected;
            }

            return Socket::State::Connected;
        }

        void SocketImpl::close(SocketHandler socket)
        {
            if(closesocket(socket) == SOCKET_ERROR)
            {
                Log::get()->write("Failed to close socket (" + String::number(Wsa::getLastError()) + ")", Log::Level::Warning);
            }
        }

        void SocketImpl::enableBlockingMode(SocketHandler socket, bool enable)
        {
            u_long blocking = enable ? 0 : 1;
            ioctlsocket(socket, FIONBIO, &blocking);
        }

        Socket::State SocketImpl::listen(SocketHandler socket, const IpAddress& address, Uint16 port, std::size_t queueLength, Socket::Error* error)
        {
            socklen_t bufferLenght;
            IpAddressImpl::SocketAddressBuffer buffer;

            bufferLenght = IpAddressImpl::toSocketAddress(address, port, &buffer[0]);

            if(::bind(socket, reinterpret_cast<const sockaddr*>(&buffer), bufferLenght) == SOCKET_ERROR)
            {
                return Socket::State::NotConnected;
            }

            if(::listen(socket, queueLength) == SOCKET_ERROR)
            {
                return Socket::State::NotConnected;
            }

            if(error)
            {
                (*error) = Socket::Error::Ok;
            }

            return Socket::State::Bound;
        }

        int SocketImpl::netProtocolToAF(NetProtocol protocol)
        {
            switch(protocol)
            {
                case NetProtocol::Ipv4: return AF_INET;
                case NetProtocol::Ipv6: return AF_INET6;
            }
        }

        Socket::State SocketImpl::receive(SocketHandler socket, void* buffer, std::size_t size, std::size_t* received, Socket::Error* error)
        {
            int written = recv(socket, buffer, size, 0);

            if(written)
            {

            }

            return Socket::State::NotConnected;
        }

        int SocketImpl::socketTypeToSock(Socket::Type type)
        {
            switch(type)
            {
                case Socket::Type::Tcp: return SOCK_STREAM;
                case Socket::Type::Udp: return SOCK_DGRAM;
                case Socket::Type::Raw: return SOCK_RAW;
            }
        }
    }
}
