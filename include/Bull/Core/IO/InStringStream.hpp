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

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        std::size_t read(void* data, std::size_t size) override;

        /*! \brief
         *
         * \return
         *
         */
        bool isAtEof() const;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        std::size_t getSize() const override;
        
        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        std::size_t setCursor(std::size_t position) override;

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        std::size_t getCursor() const override;

        /*! \brief
         *
         * \return
         *
         */
        const String& getString() const;
        
    private:

        std::size_t   m_cursor;
        const String& m_string;
    };
}

#endif // BULL_CORE_IO_INSTRINGSTREAM_HPP
