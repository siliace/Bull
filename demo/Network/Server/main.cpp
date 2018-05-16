#include <Bull/Core/System/ConsoleOutput.hpp>

#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::TcpServer server;
    Bull::ConsoleOutput cout;

    if(server.listen(Bull::NetPort(6969)))
    {
        if(server.accept(client, Bull::Duration::seconds(5.f), Bull::Duration::milliseconds(20.f)))
        {
            std::size_t sent = 0;
            Bull::String hello = "Hello World";

            cout.writeLine("Client accepted");

            if(client.send(hello.getBuffer(), hello.getSize(), sent))
            {
                cout.writeLine(Bull::StringUtils::number(sent) + " bytes sent");

                return EXIT_SUCCESS;
            }
            else
            {
                cout.writeLine("Failed to send");
            }
        }
        else
        {
            cout.writeLine("Failed to accept");
        }
    }
    else
    {
        cout.writeLine("Failed to listen");
    }

    return EXIT_FAILURE;
}