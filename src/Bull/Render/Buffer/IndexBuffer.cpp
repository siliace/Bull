#include <Bull/Render/Buffer/IndexBuffer.hpp>

namespace Bull
{
    IndexBuffer::IndexBuffer() :
        HardwareBuffer(HardwareBufferType_Element),
        m_dataType(DataType_UnsignedInt)
    {
        /// Nothing
    }

    IndexBuffer::IndexBuffer(const ArrayList<unsigned int>& indices, HardwareBufferUsage usage) :
        IndexBuffer()
    {
        create(indices, usage);
    }

    bool IndexBuffer::create(const ArrayList<unsigned int>& indices, HardwareBufferUsage usage)
    {
        if(HardwareBuffer::create(indices.getSize() * sizeof(unsigned int), usage))
        {
            return fill(indices.getBuffer(), indices.getSize() * sizeof(unsigned int), 0);
        }

        return false;
    }

    DataType IndexBuffer::getDataType() const
    {
        return m_dataType;
    }
}