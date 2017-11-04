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
            std::cout << "Client accepted" << std::endl;

            return EXIT_SUCCESS;
        }

        std::cout << "Failed to accept" << std::endl;
    }

    return EXIT_FAILURE;
}