#ifndef BULL_HARDWAREBUFFER_HPP
#define BULL_HARDWAREBUFFER_HPP

#include <utility>

#include <Bull/Core/Memory/Buffer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API HardwareBuffer : public NonCopyable, public ContextResource, public Buffer
    {
    public:

        enum Usage
        {
            StaticDraw  = GL_STATIC_DRAW,
            DynamicDraw = GL_DYNAMIC_DRAW,
            StreamDraw  = GL_STREAM_DRAW,
        };

    protected:

        enum Type
        {
            Array   = GL_ARRAY_BUFFER,
            Element = GL_ELEMENT_ARRAY_BUFFER,
        };

    public:

        /*! \brief Destructor
         *
         */
        ~HardwareBuffer();

        /*! \brief Create the buffer in the VRAM
         *
         * \param capacity The capacity of the buffer
         *
         * \return Return true if the buffer was created successfully, false otherwise
         *
         */
        bool create(std::size_t capacity) override;

        /*! \brief Create the buffer in the VRAM
         *
         * \param capacity The capacity of the buffer
         * \param usage    The usage of the buffer
         *
         * \return Return true if the buffer was created successfully, false otherwise
         *
         */
        bool create(std::size_t size, Usage usage);

        /*! \brief Fill the buffer
         *
         * \param data    Data to use to fill the buffer
         * \param size    The size of data
         * \param offset  The offset of the data in the buffer
         * \param discard True to flush the buffer before fill it, false to keep the original content
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0, bool discard = false) override;

        /*! \brief Map data to a pointer
         *
         * \return A pointer to data
         *
         */
        void* map();

        /*! \brief Map data to a pointer
         *
         * \return A pointer to data
         *
         */
        const void* map() const;

        /*! \brief Unmap the buffer
         *
         */
        void unmap() const;

        /*! \brief Flush the buffer
         *
         */
        void flush() override;

        /*! \brief Destroy the buffer
         *
         */
        void destroy() override;

        /*! \brief Get the capacity of the HardwareBuffer
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const;

    protected:

        /*! \brief Constructor
         *
         * \param type The type the of OpenGL buffer to create
         *
         */
        HardwareBuffer(Type type);

        /*! \brief Bind the buffer
         *
         */
        void bind() const;

        /*! \brief Get the buffer system handler
         *
         * \return The native buffer system handler
         *
         */
        unsigned int getSystemHandler() const;

    private:

        unsigned int m_id;
        Type         m_type;
    };
}

#endif // BULL_HARDWAREBUFFER_HPP