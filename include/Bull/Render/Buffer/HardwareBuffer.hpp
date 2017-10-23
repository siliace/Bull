#ifndef BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP
#define BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP

#include <utility>

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API HardwareBuffer : public NonCopyable, public ContextResource, public AbstractBuffer
    {
    public:

        enum Usage
        {
            StaticDraw,
            DynamicDraw,
            StreamDraw,
        };

    protected:

        enum Type
        {
            Array,
            Element
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
        bool create(Index capacity) override;

        /*! \brief Create the buffer in the VRAM
         *
         * \param capacity The capacity of the buffer
         * \param usage    The usage of the buffer
         *
         * \return Return true if the buffer was created successfully, false otherwise
         *
         */
        bool create(Index capacity, Usage usage);

        /*! \brief Fill the buffer
         *
         * \param data   Data to use to fill the buffer
         * \param size   The size of data
         * \param offset The offset of the data in the buffer
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, Index size, Index offset = 0) override;

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
        Index getCapacity() const override;

    protected:

        /*! \brief Constructor
         *
         * \param type The type the of OpenGL buffer to create
         *
         */
        explicit HardwareBuffer(Type type);

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

#endif // BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP
