#ifndef BULL_NETWORK_NETPORT_HPP
#define BULL_NETWORK_NETPORT_HPP

namespace Bull
{
    enum NetPort : unsigned short
    {
        NetPort_Any        = 0,   /*!< Any network port */
        NetPort_Wol        = 9,   /*!< The Wake On Lan port*/
        NetPort_FtpData    = 20,  /*!< The FTP data port */
        NetPort_FtpControl = 21,  /*!< The FTP control port */
        NetPort_Ssh        = 22,  /*!< The SSH port */
        NetPort_Telnet     = 23,  /*!< The Telnet port*/
        NetPort_Smtp       = 25,  /*!< The SMTP port */
        NetPort_Dns        = 53,  /*!< The DNS port */
        NetPort_Http       = 80,  /*!< The HTTP port */
        NetPort_Pop        = 110, /*!< The POP port */
        NetPort_Ntp        = 123, /*!< The NTP port */
        NetPort_Imap       = 143, /*!< The IMAP port */
        NetPort_Https      = 443, /*!< The HTTPS port */
    };

    /*! \brief Tell whether a NetPort is well known
     *
     * \param port The NetPort
     *
     * \return True if the port is well known
     *
     */
    inline bool isWellKnownPort(NetPort port)
    {
        return port <= 1023;
    }

    /*! \brief Tell whether a NetPort is registered
     *
     * \param port The NetPort
     *
     * \return True if the port is registered
     *
     */
    inline bool isRegisteredPort(NetPort port)
    {
        return port >= 1024 && port <= 49151;
    }

    /*! \brief Tell whether a NetPort is dynamic
     *
     * \param port The NetPort
     *
     * \return True if the port is dynamic
     *
     */
    inline bool isDynamicPort(NetPort port)
    {
        return port >= 49152;
    }

}

#endif // BULL_NETWORK_NETPORT_HPP
