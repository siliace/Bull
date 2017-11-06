#include <iostream>

#include <Bull/Network/Socket/SocketPoller.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpSocketStream.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::SocketPoller poller;

    if(!client.connect(Bull::IpAddressV4::Loopback, Bull::NetPort(6969)))
    {
        std::cout << "Failed to connect" << std::endl;

        return EXIT_FAILURE;
    }

    if(!poller.add(client))
    {
        std::cout << "Failed to add client" << std::endl;

        return EXIT_FAILURE;
    }

    if(poller.wait())
    {
        if(poller.isReadyToRead(client))
        {
            std::size_t size;
            Bull::String message(256, 256);

            if(client.receive(&message[0], message.getCapacity(), size))
            {
                message.setSize(size);

                std::cout << message.getBuffer() << std::endl;

                return EXIT_SUCCESS;
            }
        }
        else
        {
            std::cout << "Can't read" << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to wait" << std::endl;
    }

    return EXIT_FAILURE;
}