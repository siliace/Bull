#include <cstring>

#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/Throw.hpp>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Context/OpenGLHandlerError.hpp>

namespace Bull
{
    namespace
    {
        constexpr unsigned int bufferType[]  = {GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER};
        constexpr unsigned int bufferUsage[] = {GL_STATIC_DRAW, GL_DYNAMIC_DRAW, GL_STREAM_DRAW};
    }

    HardwareBuffer::~HardwareBuffer()
    {
        if(isValid())
        {
            gl::deleteBuffers(1, &m_id);
        }
    }

    void HardwareBuffer::create(std::size_t size)
    {
        create(size, DefaultUsage);
    }

    void HardwareBuffer::create(std::size_t size, HardwareBufferUsage usage)
    {
        if(isValid())
        {
            clear();
        }

        gl::genBuffers(1, &m_id);
        gl::bindBuffer(bufferType[m_type], m_id);

        Expect(gl::isBuffer(m_id), Throw(OpenGLHandlerError, "HardwareBuffer::create", "Failed to create buffer"));

        gl::bufferData(bufferType[m_type], size, nullptr, bufferUsage[usage]);
    }

    void HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset)
    {
        Expect(isValid(), Throw(LogicError, "HardwareBuffer::fill", "The buffer is not created"));
        Expect(data, Throw(LogicError, "HardwareBuffer::fill", "Invalid buffer pointer"));
        Expect(size, Throw(InvalidParameter, "HardwareBuffer::fill", "Invalid buffer size"));
        Expect(size + offset <= getCapacity(), Throw(InvalidParameter, "HardwareBuffer::fill", "Invalid buffer size"));

        bind();

        /// It seems that glBufferSubData is more efficient than glMapBuffer with small buffers
        /// http://www.stevestreeting.com/2007/03/17/glmapbuffer-vs-glbuffersubdata-the-return/
        if(size < 32 * 1024)
        {
            gl::bufferSubData(bufferType[m_type], offset, size, data);
        }
        else
        {
            unsigned char* ptr = reinterpret_cast<unsigned char*>(map());

            Expect(ptr, Throw(InternalError, "HardwareBuffer::fill", "Failed to map HardwareBuffer"));

            std::memcpy(ptr + offset, data, size);

            unmap();
        }
    }

    bool HardwareBuffer::isValid() const
    {
        return gl::isBuffer(m_id);
    }

    void* HardwareBuffer::map()
    {
        if(isValid())
        {
            bind();

            return gl::mapBuffer(bufferType[m_type], GL_READ_WRITE);
        }

        return nullptr;
    }

    const void* HardwareBuffer::map() const
    {
        if(isValid())
        {
            bind();

            return gl::mapBuffer(bufferType[m_type], GL_READ_ONLY);
        }

        return nullptr;
    }

    void HardwareBuffer::unmap() const
    {
        if(isValid())
        {
            bind();

            gl::unmapBuffer(bufferType[m_type]);
        }
    }

    void HardwareBuffer::clear()
    {
        if(isValid())
        {
            bind();

            int usage;
            gl::getBufferParameteriv(bufferType[m_type], GL_BUFFER_USAGE, &usage);
            gl::bufferData(bufferType[m_type], getCapacity(), nullptr, usage);
        }
    }

    std::size_t HardwareBuffer::getCapacity() const
    {
        if(isValid())
        {
            bind();

            int capacity;
            gl::getBufferParameteriv(bufferType[m_type], GL_BUFFER_SIZE, &capacity);

            return static_cast<std::size_t>(capacity);
        }

        return 0;
    }

    HardwareBuffer::HardwareBuffer(HardwareBufferType type) :
        m_id(0),
        m_type(type)
    {
        /// Nothing
    }


    void HardwareBuffer::bind() const
    {
        Expect(isValid(), Throw(LogicError, "HardwareBuffer::bind", "The buffer was not created"));

        gl::bindBuffer(bufferType[m_type], m_id);
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
