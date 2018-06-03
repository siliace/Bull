#include <algorithm>
#include <cstring>

#include <Bull/Core/Memory/MemoryStream.hpp>

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
        close();
    }

    bool MemoryStream::open(const void* data, std::size_t length)
    {
        if(data && length)
        {
            m_data = static_cast<const unsigned char*>(data);
            m_size = length;

            return true;
        }

        return false;
    }

    bool MemoryStream::isOpen() const
    {
        return m_data != nullptr;
    }

    void MemoryStream::close()
    {
        m_data   = nullptr;
        m_size   = 0;
        m_cursor = 0;
    }

    std::size_t MemoryStream::read(void* data, std::size_t size)
    {
        if(m_data && m_size)
        {
            std::size_t count = std::min(size, m_size - m_cursor);
            std::memcpy(data, &m_data[m_cursor], count);
            m_cursor += count;

            return count;
        }

        return 0;
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