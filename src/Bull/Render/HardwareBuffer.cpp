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
        m_type(type)
    {
        /// Nothing
    }

    HardwareBuffer::~HardwareBuffer()
    {
        ensureContext();
        destroy();
    }

    bool HardwareBuffer::create(std::size_t size, Usage usage)
    {
        ensureContext();

        if(m_id)
        {
            destroy();
        }

        gl::genBuffers(1, &m_id);
        gl::bindBuffer(m_type, m_id);
        gl::bufferData(m_type, size, nullptr, usage);

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

    void HardwareBuffer::flush()
    {
        if(m_id)
        {
            ensureContext();

            bind(this);

            int usage;
            gl::getBufferParameteriv(m_id, GL_BUFFER_USAGE, &usage);
            gl::bufferData(m_type, 0, nullptr, static_cast<GLenum >(usage));
        }
    }

    void HardwareBuffer::destroy()
    {
        if(m_id)
        {
            ensureContext();

            gl::deleteBuffers(1, &m_id);
        }
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
