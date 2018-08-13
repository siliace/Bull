#include <Bull/Render/Buffer/IndexBuffer.hpp>

namespace Bull
{
    IndexBuffer::IndexBuffer() :
        HardwareBuffer(HardwareBufferType_Element),
        m_dataType(DataType_UnsignedInt)
    {
        /// Nothing
    }

    IndexBuffer::IndexBuffer(IndexBuffer&& right) noexcept :
        HardwareBuffer(std::move(right))
    {
        std::swap(m_dataType, right.m_dataType);
    }

    IndexBuffer& IndexBuffer::operator=(IndexBuffer&& right) noexcept
    {
        std::swap(m_dataType, right.m_dataType);

        HardwareBuffer::operator=(std::move(right));

        return *this;
    }

    IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices, HardwareBufferUsage usage) :
        IndexBuffer()
    {
        create(indices, usage);
    }

    void IndexBuffer::create(const std::vector<unsigned int>& indices, HardwareBufferUsage usage)
    {
        HardwareBuffer::create(indices.size() * sizeof(unsigned int), usage);

        fill(indices.data(), indices.size() * sizeof(unsigned int), 0);
    }

    DataType IndexBuffer::getDataType() const
    {
        return m_dataType;
    }
}