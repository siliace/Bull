#include <cstring>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>

namespace Bull
{
    HardwareBuffer::~HardwareBuffer()
    {
        destroy();
    }

    bool HardwareBuffer::create(Index size)
    {
        return create(size, HardwareBuffer::Usage::StaticDraw);
    }

    bool HardwareBuffer::create(Index size, Usage usage)
    {
        if(gl::isBuffer(m_id))
        {
            destroy();
        }

        gl::genBuffers(1, &m_id);
        gl::bindBuffer(m_type, m_id);
        gl::bufferData(m_type, size, nullptr, usage);

        return true;
    }

    bool HardwareBuffer::fill(const void* data, Index size, Index offset)
    {
        if(gl::isBuffer(m_id))
        {
            bind();

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
        if(gl::isBuffer(m_id))
        {
            bind();

            return gl::mapBuffer(m_type, GL_READ_WRITE);
        }

        return nullptr;
    }

    const void* HardwareBuffer::map() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            return gl::mapBuffer(m_type, GL_READ_ONLY);
        }

        return nullptr;
    }

    void HardwareBuffer::unmap() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            gl::unmapBuffer(m_type);
        }
    }

    void HardwareBuffer::flush()
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            int usage;
            gl::getBufferParameteriv(m_type, GL_BUFFER_USAGE, &usage);
            gl::bufferData(m_type, getCapacity(), nullptr, static_cast<GLenum >(usage));
        }
    }

    void HardwareBuffer::destroy()
    {
        if(gl::isBuffer(m_id))
        {
            gl::deleteBuffers(1, &m_id);
        }
    }

    Index HardwareBuffer::getCapacity() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            int capacity;
            gl::getBufferParameteriv(m_type, GL_BUFFER_SIZE, &capacity);

            return static_cast<Index>(capacity);
        }

        return 0;
    }

    HardwareBuffer::HardwareBuffer(Type type) :
        m_id(0),
        m_type(type)
    {
        /// Nothing
    }


    void HardwareBuffer::bind() const
    {
        if(gl::isBuffer(m_id))
        {
            gl::bindBuffer(m_type, m_id);
        }
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
