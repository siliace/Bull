#include <Bull/Network/Socket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    /*! \brief Destructor
     *
     */
    Socket::~Socket()
    {
        close();
    }

    /*! \brief Close the socket
     *
     */
    void Socket::close()
    {
        if(m_handler != prv::SocketImpl::InvalidHandler)
        {
            prv::SocketImpl::close(m_handler);

            m_handler = prv::SocketImpl::InvalidHandler;
        }
    }

    /*! \brief Get the type of the Socket
     *
     * \return Return the type
     *
     */
    Socket::Type Socket::getType() const
    {
        return m_type;
    }

    /*! \brief Get the state of the socket
     *
     * \return Return the state
     *
     */
    Socket::State Socket::getState() const
    {
        return m_state;
    }

    /*! \brief
     *
     * \return
     *
     */
    NetProtocol Socket::getProtocol() const
    {
        return m_protocol;
    }

    /*! \brief Constructor
     *
     * \param type The type of Socket to create
     *
     */
    Socket::Socket(Type type) :
        m_handler(prv::SocketImpl::InvalidHandler),
        m_type(type)
    {
        /// Nothing
    }

    /*! \brief Create the socket handler
     *
     * \param protocol The used by the Socket to communicate
     *
     * \return Return true if the handler was created successfully, false otherwise
     *
     */
    bool Socket::create(NetProtocol protocol)
    {
        if(m_handler == prv::SocketImpl::InvalidHandler || m_protocol != protocol)
        {
            SocketHandler handler = prv::SocketImpl::create(protocol, m_type);

            if(handler == prv::SocketImpl::InvalidHandler)
            {
                return false;
            }

            m_protocol = protocol;
            create(handler);
        }

        return true;
    }

    void Socket::create(SocketHandler handler)
    {
        if(handler != prv::SocketImpl::InvalidHandler)
        {
            close();

            m_handler = handler;
        }
    }
}
