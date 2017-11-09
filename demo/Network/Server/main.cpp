#include <iostream>

#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::TcpServer server;

    if(server.listen(Bull::NetPort(6969)))
    {
        if(server.accept(client))
        {
            std::size_t sent = 0;
            Bull::String hello = "Hello World";

            std::cout << "Client accepted" << std::endl;

            if(client.send(hello.getBuffer(), hello.getSize(), sent))
            {
                std::cout << sent << " bytes sent" << std::endl;

                return EXIT_SUCCESS;
            }
            else
            {
                std::cout << "Failed to send" << std::endl;
            }
        }
        else
        {
            std::cout << "Failed to accept" << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to listen" << std::endl;
    }

    return EXIT_FAILURE;
}