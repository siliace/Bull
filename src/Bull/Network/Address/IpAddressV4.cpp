#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/Address/IpAddressImpl.hpp>
#include <Bull/Network/Address/IpAddressV4.hpp>

namespace Bull
{
    IpAddressV4 IpAddressV4::Any = IpAddressV4(0, 0, 0, 0);
    IpAddressV4 IpAddressV4::None;
    IpAddressV4 IpAddressV4::Loopback = IpAddressV4(127, 0, 0, 1);
    IpAddressV4 IpAddressV4::Broadcast = IpAddressV4(255, 255, 255, 255);

    IpAddressV4::IpAddressV4() :
        IpAddress(4, false)
    {
        /// Nothing
    }

    IpAddressV4::IpAddressV4(Uint32 address) :
        IpAddress(4)
    {
        /// Todo
    }

    IpAddressV4::IpAddressV4(Uint8 a, Uint8 b, Uint8 c, Uint8 d) :
        IpAddress(4)
    {
        at(0) = a;
        at(1) = b;
        at(2) = c;
        at(3) = d;
    }

    Uint32 IpAddressV4::toInt() const
    {
        return (at(0) << 24) | (at(1) << 16) | (at(2) << 8) | at(3);
    }

    String IpAddressV4::toString() const
    {
        StringStream ss;

        for(std::size_t i = 0; i < m_bytes.getCapacity(); i++)
        {
            ss << at(i);

            if(i < 3)
            {
                ss << '.';
            }
        }

        return ss.toString();
    }

    NetProtocol IpAddressV4::getProtocol() const
    {
        return NetProtocol_Ipv4;
    }
}