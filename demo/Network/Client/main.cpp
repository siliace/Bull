#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/System/ConsoleOutput.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

#include <Bull/Network/Address/IpAddressV4.hpp>
#include <Bull/Network/Socket/SocketPoller.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::ConsoleOutput cout;
    Bull::SocketPoller poller;
    Bull::TextWriter writer(cout);

    client.connect(Bull::IpAddressV4::Loopback, Bull::NetPort(6969));

    poller.add(client, Bull::SocketPollerEvent_Read);

    if(poller.wait())
    {
        if(poller.isReadyToRead(client))
        {
            Bull::String message = Bull::StringUtils::ofSize(255);
            std::size_t size = client.receive(&message[0], message.getSize());

            message.setSize(size);

            writer.writeLine(message.getBuffer());

            return 0;

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