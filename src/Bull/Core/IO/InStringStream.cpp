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

    std::size_t InStringStream::read(void* data, std::size_t size)
    {
        std::size_t toRead;

        if(m_cursor + size > getSize())
        {
            toRead = getSize() - m_cursor;
        }
        else
        {
            toRead = size;
        }

        std::memcpy(data, &m_string[m_cursor], toRead);

        m_cursor += toRead;

        return toRead;
    }

    std::size_t InStringStream::getSize() const
    {
        return m_string.getSize();
    }

    std::size_t InStringStream::setCursor(std::size_t position)
    {
        m_cursor = std::min(position, getSize());

        return m_cursor;
    }

    std::size_t InStringStream::getCursor() const
    {
        return m_cursor;
    }
}