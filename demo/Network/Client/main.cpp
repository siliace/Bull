#include <Bull/Network/Socket/TcpClient.hpp>

int main()
{
    Bull::TcpClient client;

    if(client.connect(Bull::IpAddress::Loopback, Bull::NetPort(6969)))
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}