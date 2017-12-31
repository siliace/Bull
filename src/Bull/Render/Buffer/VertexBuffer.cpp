#include <Bull/Render/Buffer/VertexBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    VertexBuffer::VertexBuffer() :
        HardwareBuffer(HardwareBufferType_Array)
    {
        /// Nothing
    }

    VertexBuffer::VertexBuffer(const VertexArray& vertices, HardwareBufferUsage usage) :
        VertexBuffer()
    {
        create(vertices, usage);
    }

    bool VertexBuffer::create(const VertexArray& vertices, HardwareBufferUsage usage)
    {
        if(HardwareBuffer::create(vertices.getVertexCount() * sizeof(Vertex), usage))
        {
            return fill(&vertices[0], getCapacity(), 0);
        }

        return false;
    }

    VertexBuffer& VertexBuffer::setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride, std::size_t start)
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