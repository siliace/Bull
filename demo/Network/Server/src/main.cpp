#include <iostream>

#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

#include <Bull/System/Keyboard.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    TcpSocket client;
    TcpListener server;
    String message("Hello world");

    if(server.listen(6969) != Socket::Ready)
    {
        std::cout << "Failed to listen the port" << std::endl;

        return -1;
    }

    while(!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        Index sent = 0;

        if(client.send(message.getBuffer(), message.getSize(), sent) == Socket::Ready)
        {
            std::cout << sent << " bytes sent" << std::endl;
        }
        else
        {
            std::cout << "Waiting for client" << std::endl;

            if(server.accept(client, Time::seconds(1.f)) == Socket::Ready)
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