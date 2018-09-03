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

    void ArrayBuffer::create(const std::vector<Vertex>& vertices, HardwareBufferUsage usage)
    {
        HardwareBuffer::create(vertices.size() * sizeof(Vertex), usage);

        fill(&vertices[0], getCapacity(), 0);
    }

    void ArrayBuffer::setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride, std::size_t start)
    {
        bind();

        gl::enableVertexAttribArray(attrib);
        gl::vertexAttribPointer(attrib, static_cast<int>(size), GL_FLOAT, GL_FALSE, static_cast<int>(stride), (void*)start);
    }

    void ArrayBuffer::setAttribDivisor(unsigned int attrib, unsigned int divisor) const
    {
        bind();

        gl::enableVertexAttribArray(attrib);
        gl::vertexAttribDivisor(attrib, divisor);
    }
}