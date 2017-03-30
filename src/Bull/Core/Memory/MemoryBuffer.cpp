#include <Bull/Core/Memory/MemoryBuffer.hpp>

namespace Bull
{
    MemoryBuffer::SharedHandlerType& MemoryBuffer::getEmptyHandler()
    {
        static SharedHandlerType handler = std::make_shared<HandlerType>();

        return handler;
    }

    MemoryBuffer::MemoryBuffer(std::size_t capacity)
    {
        create(capacity);
    }

    MemoryBuffer::MemoryBuffer(std::size_t capacity, Uint8 byte)
    {
        create(capacity);

        m_buffer->memset(byte);
    }

    bool MemoryBuffer::create(std::size_t capacity)
    {
        try
        {
            m_buffer = std::make_shared<HandlerType>(capacity);
        }
        catch (std::bad_alloc)
        {
            return false;
        }

        return true;
    }

    bool MemoryBuffer::fill(const void* data, std::size_t size, std::size_t offset, bool discard)
    {
        if(discard)
        {
            flush();
        }

        m_buffer->memcpy(reinterpret_cast<const Uint8*>(data), size, offset);

        return true;
    }

    Uint8& MemoryBuffer::at(std::size_t index)
    {
        return m_buffer->at(index);
    }

    const Uint8& MemoryBuffer::at(std::size_t index) const
    {
        return m_buffer->at(index);
    }

    Uint8& MemoryBuffer::operator[](std::size_t index)
    {
        return m_buffer->at(index);
    }

    const Uint8& MemoryBuffer::operator[](std::size_t index) const
    {
        return m_buffer->at(index);
    }

    void MemoryBuffer::flush()
    {
        m_buffer->memset(0);
    }

    void MemoryBuffer::destroy()
    {
        m_buffer = getEmptyHandler();
    }

    std::size_t MemoryBuffer::getCapacity() const
    {
        return m_buffer->getCapacity();
    }
}