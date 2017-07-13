#include <iostream>

#include <Bull/Network/Icmp.hpp>
#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    String buffer;
    TcpSocket socket;
    bool connected = false;

    buffer.reserve(512);

    std::cout << "Ping : " << Icmp::ping(IpAddress(216, 58, 213, 67)).asMilliseconds() << std::endl;

    if(socket.connect(IpAddress::LoopbackIpv4, 6969) != TcpSocket::Ready)
    {
        std::cout << "Failed to connect" << std::endl;
    }
    else
    {
        std::cout << "Connected" << std::endl;

        connected = true;
    }

    while(connected)
    {
        std::size_t received = 0;

        if(socket.receive(&buffer[0], buffer.getCapacity(), received) == Socket::Ready)
        {
            std::cout << received << " bytes" << std::endl;
            std::cout << "Message: " << buffer.getBuffer() << std::endl;
        }
        else
        {
            connected = false;
        }
    }

    socket.disconnect();

    return 0;
}