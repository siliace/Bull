#include <iostream>

#include <Bull/Network/Icmp.hpp>
#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    TcpSocket socket;

    std::cout << "Ping : " << Icmp::ping(IpAddress(216, 58, 213, 67)).asMilliseconds() << std::endl;

    if(socket.connect(IpAddress::LoopbackIpv4, 6969) != TcpSocket::Ready)
    {
        std::cout << "Failed to connect" << std::endl;
    }
    else
    {
        std::cout << "Connected" << std::endl;
    }

    socket.disconnect();

    return 0;
}