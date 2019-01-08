#include <Bull/Render/Buffer/ArrayBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    ArrayBuffer::ArrayBuffer() :
        HardwareBuffer(HardwareBufferType::Array)
    {
        /// Nothing
    }

    ArrayBuffer::ArrayBuffer(const VertexArray& vertices, HardwareBufferUsage usage) :
        ArrayBuffer()
    {
        create(vertices, usage);
    }

    void ArrayBuffer::create(const VertexArray& vertices, HardwareBufferUsage usage)
    {
        HardwareBuffer::create(vertices.getSize() * sizeof(Vertex), usage);

        fill(vertices.getBuffer(), getCapacity(), 0);
    }

    void ArrayBuffer::setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride, std::size_t start) const
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