#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/System/ConsoleOutput.hpp>

#include <Bull/Network/Socket/SocketPoller.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::ConsoleOutput cout;
    Bull::SocketPoller poller;
    Bull::TextWriter writer(cout);

    if(!client.connect(Bull::IpAddressV4::Loopback, Bull::NetPort(6969)))
    {
        writer.writeLine("Failed to connect");

        return -1;
    }

    if(!poller.add(client, Bull::SocketPollerEvent_Read))
    {
        writer.writeLine("Failed to add client");

        return -1;
    }

    if(poller.wait())
    {
        if(poller.isReadyToRead(client))
        {
            std::size_t size;
            Bull::String message;
            message.setSize(256);

            if(client.receive(&message[0], message.getSize(), size))
            {
                message.setSize(size);

                writer.writeLine(message.getBuffer());

                return 0;
            }
        }
        else if(poller.isReadyToWrite(client))
        {
            writer.writeLine("Ready to write");
        }
        else
        {
            writer.writeLine("Can't read");
        }
    }
    else
    {
        writer.writeLine("Failed to wait");
    }

    return -1;
}