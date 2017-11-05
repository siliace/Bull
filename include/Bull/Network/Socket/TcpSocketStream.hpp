#ifndef BULL_NETWORK_SOCKET_TCPSOCKETSTREAM_HPP
#define BULL_NETWORK_SOCKET_TCPSOCKETSTREAM_HPP

#include <Bull/Core/IO/InOutStream.hpp>

#include <Bull/Network/Socket/TcpClient.hpp>

namespace Bull
{
    class BULL_NETWORK_API TcpSocketStream : public InOutStream
    {
    public:

        /*! \brief Constructor
         *
         * \param client The TcpClient to read and write
         * 
         */
        explicit TcpSocketStream(TcpClient& client);

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        std::size_t read(void* data, std::size_t size) override;

        /*! \brief Write data into a stream
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        std::size_t write(const void* data, std::size_t size) override;
        
        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        std::size_t setCursor(std::size_t position) override;

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        std::size_t getCursor() const override;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        std::size_t getSize() const override;

    private:

        TcpClient& m_client;
    };
}

#endif // BULL_NETWORK_SOCKET_TCPSOCKETSTREAM_HPP
