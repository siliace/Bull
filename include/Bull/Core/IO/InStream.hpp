#ifndef BULL_CORE_IO_INSTREAM_HPP
#define BULL_CORE_IO_INSTREAM_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API InStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~InStream();

        /*! \brief Get all the content of the stream
         *
         * \return Return the content of the stream
         *
         */
        String readAll();

        /*! \brief Read a line from the InStream
         *
         * \param line      The String to fill with the line
         * \param separator The character that delimit two lines
         *
         * \return True if a line could be read
         *
         */
        bool readLine(String& line, char separator = '\n');

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        virtual std::size_t read(void* data, std::size_t size) = 0;

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
