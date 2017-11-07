#ifndef BULL_NETWORK_ADDRESS_WIN32_IPADDRESSIMPL_HPP
#define BULL_NETWORK_ADDRESS_WIN32_IPADDRESSIMPL_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
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
             * \param bytes    Bytes of the IpAddress
             * \param service  The service to use to resolve
             *
             * \return True if the IpAddress was resolved successfully
             *
             *
             */
            static bool resolve(const String& hostname, NetProtocol protocol, ByteArray& bytes, const String& service = "http");
        };
    }
}

#endif // BULL_NETWORK_ADDRESS_WIN32_IPADDRESSIMPL_HPP
