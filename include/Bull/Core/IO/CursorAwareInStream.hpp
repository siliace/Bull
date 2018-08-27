#ifndef BULL_CORE_IO_CURSORAWAREINSTREAM_HPP
#define BULL_CORE_IO_CURSORAWAREINSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    struct BULL_CORE_API CursorAwareInStream : public InStream
    {
        /*! \brief Skip bytes in the CursorAwareInStream
         *
         * \param length The number of bytes to skip
         *
         */
        void skip(std::size_t length) override;

        /*! \brief Tell whether the CursorAwareInStream is at its end
         *
         * An CursorAwareInStream is considered at its end when there is not left to read
         *
         * \return True if the CursorAwareInStream is at its end
         *
         */
        bool isAtEnd() const override;

        /*! \brief Set the reading position in the CursorAwareInStream
         *
         * \param position The position to seek to
         *
         * \return The actual position of the cursor
         *
         */
        virtual std::size_t setCursor(std::size_t cursor) = 0;

        /*! \brief Get the position of the cursor in the CursorAwareInStream
         *
         * \return The position of the cursor in the CursorAwareInStream
         *
         */
        virtual std::size_t getCursor() const = 0;
    };
}

#endif // BULL_CORE_IO_CURSORAWAREINSTREAM_HPP
