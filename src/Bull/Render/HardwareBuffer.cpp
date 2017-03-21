#include <cstring>

#include <Bull/Render/HardwareBuffer.hpp>

namespace Bull
{
    void HardwareBuffer::bind(const HardwareBuffer* buffer)
    {
        ensureContext();
        gl::bindBuffer(buffer->getType(), buffer->getSystemHandler());
    }

    void HardwareBuffer::unbind(Type type)
    {
        ensureContext();
        gl::bindBuffer(type, 0);
    }

    HardwareBuffer::HardwareBuffer(Type type) :
        m_id(0),
        m_size(0),
        m_type(type)
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
        ensureContext();

        if(m_id)
        {
            destroy();
        }

        m_size = size;

        gl::genBuffers(1, &m_id);
        gl::bindBuffer(m_type, m_id);
        gl::bufferData(m_type, m_size, nullptr, usage);

        return true;
    }

    bool HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset, bool discard)
    {
        if(m_id)
        {
            bind(this);

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
            bind(this);
            return gl::mapBuffer(m_type, GL_READ_WRITE);
        }

        return nullptr;
    }

    const void* HardwareBuffer::map() const
    {
        if(m_id)
        {
            bind(this);
            return gl::mapBuffer(m_type, GL_READ_ONLY);
        }

        return nullptr;
    }

    void HardwareBuffer::unmap() const
    {
        if(m_id)
        {
            bind(this);
            gl::unmapBuffer(m_type);
        }
    }

    void HardwareBuffer::flush()
    {
        if(m_id)
        {
            ensureContext();

            bind(this);

            m_size = 0;

            int usage;
            gl::getBufferParameteriv(m_id, GL_BUFFER_USAGE, &usage);
            gl::bufferData(m_type, m_size, nullptr, static_cast<GLenum >(usage));
        }
    }

    void HardwareBuffer::destroy()
    {
        if(m_id)
        {
            ensureContext();

            gl::deleteBuffers(1, &m_id);

            m_id = 0;
            m_size = 0;
        }
    }

    std::size_t HardwareBuffer::getSize() const
    {
        return m_size;
    }

    HardwareBuffer::Type HardwareBuffer::getType() const
    {
        return m_type;
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
