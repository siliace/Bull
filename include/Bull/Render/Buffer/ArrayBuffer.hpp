#ifndef BULL_RENDER_BUFFER_ARRAYBUFFER_HPP
#define BULL_RENDER_BUFFER_ARRAYBUFFER_HPP

#include <vector>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Buffer/HardwareBuffer.hpp>

#include <Bull/Utility/Vertex.hpp>

namespace Bull
{
    class BULL_RENDER_API ArrayBuffer : public HardwareBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        ArrayBuffer();

        /*! \brief Constructor
         *
         * \param vertices Vertices in the ArrayBuffer
         *
         */
        ArrayBuffer(const std::vector<Vertex>& vertices, Usage usage = StaticDraw);

        /*! \brief Create the ArrayBuffer from a Vertex vector
         *
         * \param vertices Vertices in the ArrayBuffer
         *
         * \return True if the ArrayBuffer was created successfully
         *
         */
        bool create(const std::vector<Vertex>& vertices, Usage usage = StaticDraw);

        /*! \brief Set a buffer array attribute pointer
         *
         * \param attrib The attribute's index
         * \param size   The size of the attribute
         * \param stride The stride of the buffer
         * \param start  The beginning of the attribute in the stride
         *
         * \return This
         *
         */
        ArrayBuffer& setAttribPointer(unsigned int attrib, Index size, Index stride = 0, Index start = 0);
    };
}

#endif // BULL_RENDER_BUFFER_ARRAYBUFFER_HPP
