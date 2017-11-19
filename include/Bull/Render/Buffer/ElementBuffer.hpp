#ifndef BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP
#define BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP

#include <vector>

#include <Bull/Core/Utility/DataType.hpp>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>

namespace Bull
{
    class BULL_RENDER_API ElementBuffer : public HardwareBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        ElementBuffer();

        /*! \brief Constructor
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         */
        explicit ElementBuffer(const std::vector<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

        /*! \brief Create the ElementBuffer from a indice vector
         *
         * \param indices Indices in the ElementBuffer
         * \param usage   The usage (static, dynamic, stream) of the ElementBuffer
         *
         * \return True if the ElementBuffer was created successfully
         *
         */
        bool create(const std::vector<unsigned int>& indices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

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

#endif // BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP
