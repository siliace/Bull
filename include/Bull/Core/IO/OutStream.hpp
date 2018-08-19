#ifndef BULL_CORE_IO_OUTSTREAM_HPP
#define BULL_CORE_IO_OUTSTREAM_HPP

#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    struct BULL_CORE_API OutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~OutStream();

        /*! \brief Write data into a stream
         *
         * \param bytes Bytes to write
         *
         * \return Return the number of bytes written
         *
         */
        virtual std::size_t write(const ByteArray& bytes) = 0;

        /*! \brief Flush the OutStream
         *
         */
        virtual void flush() = 0;
    };
}

#endif // BULL_CORE_IO_OUTSTREAM_HPP
