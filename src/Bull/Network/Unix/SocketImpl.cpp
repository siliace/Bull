#include <Bull/Core/Log.hpp>

#include <Bull/Network/Unix/IpAddressImpl.hpp>
#include <Bull/Network/Unix/SocketImpl.hpp>

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
                Log::get()->write("Failed to create socket", Log::Level::Warning);
            }

            return handler;
        }

        Socket::State SocketImpl::connect(SocketHandler socket, const IpAddress& remote, Uint16 port, Socket::Error* error)
        {
            socklen_t bufferLenght;
            IpAddressImpl::SocketAddressBuffer buffer;

            bufferLenght = IpAddressImpl::toSocketAddress(remote, port, &buffer[0]);

            if(::connect(socket, reinterpret_cast<const sockaddr*>(&buffer), bufferLenght) == -1)
            {
                return Socket::State::NotConnected;
            }

            return Socket::State::Connected;
        }

        void SocketImpl::close(SocketHandler socket)
        {
            close(socket);
        }

        void SocketImpl::enableBlockingMode(SocketHandler socket, bool enable)
        {
            u_long blocking = enable ? 0 : 1;
            fcntl(socket, O_NONBLOCK, &blocking);
        }

        Socket::State SocketImpl::listen(SocketHandler socket, const IpAddress& address, Uint16 port, std::size_t queueLength, Socket::Error* error)
        {
            socklen_t bufferLenght;
            IpAddressImpl::SocketAddressBuffer buffer;

            bufferLenght = IpAddressImpl::toSocketAddress(address, port, &buffer[0]);

            if(::bind(socket, reinterpret_cast<const sockaddr*>(&buffer), bufferLenght) == -1)
            {
                return Socket::State::NotConnected;
            }

            if(::listen(socket, queueLength) == -1)
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

            return 0;
        }

        Socket::State SocketImpl::receive(SocketHandler socket, void* buffer, std::size_t size, std::size_t* received, Socket::Error* error)
        {
            return Socket::State::Connected;
        }

        int SocketImpl::socketTypeToSock(Socket::Type type)
        {
            switch(type)
            {
                case Socket::Type::Tcp: return SOCK_STREAM;
                case Socket::Type::Udp: return SOCK_DGRAM;
                case Socket::Type::Raw: return SOCK_RAW;
            }

            return 0;
        }
    }
}
