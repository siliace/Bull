#include <cstring>

#include <Bull/Render/HardwareBuffer.hpp>

namespace Bull
{
    HardwareBuffer::HardwareBuffer(Type type) :
        m_id(0),
        m_type(type),
        m_capacity(0)
    {
        /// Nothing
    }

    HardwareBuffer::~HardwareBuffer()
    {
        destroy();
    }

    bool HardwareBuffer::create(std::size_t size)
    {
        return create(size, HardwareBuffer::Usage::StaticDraw);
    }

    bool HardwareBuffer::create(std::size_t size, Usage usage)
    {
        if(m_id)
        {
            destroy();
        }

        m_capacity = size;

        bind();
        gl::genBuffers(1, &m_id);
        gl::bindBuffer(m_type, m_id);
        gl::bufferData(m_type, m_capacity, nullptr, usage);

        return true;
    }

    bool HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset, bool discard)
    {
        if(m_id)
        {
            bind();

            if(discard)
            {
                flush();
            }

            /// It seems that glBufferSubData is more efficient than glMapBuffer with small buffers
            /// http://www.stevestreeting.com/2007/03/17/glmapbuffer-vs-glbuffersubdata-the-return/
            if(size < 32 * 1024)
            {
                gl::bufferSubData(m_type, offset, size, data);
            }
            else
            {
                unsigned char* ptr = reinterpret_cast<unsigned char*>(gl::mapBuffer(m_type, GL_WRITE_ONLY));

                if(!ptr)
                {
                    return false;
                }

                std::memcpy(ptr + offset, data, size);

                gl::unmapBuffer(m_type);
            }

            return true;
        }

        return false;
    }

    void* HardwareBuffer::map()
    {
        if(m_id)
        {
            bind();

            return gl::mapBuffer(m_type, GL_READ_WRITE);
        }

        return nullptr;
    }

    const void* HardwareBuffer::map() const
    {
        if(m_id)
        {
            bind();

            return gl::mapBuffer(m_type, GL_READ_ONLY);
        }

        return nullptr;
    }

    void HardwareBuffer::unmap() const
    {
        if(m_id)
        {
            bind();
            gl::unmapBuffer(m_type);
        }
    }

    void HardwareBuffer::flush()
    {
        if(m_id)
        {
            bind();

            m_capacity = 0;

            int usage;
            gl::getBufferParameteriv(m_id, GL_BUFFER_USAGE, &usage);
            gl::bufferData(m_type, m_capacity, nullptr, static_cast<GLenum >(usage));
        }
    }

    void HardwareBuffer::destroy()
    {
        if(m_id)
        {
            gl::deleteBuffers(1, &m_id);

            m_id       = 0;
            m_capacity = 0;
        }
    }

    std::size_t HardwareBuffer::getCapacity() const
    {
        return m_capacity;
    }

    HardwareBuffer::Type HardwareBuffer::getType() const
    {
        return m_type;
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }

    void HardwareBuffer::bind() const
    {
        if(m_id)
        {
            gl::bindBuffer(m_type, m_id);
        }
    }
}
