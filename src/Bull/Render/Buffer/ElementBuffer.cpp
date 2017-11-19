#include <Bull/Render/Buffer/ElementBuffer.hpp>

namespace Bull
{
    ElementBuffer::ElementBuffer() :
        HardwareBuffer(HardwareBufferType_Element),
        m_dataType(DataType_UnsignedInt)
    {
        /// Nothing
    }

    ElementBuffer::ElementBuffer(const std::vector<unsigned int>& indices, HardwareBufferUsage usage) :
        ElementBuffer()
    {
        create(indices, usage);
    }

    bool ElementBuffer::create(const std::vector<unsigned int>& indices, HardwareBufferUsage usage)
    {
        if(HardwareBuffer::create(indices.size() * sizeof(unsigned int), usage))
        {
            return fill(&indices[0], indices.size() * sizeof(unsigned int), 0);
        }

        return false;
    }

    DataType ElementBuffer::getDataType() const
    {
        return m_dataType;
    }
}