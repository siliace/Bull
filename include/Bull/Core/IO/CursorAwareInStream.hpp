#ifndef BULL_CORE_IO_CursorAwareINSTREAM_HPP
#define BULL_CORE_IO_CursorAwareINSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    struct BULL_CORE_API CursorAwareInStream : public InStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~CursorAwareInStream();

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

        /*! \brief Tell whether the CursorAwareInStream is at its end
         *
         * An InStream is considered at its end when there is not left to read
         *
         * \return True if the CursorAwareInStream is at its end
         *
         */
        bool isAtEnd() const override;
    };
}

#endif // BULL_CORE_IO_CursorAwareINSTREAM_HPP
