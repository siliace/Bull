#ifndef BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP
#define BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP

#include <string>

#include <Bull/Network/Address/NetProtocol.hpp>

namespace Bull
{
    namespace prv
    {
        class IpAddressImpl
        {
        public:

            /** \brief Resolve an IpAddress
             *
             * \param hostname The hostname to resolve
             * \param protocol The NetProtocol of the IpAddress to resolve
             * \param service  The service to use to resolve
             *
             * \return Bytes of the resolved IpAddress
             *
             */
            static ByteArray resolve(const std::string& hostname, NetProtocol protocol, const std::string& service = "http");
        };
    }
}

#endif // BULL_NETWORK_ADDRESS_UNIX_IPADDRESSIMPL_HPP
