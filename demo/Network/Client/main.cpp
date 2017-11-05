#include <iostream>

#include <Bull/Network/Icmp/Icmp.hpp>

int main()
{
    Bull::Time ping = Bull::Icmp::ping(Bull::IpAddressV4::Loopback, Bull::Time::seconds(1.f));

    std::cout << ping.asSeconds() << std::endl;

    return 0;
}