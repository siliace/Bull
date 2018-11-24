#ifndef BULL_RENDER_BUFFER_INDEXEBUFFER_HPP
#define BULL_RENDER_BUFFER_INDEXEBUFFER_HPP

#include <vector>

#include <Bull/Core/Utility/DataType.hpp>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>

namespace Bull
{
    class BULL_RENDER_API IndexBuffer : public HardwareBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        IndexBuffer();

        /*! \brief Constructor by movement semantic
         *
         * \param right The IndexBuffer to move
         *
         */
        IndexBuffer(IndexBuffer&& right) noexcept;

        /*! \brief Basic assignment operator by movement semantic
         *
         * \param right The IndexBuffer to move
         *
         * \return This
         *
         */
        IndexBuffer& operator=(IndexBuffer&& right) noexcept;

        /*! \brief Constructor
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         */
        explicit IndexBuffer(const std::vector<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage::StaticDraw);

        /*! \brief Create the ElementBuffer from a indices vector
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         */
        void create(const std::vector<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage::StaticDraw);

        /*! \brief Get the DataType of the element buffer
         *
         * \return The DataType
         *
         */
        DataType getDataType() const;

    private:

        DataType m_dataType;
    };
}

#endif // BULL_RENDER_BUFFER_INDEXEBUFFER_HPP
