#ifndef BULL_CORE_IO_INSTREAM_HPP
#define BULL_CORE_IO_INSTREAM_HPP

#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    struct BULL_CORE_API InStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~InStream();

        /*! \brief Read bytes from the InStream
         *
         * \param length The length of data to read
         *
         * \return Read bytes
         *
         */
        virtual ByteArray read(std::size_t length) = 0;

        /*! \brief Skip bytes in the InStream
         *
         * \param length The number of bytes to skip
         *
         */
        virtual void skip(std::size_t length) = 0;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        virtual std::size_t getSize() const = 0;

        /*! \brief Tell whether the InStream is at its end
         *
         * An InStream is considered at its end when there is not left to read
         *
         * \return True if the InStream is at its end
         *
         */
        virtual bool isAtEnd() const = 0;

        /*! \brief Cast the InStream to a bool
         *
         * \return True if the InStream is not at its end
         *
         * \see isAtEnd
         *
         */
        operator bool() const;
    };
}

#endif // BULL_CORE_IO_INSTREAM_HPP
