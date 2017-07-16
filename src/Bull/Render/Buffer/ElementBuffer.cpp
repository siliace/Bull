#include <Bull/Render/Buffer/ElementBuffer.hpp>

namespace Bull
{
    ElementBuffer::ElementBuffer() :
        HardwareBuffer(Element)
    {
        /// Nothing
    }

    ElementBuffer::ElementBuffer(const std::vector<unsigned int>& indices, Usage usage) :
        ElementBuffer()
    {
        create(indices, usage);
    }

    bool ElementBuffer::create(const std::vector<unsigned int>& indices, Usage usage)
    {
        if(HardwareBuffer::create(indices.size() * sizeof(unsigned int), usage))
        {
            return fill(&indices[0], indices.size() * sizeof(unsigned int), 0, true);
        }

        return false;
    }
}