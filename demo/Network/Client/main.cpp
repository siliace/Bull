#include <Bull/Core/System/ConsoleOutput.hpp>

#include <Bull/Network/Socket/SocketPoller.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpSocketStream.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::ConsoleOutput cout;
    Bull::SocketPoller poller;

    if(!client.connect(Bull::IpAddressV4::Loopback, Bull::NetPort(6969)))
    {
        cout.writeLine("Failed to connect");

        return -1;
    }

    if(!poller.add(client, Bull::SocketPollerEvent_Read))
    {
        cout.writeLine("Failed to add client");

        return -1;
    }

    if(poller.wait())
    {
        if(poller.isReadyToRead(client))
        {
            std::size_t size;
            Bull::String message;
            message.setSize(256);

            if(client.receive(&message[0], message.getCapacity(), size))
            {
                message.setSize(size);

                cout.writeLine(message.getBuffer());

                return 0;
            }
        }
        else if(poller.isReadyToWrite(client))
        {
            cout.writeLine("Ready to write");
        }
        else
        {
            cout.writeLine("Can't read");
        }
    }
    else
    {
        cout.writeLine("Failed to wait");
    }

    return -1;
}