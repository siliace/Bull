#include <Bull/Render/Buffer/VertexBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    VertexBuffer::VertexBuffer() :
        HardwareBuffer(HardwareBufferType_Array)
    {
        /// Nothing
    }

    VertexBuffer::VertexBuffer(const std::vector<Vertex>& vertices, HardwareBufferUsage usage) :
        VertexBuffer()
    {
        create(vertices, usage);
    }

    bool VertexBuffer::create(const std::vector<Vertex>& vertices, HardwareBufferUsage usage)
    {
        HardwareBuffer::create(vertices.size() * sizeof(Vertex), usage);

        fill(&vertices[0], getCapacity(), 0);
    }

    void VertexBuffer::setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride, std::size_t start)
    {
        bind();

        gl::enableVertexAttribArray(attrib);
        gl::vertexAttribPointer(attrib, static_cast<int>(size), GL_FLOAT, GL_FALSE, static_cast<int>(stride), (void*)start);
    }
}