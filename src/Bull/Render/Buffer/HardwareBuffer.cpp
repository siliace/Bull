#include <cstring>
#include <map>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Context/OpenGLHandlerError.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    HardwareBuffer::~HardwareBuffer()
    {
        if(isValid())
        {
            gl::deleteBuffers(1, &m_id);
        }
    }

    void HardwareBuffer::create(std::size_t size)
    {
        create(size, HardwareBufferUsage::StaticDraw);
    }

    void HardwareBuffer::create(std::size_t size, HardwareBufferUsage usage)
    {
        if(isValid())
        {
            clear();
        }

        gl::genBuffers(1, &m_id);
        gl::bindBuffer(OpenGL::hardwareBufferType(m_type), m_id);

        Expect(gl::isBuffer(m_id), Throw(OpenGLHandlerError, "Failed to create buffer"));

        gl::bufferData(OpenGL::hardwareBufferType(m_type), size, nullptr, OpenGL::hardwareBufferUsage(usage));
    }

    void HardwareBuffer::bind() const
    {
        Expect(isValid(), Throw(LogicError, "The buffer was not created"));

        gl::bindBuffer(OpenGL::hardwareBufferType(m_type), m_id);
    }

    void HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset)
    {
        Expect(data && size, Throw(InvalidParameter, "Invalid buffer"));
        Expect(isValid(), Throw(LogicError, "The buffer is not created"));
        Expect(size + offset <= getCapacity(), Throw(InvalidParameter, "Invalid buffer size"));

        bind();

        /// It seems that glBufferSubData is more efficient than glMapBuffer with small buffers
        /// http://www.stevestreeting.com/2007/03/17/glmapbuffer-vs-glbuffersubdata-the-return/
        if(size < 32 * 1024)
        {
            gl::bufferSubData(OpenGL::hardwareBufferType(m_type), offset, size, data);
        }
        else
        {
            unsigned char* ptr = reinterpret_cast<unsigned char*>(map());

            Expect(ptr, Throw(InternalError, "Failed to map HardwareBuffer"));

            std::memcpy(ptr + offset, data, size);

            unmap();
        }
    }

    bool HardwareBuffer::isValid() const
    {
        ensureContext();

        return gl::isBuffer(m_id);
    }

    void* HardwareBuffer::map()
    {
        bind();

        return gl::mapBuffer(OpenGL::hardwareBufferType(m_type), GL_READ_WRITE);
    }

    const void* HardwareBuffer::map() const
    {
        bind();

        return gl::mapBuffer(OpenGL::hardwareBufferType(m_type), GL_READ_ONLY);
    }

    void HardwareBuffer::unmap() const
    {
        bind();

        gl::unmapBuffer(OpenGL::hardwareBufferType(m_type));
    }

    void HardwareBuffer::clear()
    {
        bind();

        int usage;
        gl::getBufferParameteriv(OpenGL::hardwareBufferType(m_type), GL_BUFFER_USAGE, &usage);
        gl::bufferData(OpenGL::hardwareBufferType(m_type), getCapacity(), nullptr, usage);
    }

    std::size_t HardwareBuffer::getCapacity() const
    {
        bind();

        int capacity;
        gl::getBufferParameteriv(OpenGL::hardwareBufferType(m_type), GL_BUFFER_SIZE, &capacity);

        return static_cast<std::size_t>(capacity);
    }

    HardwareBuffer::HardwareBuffer(HardwareBufferType type) :
        m_id(0),
        m_type(type)
    {
        /// Nothing
    }

    HardwareBuffer::HardwareBuffer(HardwareBuffer&& right) noexcept
    {
        std::swap(m_id, right.m_id);
        std::swap(m_type, right.m_type);
    }

    HardwareBuffer& HardwareBuffer::operator=(HardwareBuffer&& right) noexcept
    {
        std::swap(m_id, right.m_id);
        std::swap(m_type, right.m_type);

        return *this;
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
