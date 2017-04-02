#include <cstring>

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

    MemoryStream::~MemoryStream()
    {
        m_data   = nullptr;
        m_size   = 0;
        m_cursor = 0;
    }

    bool MemoryStream::open(const void* data, std::size_t length)
    {
        if(data && length)
        {
            m_data = data;
            m_size = length;

            return true;
        }

        return false;
    }

    Uint64 MemoryStream::read(void* data, Uint64 size)
    {
        if(m_data && m_size)
        {
            Uint64 count = std::min(size, m_size - m_cursor);
            std::memcpy(data, m_data + m_cursor, static_cast<std::size_t>(count));
            m_cursor += count;

            return count;
        }

        return 0;
    }

    Uint64 MemoryStream::setCursor(Uint64 position)
    {
        return m_cursor = std::min(position, m_size);
    }

    Uint64 MemoryStream::getCursor() const
    {
        return m_cursor;
    }

    Uint64 MemoryStream::getSize() const
    {
        return m_size;
    }
}