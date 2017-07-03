#include <iostream>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    TcpSocket socket;

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