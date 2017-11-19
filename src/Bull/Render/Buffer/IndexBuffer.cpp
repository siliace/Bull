#include <Bull/Render/Buffer/IndexBuffer.hpp>

namespace Bull
{
    IndexBuffer::IndexBuffer() :
        HardwareBuffer(HardwareBufferType_Element),
        m_dataType(DataType_UnsignedInt)
    {
        /// Nothing
    }

    IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices, HardwareBufferUsage usage) :
        IndexBuffer()
    {
        create(indices, usage);
    }

    bool IndexBuffer::create(const std::vector<unsigned int>& indices, HardwareBufferUsage usage)
    {
        if(HardwareBuffer::create(indices.size() * sizeof(unsigned int), usage))
        {
            return fill(&indices[0], indices.size() * sizeof(unsigned int), 0);
        }

        return false;
    }

    DataType IndexBuffer::getDataType() const
    {
        return m_dataType;
    }
}