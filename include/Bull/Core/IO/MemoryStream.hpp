#ifndef BULL_MEMORYSTREAM_HPP
#define BULL_MEMORYSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    class BULL_API MemoryStream : public InStream
    {
    public:

        /*! @brief Default contructor
         *
         */
        MemoryStream();

        /*! @brief Constructor
         *
         * @param data   Data to stream
         * @param length The length of data
         *
         */
        MemoryStream(const void* data, std::size_t length);

        /*! @brief Destructor
         *
         */
        ~MemoryStream();

        /*! @brief Open a stream
         *
         * @param data   Data to stream
         * @param length The length of data
         *
         * @return True if the stream was opened successfully
         *
         */
        bool open(const void* data, std::size_t length);

        /*! @brief Check if the stream is open
         *
         * @return True is the stream is open
         *
         */
        bool isOpen() const;

        /*! @brief Close the stream
         *
         */
        void close();

        /*! @brief Read data from a stream
         *
         * @param data A pointer to the memory area to fill
         * @param size The size of the memory area to fill
         *
         * @return Return the number of read bytes
         *
         */
        Uint64 read(void* data, Uint64 size) override;

        /*! @brief Set the reading position in the stream
         *
         * @param position The position to seek to
         *
         * @return Return the actual position
         *
         */
        Uint64 setCursor(Uint64 position) override;

        /*! @brief Get the reading position in the stream
         *
         * @return Return the current position
         *
         */
        Uint64 getCursor() const override;

        /*! @brief Get the size of the stream
         *
         * @return Return the size of the stream
         *
         */
        Uint64 getSize() const override;

        /*! @brief Check if the stream is open
         *
         * @return True is the stream is open
         *
         */
        operator bool() const;

    private:

        const void* m_data;   /*!< Data to stream */
        std::size_t m_size;   /*!< Size of data to stream */
        std::size_t m_cursor; /*!< The internal cursor */
    };
}

#endif //BULL_MEMORYSTREAM_HPP
