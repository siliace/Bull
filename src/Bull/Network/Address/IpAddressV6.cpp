#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/IO/TextWriter.hpp>

#include <Bull/Network/Address/IpAddressImpl.hpp>
#include <Bull/Network/Address/IpAddressV6.hpp>

namespace Bull
{
    IpAddressV6::IpAddressV6() :
        IpAddress(16, false)
    {
        /// Nothing
    }

    IpAddressV6::IpAddressV6(const ByteArray& bytes) :
        IpAddress(16, true)
    {
        Expect(bytes.getCapacity() == 16, Throw(InvalidParameter, "Invalid buffer size"));

        m_bytes = bytes;
    }

    String IpAddressV6::toString() const
    {
        OutStringStream oss;
        TextWriter textWriter(oss);

        for(std::size_t i = 0; i < getByteCount(); i++)
        {
            textWriter << at(i);

            if(i < getByteCount() - 1)
            {
                textWriter << ':';
            }
        }

        return oss.toString();
    }

    NetProtocol IpAddressV6::getProtocol() const
    {
        return NetProtocol_Ipv6;
    }
}