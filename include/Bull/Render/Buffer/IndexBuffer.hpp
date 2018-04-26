#ifndef BULL_RENDER_BUFFER_INDEXEBUFFER_HPP
#define BULL_RENDER_BUFFER_INDEXEBUFFER_HPP

#include <Bull/Core/Utility/ArrayList.hpp>
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

        /*! \brief Constructor
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         */
        explicit IndexBuffer(const ArrayList<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

        /*! \brief Create the ElementBuffer from a indice vector
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         * \return True if the ElementBuffer was created successfully
         *
         */
        bool create(const ArrayList<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

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
