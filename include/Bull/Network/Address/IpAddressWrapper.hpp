#ifndef BULL_NETWORK_ADDRESS_IPADDRESSWRAPPER_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSWRAPPER_HPP

#include <Bull/Network/Address/IpAddressV4.hpp>
#include <Bull/Network/Address/IpAddressV6.hpp>
#include <Bull/Network/Address/NetProtocol.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddressWrapper
    {
    public:

        /*! \brief Default constructor
         *
         */
        IpAddressWrapper();

        /*! \brief Constructor
         *
         * \param address The IpAddressV4 to wrap
         *
         */
        IpAddressWrapper(const IpAddressV4& address);

        /*! \brief Constructor
         *
         * \param address The IpAddressV6 to wrap
         *
         */
        IpAddressWrapper(const IpAddressV6& address);

        /*! \brief Copy constructor
         *
         * \param copy The IpAddressWrapper to copy
         *
         */
        IpAddressWrapper(const IpAddressWrapper& copy);

        /*! \brief Basic assignment operator
         *
         * \param copy The IpAddressWrapper to copy
         *
         * \return This
         *
         */
        IpAddressWrapper& operator=(const IpAddressWrapper& copy);

        /*! \brief Constructor by movement semantic
         *
         * \param right The IpAddressWrapper to move
         *
         */
        IpAddressWrapper(IpAddressWrapper&& right) noexcept;

        /*! \brief Basic assignment by movement semantic
         *
         * \param right The IpAddressWrapper to move
         *
         * \return This
         *
         */
        IpAddressWrapper& operator=(IpAddressWrapper&& right) noexcept;

        /*! \brief Tell whether the wrapped IpAddress is valid
         *
         * \return True if the IpAddress is valid
         *
         */
        bool isValid() const;

        /*! \brief Get the NetProtocol used by the wrapped IpAddress
         *
         * \return The NetProtocol
         *
         */
        NetProtocol getProtocol() const;

        /*! \brief Get the handled AbstractIpAddress
         *
         * \return
         */
        const IpAddress& getAddress() const;

    private:

        struct Wrapper
        {
            IpAddressV4 v4;
            IpAddressV6 v6;
        };

        Wrapper     m_wrapper;
        NetProtocol m_protocol;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESSWRAPPER_HPP
