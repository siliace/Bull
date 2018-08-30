#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/System/ConsoleOutput.hpp>

#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

int main()
{
    Bull::TcpClient client;
    Bull::TcpServer server;
    Bull::ConsoleOutput cout;
    Bull::TextWriter writer(cout);

    server.listen(Bull::NetPort(6969));

    client = server.accept();

    std::size_t sent = 0;
    Bull::String hello = "Hello World";

    writer.writeLine("Client accepted: " + client.getRemoteAddress().toString());

    sent = client.send(hello.getBuffer(), hello.getSize());

    writer.writeLine(Bull::StringUtils::number(sent) + " bytes sent");

    return 0;
}