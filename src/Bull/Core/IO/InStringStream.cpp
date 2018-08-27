#include <cstring>

#include <Bull/Core/IO/InStringStream.hpp>

namespace Bull
{
    InStringStream::InStringStream(const String& string) :
        m_cursor(0),
        m_string(string)
    {
        /// Nothing
    }

    ByteArray InStringStream::read(std::size_t length)
    {
        std::size_t toRead = std::min(m_cursor + length, getSize());

        ByteArray bytes = ByteArray::memoryCopy(&m_string[m_cursor], toRead);

        m_cursor += toRead;

        return bytes;
    }

    size_t InStringStream::getSize() const
    {
        return m_string.getSize();
    }

    std::size_t InStringStream::setCursor(std::size_t cursor)
    {
        m_cursor = std::min(cursor, getSize());

        return m_cursor;
    }
}