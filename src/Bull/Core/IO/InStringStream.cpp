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
        ByteArray bytes = ByteArray::memoryCopy(&m_string[m_cursor], length);

        m_cursor += length;

        return bytes;
    }

    void InStringStream::skip(std::size_t length)
    {
        m_cursor += length;
    }

    size_t InStringStream::getSize() const
    {
        return m_string.getSize();
    }

    bool InStringStream::isAtEnd() const
    {
        return m_cursor >= getSize();
    }
}