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
        m_type(type)
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

        return true;
    }

    /*! \brief Fill the buffer
     *
     * \param data   Data to use to fill the buffer
     * \param size   The size of data
     * \param offset The offset of the data in the buffer
     *
     * \return Return true if the buffer was filled successfully, false otherwise
     *
     */
    bool HardwareBuffer::fill(const void* data, std::size_t size, std::size_t offset)
    {
        ensureContext();

        if(m_id)
        {
            gl::bindBuffer(m_type, m_id);
            gl::bufferSubData(m_type, offset, size, data);

            return true;
        }

        return false;

    }

    /*! \brief Flush the buffer
     *
     */
    void HardwareBuffer::flush()
    {
        if(m_id)
        {
            ensureContext();

            gl::bindBuffer(m_type, m_id);
            gl::bufferData(m_type, 0, nullptr, StaticDraw);
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
