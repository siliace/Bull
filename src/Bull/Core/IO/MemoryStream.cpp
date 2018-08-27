#include <algorithm>
#include <cstring>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/IO/MemoryStream.hpp>

namespace Bull
{
    MemoryStream::MemoryStream() :
        m_data(nullptr),
        m_size(0),
        m_cursor(0)
    {
        /// Nothing
    }

    MemoryStream::MemoryStream(const void* data, std::size_t length)
    {
        open(data, length);
    }

    void MemoryStream::open(const void* data, std::size_t length)
    {
        Expect(data && length, Throw(InvalidParameter, "MemoryStream::open", "Invalid buffer"));

        m_data = static_cast<const unsigned char*>(data);
        m_size = length;
    }

    ByteArray MemoryStream::read(std::size_t length)
    {
        ByteArray bytes = ByteArray::memoryCopy(&m_data[m_cursor], std::min(length, m_size - m_cursor));

        m_cursor += length;

        return bytes;
    }

    void MemoryStream::skip(std::size_t length)
    {
        m_cursor += length;
    }

    bool MemoryStream::isOpen() const
    {
        return m_data != nullptr;
    }

    bool MemoryStream::isAtEnd() const
    {
        return m_cursor >= m_size;
    }

    void MemoryStream::close()
    {
        m_data   = nullptr;
        m_size   = 0;
        m_cursor = 0;
    }

    std::size_t MemoryStream::setCursor(std::size_t position)
    {
        return m_cursor = std::min(position, m_size);
    }

    std::size_t MemoryStream::getCursor() const
    {
        return m_cursor;
    }

    std::size_t MemoryStream::getSize() const
    {
        return m_size;
    }
}