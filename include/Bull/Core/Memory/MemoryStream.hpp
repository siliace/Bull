#ifndef BULL_CORE_MEMORY_MEMORYSTREAM_HPP
#define BULL_CORE_MEMORY_MEMORYSTREAM_HPP

#include <Bull/Core/IO/CursorAwareInStream.hpp>

namespace Bull
{
    class BULL_CORE_API MemoryStream : public CursorAwareInStream
    {
    public:

        /*! \brief Default contructor
         *
         */
        MemoryStream();

        /*! \brief Constructor
         *
         * \param data   Data to stream
         * \param length The length of data
         *
         */
        MemoryStream(const void* data, std::size_t length);

        /*! \brief Destructor
         *
         */
        ~MemoryStream();

        /*! \brief Open a stream
         *
         * \param data   Data to stream
         * \param length The length of data
         *
         * \return True if the stream was opened successfully
         *
         */
        bool open(const void* data, std::size_t length);

        /*! \brief Check if the stream is open
         *
         * \return True is the stream is open
         *
         */
        bool isOpen() const;

        /*! \brief Close the stream
         *
         */
        void close();

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        std::size_t read(void* data, std::size_t size) override;

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

        /*! \brief Check if the stream is open
         *
         * \return True is the stream is open
         *
         */
        operator bool() const;

    private:

        const void* m_data;   /*!< Data to stream */
        std::size_t       m_size;   /*!< Size of data to stream */
        std::size_t       m_cursor; /*!< The internal cursor */
    };
}

#endif //BULL_CORE_MEMORY_MEMORYSTREAM_HPP
