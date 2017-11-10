#include <cstring>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    namespace
    {
        constexpr unsigned int BufferType[]  = {GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER};
        constexpr unsigned int BufferUsage[] = {GL_STATIC_DRAW, GL_DYNAMIC_DRAW, GL_STREAM_DRAW};
    }

    HardwareBuffer::~HardwareBuffer()
    {
        if(gl::isBuffer(m_id))
        {
            gl::deleteBuffers(1, &m_id);
        }
    }

    bool HardwareBuffer::create(std::size_t size)
    {
        return create(size, HardwareBufferUsage_StaticDraw);
    }

    bool HardwareBuffer::create(std::size_t size, HardwareBufferUsage usage)
    {
        if(!gl::isBuffer(m_id))
        {
            gl::genBuffers(1, &m_id);
            gl::bindBuffer(BufferType[m_type], m_id);
            gl::bufferData(BufferType[m_type], size, nullptr, BufferUsage[usage]);

            return true;
        }

        return false;
    }

    bool HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset)
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            /// It seems that glBufferSubData is more efficient than glMapBuffer with small buffers
            /// http://www.stevestreeting.com/2007/03/17/glmapbuffer-vs-glbuffersubdata-the-return/
            if(size < 32 * 1024)
            {
                gl::bufferSubData(BufferType[m_type], offset, size, data);
            }
            else
            {
                unsigned char* ptr = reinterpret_cast<unsigned char*>(gl::mapBuffer(BufferType[m_type], GL_WRITE_ONLY));

                if(!ptr)
                {
                    return false;
                }

                std::memcpy(ptr + offset, data, size);

                gl::unmapBuffer(BufferType[m_type]);
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

            return gl::mapBuffer(BufferType[m_type], GL_READ_WRITE);
        }

        return nullptr;
    }

    const void* HardwareBuffer::map() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            return gl::mapBuffer(BufferType[m_type], GL_READ_ONLY);
        }

        return nullptr;
    }

    void HardwareBuffer::unmap() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            gl::unmapBuffer(BufferType[m_type]);
        }
    }

    void HardwareBuffer::clear()
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            int usage;
            gl::getBufferParameteriv(BufferType[m_type], GL_BUFFER_USAGE, &usage);
            gl::bufferData(BufferType[m_type], getCapacity(), nullptr, static_cast<unsigned int>(usage));
        }
    }

    std::size_t HardwareBuffer::getCapacity() const
    {
        if(gl::isBuffer(m_id))
        {
            bind();

            int capacity;
            gl::getBufferParameteriv(BufferType[m_type], GL_BUFFER_SIZE, &capacity);

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
        if(gl::isBuffer(m_id))
        {
            gl::bindBuffer(BufferType[m_type], m_id);
        }
    }

    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
