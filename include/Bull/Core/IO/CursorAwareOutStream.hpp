#ifndef BULL_CORE_IO_CursorAwareOUTSTREAM_HPP
#define BULL_CORE_IO_CursorAwareOUTSTREAM_HPP

#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    struct BULL_CORE_API CursorAwareOutStream : public OutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~CursorAwareOutStream();

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
    };
}

#endif // BULL_CORE_IO_CursorAwareOUTSTREAM_HPP
