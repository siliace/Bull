#ifndef BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP
#define BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP

#include <utility>

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Buffer/HardwareBufferType.hpp>
#include <Bull/Render/Buffer/HardwareBufferUsage.hpp>
#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API HardwareBuffer : public NonCopyable, public ContextResource, public AbstractBuffer
    {
    public:

        /*! \brief Destructor
         *
         */
        virtual ~HardwareBuffer();

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
        bool create(std::size_t capacity, HardwareBufferUsage usage);

        /*! \brief Fill the buffer
         *
         * \param data   Data to use to fill the buffer
         * \param size   The size of data
         * \param offset The offset of the data in the buffer
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0) override;

        /*! \brief Tell whether the HardwareBuffer is valid
         *
         * A HardwareBuffer is valid since its exists in the VRAM no matter if its filled or not
         *
         * \return True if the HardwareBuffer is valid
         *
         */
        bool isValid() const;

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

        /*! \brief Clear the HardwareBuffer
         *
         */
        void clear() override;

        /*! \brief Get the capacity of the HardwareBuffer
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const override;

    protected:

        /*! \brief Constructor
         *
         * \param type The type the of OpenGL buffer to create
         *
         */
        explicit HardwareBuffer(HardwareBufferType type);

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

        unsigned int       m_id;
        HardwareBufferType m_type;
    };
}

#endif // BULL_RENDER_BUFFER_HARDWAREBUFFER_HPP
