#ifndef BULL_CORE_IO_INSTRINGSTREAM_HPP
#define BULL_CORE_IO_INSTRINGSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API InStringStream : public InStream
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

        /*! \brief Skip bytes in the InStringStream
         *
         * \param length The number of bytes to skip
         *
         */
        void skip(std::size_t length) override;

        /*! \brief Get the size of the InStringStream
         *
         * \return The size of the InStringStream
         *
         */
        size_t getSize() const override;

        /*! \brief Tell whether the InStringStream is at its end
         *
         * An InStream is considered at its end when there is not left to read
         *
         * \return True if the InStringStream is at its end
         *
         */
        bool isAtEnd() const override;

    private:

        std::size_t   m_cursor;
        const String& m_string;
    };
}

#endif // BULL_CORE_IO_INSTRINGSTREAM_HPP
