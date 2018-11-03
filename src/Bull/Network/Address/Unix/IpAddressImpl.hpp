#ifndef BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP
#define BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Network/Address/NetProtocol.hpp>

namespace Bull
{
    namespace prv
    {
        struct IpAddressImpl
        {
            /*! \brief Resolve an IpAddress
             *
             * \param hostname The hostname to resolve
             * \param protocol The NetProtocol of the IpAddress to resolve
             * \param service  The service to use to resolve
             *
             * \return Bytes of the resolved IpAddress
             *
             */
            static ByteArray resolve(const String& hostname, NetProtocol protocol, const String& service = "http");
        };
    }
}

#endif // BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP
