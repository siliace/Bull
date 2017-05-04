#ifndef BULL_OUTSTREAM_HPP
#define BULL_OUTSTREAM_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    struct BULL_CORE_API OutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~OutStream()
        {
            /// Nothing
        }

        /*! \brief Write data into a stream
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        virtual Uint64 write(const void* data, Uint64 size) = 0;

        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        virtual Uint64 setCursor(Uint64 position) = 0;

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        virtual Uint64 getCursor() const = 0;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        virtual Uint64 getSize() const = 0;
    };
}

#endif // BULL_OUTSTREAM_HPP
