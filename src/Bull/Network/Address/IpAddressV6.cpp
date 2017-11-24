#include <Bull/Core/IO/OutStringStream.hpp>

#include <Bull/Network/Address/IpAddressImpl.hpp>
#include <Bull/Network/Address/IpAddressV6.hpp>

namespace Bull
{
    IpAddressV6::IpAddressV6() :
        IpAddress(16, false)
    {
        /// Nothing
    }

    String IpAddressV6::toString() const
    {
        OutStringStream ss;

        for(std::size_t i = 0; i < getByteCount(); i++)
        {
            ss << at(i);

            if(i < getByteCount() - 1)
            {
                ss << ':';
            }
        }

        return ss.toString();
    }

    NetProtocol IpAddressV6::getProtocol() const
    {
        return NetProtocol_Ipv6;
    }
}