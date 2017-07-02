#include <iostream>

#include <Bull/Hardware/Keyboard.hpp>

#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    TcpSocket client;
    TcpListener server;
    String message("Hello world");

    server.listen(6969);

    while(!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        if(client.isConnected())
        {
            client.send(message.getBuffer(), message.getSize());
        }
        else
        {
            std::cout << "Waiting for client" << std::endl;

            if(server.accept(client) == Socket::Ready)
            {
                std::cout << "Client found" << std::endl;
            }
        }
    }

    return 0;
}