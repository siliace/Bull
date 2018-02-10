#ifndef BULL_CORE_IO_OUTSTREAM_HPP
#define BULL_CORE_IO_OUTSTREAM_HPP

#include <Bull/Core/Memory/String.hpp>

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
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        virtual std::size_t write(const void* data, std::size_t size) = 0;
    };
}

#endif // BULL_CORE_IO_OUTSTREAM_HPP
