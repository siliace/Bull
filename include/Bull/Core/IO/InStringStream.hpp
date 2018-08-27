#ifndef BULL_CORE_IO_INSTRINGSTREAM_HPP
#define BULL_CORE_IO_INSTRINGSTREAM_HPP

#include <Bull/Core/IO/CursorAwareInStream.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API InStringStream : public CursorAwareInStream
    {
    public:

        /*! \brief Constructor
         * 
         * \param string The String to parse
         * 
         */
        explicit InStringStream(const String& string);

        /*! \brief Read bytes from the String
         *
         * \param length The number of bytes to read
         *
         * \return Read bytes
         *
         */
        ByteArray read(std::size_t length) override;

        /*! \brief Get the size of the InStringStream
         *
         * \return The size of the InStringStream
         *
         */
        size_t getSize() const override;

        /*! \brief Set the reading position in the InStringStream
         *
         * \param position The position to seek to
         *
         * \return The actual position of the cursor
         *
         */
        std::size_t setCursor(std::size_t cursor) override;

        /*! \brief Get the position of the cursor in the InStringStream
         *
         * \return The position of the cursor in the InStringStream
         *
         */
        inline std::size_t getCursor() const override
        {
            return m_cursor;
        }

    private:

        std::size_t   m_cursor;
        const String& m_string;
    };
}

#endif // BULL_CORE_IO_INSTRINGSTREAM_HPP
