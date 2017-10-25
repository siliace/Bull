#include <iostream>

#include <Bull/Network/Icmp.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    String buffer;
    TcpSocket socket;
    bool connected = false;

    buffer.reserve(512);

    if(socket.connect(IpAddress::LoopbackIpv4, 6969) != SocketState_Ready)
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
        Index received = 0;

        if(socket.receive(&buffer[0], buffer.getCapacity(), received) == SocketState_Ready)
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