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

    MemoryStream::MemoryStream(const void* data, Index length)
    {
        open(data, length);
    }

    MemoryStream::~MemoryStream()
    {
        close();
    }

    bool MemoryStream::open(const void* data, Index length)
    {
        if(data && length)
        {
            m_data = data;
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

    Uint64 MemoryStream::read(void* data, Uint64 size)
    {
        if(m_data && m_size)
        {
            Uint64 count = std::min(static_cast<Index>(size), m_size - m_cursor);
            std::memcpy(data, &reinterpret_cast<const unsigned char*>(m_data)[m_cursor], static_cast<Index>(count));
            m_cursor += count;

            return count;
        }

        return 0;
    }

    Uint64 MemoryStream::setCursor(Uint64 position)
    {
        return m_cursor = std::min(static_cast<Index>(position), m_size);
    }

    Uint64 MemoryStream::getCursor() const
    {
        return m_cursor;
    }

    Uint64 MemoryStream::getSize() const
    {
        return m_size;
    }

    MemoryStream::operator bool() const
    {
        return isOpen();
    }
}