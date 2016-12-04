#include <cstring>

#include <Bull/Render/HardwareBuffer.hpp>

namespace Bull
{
    /*! \brief Bind a buffer
     *
     * \param buffer The buffer to bind
     *
     */
    void HardwareBuffer::bind(const HardwareBuffer& buffer)
    {
        ensureContext();
        gl::bindBuffer(buffer.m_type, buffer.m_id);
    }

    /*! \brief Unbind any buffer
     *
     * \param type The type of buffer to unbind
     *
     */
    void HardwareBuffer::unbind(Type type)
    {
        ensureContext();
        gl::bindBuffer(type, 0);
    }

    /*! \brief Constructor
     *
     * \param type The type the of OpenGL buffer to create
     *
     */
    HardwareBuffer::HardwareBuffer(Type type) :
        m_id(0),
        m_type(type),
        m_size(0)
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    HardwareBuffer::~HardwareBuffer()
    {
        destroy();
    }

    /*! \brief Create the buffer in the VRAM
     *
     * \param size  The size of the buffer
     * \param usage The usage of the buffer
     *
     * \return Return true if the buffer was created successfully, false otherwise
     *
     */
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

        m_size = size;

        return true;
    }

    /*! \brief Fill the buffer
     *
     * \param data    Data to use to fill the buffer
     * \param size    The size of data
     * \param offset  The offset of the data in the buffer
     * \param discard True to flush the buffer before fill it, false to keep the original content
     *
     * \return Return true if the buffer was filled successfully, false otherwise
     *
     */
    bool HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset, bool discard)
    {
        ensureContext();

        if(m_id && data && size)
        {
            gl::bindBuffer(m_type, m_id);

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

    /*! \brief Flush the buffer
     *
     * \param keepMemory True to keep the allocated memory, false otherwise
     *
     */
    void HardwareBuffer::flush(bool keepMemory)
    {
        if(m_id)
        {
            ensureContext();

            gl::bindBuffer(m_type, m_id);

            if(!keepMemory)
            {
                m_size = 0;
            }

            gl::bufferData(m_type, m_size, nullptr, StaticDraw);
        }
    }

    /*! \brief Destroy the buffer
     *
     */
    void HardwareBuffer::destroy()
    {
        if(m_id)
        {
            ensureContext();

            gl::deleteBuffers(1, &m_id);
        }
    }

    /*! \brief Get the buffer system handler
     *
     * \return Return the native buffer system handler
     *
     */
    unsigned int HardwareBuffer::getSystemHandler() const
    {
        return m_id;
    }
}
