#include <iostream>

#include <Bull/Network/Socket/TcpClient.hpp>

int main()
{
    Bull::TcpClient client;

    if(client.connect(Bull::IpAddressV4::Loopback, Bull::NetPort(6969)))
    {
        std::size_t received;
        Bull::String message(256, 256);

        if(client.receive(&message[0], message.getCapacity(), received))
        {
            message.setSize(received);

            std::cout << received << " bytes received" << std::endl;
            std::cout << message.getBuffer() << std::endl;

            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}