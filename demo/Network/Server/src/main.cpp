#include <iostream>

#include <Bull/Core/Hardware/Keyboard.hpp>

#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    TcpSocket client;
    TcpListener server;
    String message("Hello world");

    if(server.listen(NetPort(6969)) != SocketState_Ready)
    {
        std::cout << "Failed to listen the port" << std::endl;

        return -1;
    }

    while(!Keyboard::isKeyPressed(KeyboardKey_Escape))
    {
        Index sent = 0;

        if(client.send(message.getBuffer(), message.getSize(), sent) == SocketState_Ready)
        {
            std::cout << sent << " bytes sent" << std::endl;
        }
        else
        {
            std::cout << "Waiting for client" << std::endl;

            if(server.accept(client, Time::seconds(1.f)) == SocketState_Ready)
            {
                std::cout << "Client found" << std::endl;
            }
            else
            {
                std::cout << "Accept timeout" << std::endl;
            }
        }
    }

    return 0;
}