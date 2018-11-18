#include <Bull/Core/Memory/MemoryAccumulator.hpp>

namespace Bull
{
    std::size_t MemoryAccumulator::write(const ByteArray& bytes)
    {
        return write(bytes.getBuffer(), bytes.getCapacity());
    }

    std::size_t MemoryAccumulator::write(const void* data, std::size_t length)
    {
        m_bytes.fill(data, length, m_bytes.getCapacity());

        return length;
    }

    void MemoryAccumulator::flush()
    {
        /// Nothing
    }

    const ByteArray& MemoryAccumulator::getBytes() const
    {
        return m_bytes;
    }
}