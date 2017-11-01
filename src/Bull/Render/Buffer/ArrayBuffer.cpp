#include <Bull/Render/Buffer/ArrayBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    ArrayBuffer::ArrayBuffer() :
        HardwareBuffer(HardwareBufferType_Array)
    {
        /// Nothing
    }

    ArrayBuffer::ArrayBuffer(const std::vector<Vertex>& vertices, HardwareBufferUsage usage) :
        ArrayBuffer()
    {
        create(vertices, usage);
    }

    bool ArrayBuffer::create(const std::vector<Vertex>& vertices, HardwareBufferUsage usage)
    {
        if(HardwareBuffer::create(vertices.size() * sizeof(Vertex), usage))
        {
            return fill(&vertices[0], getCapacity(), 0);
        }

        return false;
    }

    ArrayBuffer& ArrayBuffer::setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride, std::size_t start)
    {
        if(gl::isBuffer(getSystemHandler()))
        {
            bind();

            gl::enableVertexAttribArray(attrib);
            gl::vertexAttribPointer(attrib, static_cast<int>(size), GL_FLOAT, GL_FALSE, static_cast<int>(stride), (void*)start);
        }

        return (*this);
    }
}