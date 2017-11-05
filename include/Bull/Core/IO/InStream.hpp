#ifndef BULL_CORE_IO_INSTREAM_HPP
#define BULL_CORE_IO_INSTREAM_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Configuration/Integer.hpp>

namespace Bull
{
    struct BULL_CORE_API InStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~InStream();

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        virtual std::size_t read(void* data, std::size_t size) = 0;

        /*! \brief Get all the content of the stream
         *
         * \return Return the content of the stream
         *
         */
        String readAll();

        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        virtual std::size_t setCursor(std::size_t position) = 0;

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        virtual std::size_t getCursor() const = 0;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        virtual std::size_t getSize() const = 0;
    };
}

#endif // BULL_CORE_IO_INSTREAM_HPP
