#include <iostream>

#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::TcpServer server;

    if(server.listen(Bull::NetPort(6969)))
    {
        while(!server.accept(client, Bull::Time::seconds(1.f)))
        {
            std::cout << "Failed to accept" << std::endl;
        }

        std::cout << "Client accepted" << std::endl;
    }

    return EXIT_FAILURE;
}