#ifndef BULL_RENDER_BUFFER_VERTEXBUFFER_HPP
#define BULL_RENDER_BUFFER_VERTEXBUFFER_HPP

#include <vector>

#include <Bull/Core/Utility/Vertex.hpp>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>

namespace Bull
{
    class BULL_RENDER_API VertexBuffer : public HardwareBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        VertexBuffer();

        /*! \brief Constructor
         *
         * \param vertices Vertices in the ArrayBuffer
         * \param usage    The usage (static, dynamic, stream) of the ArrayBuffer
         *
         */
        explicit VertexBuffer(const std::vector<Vertex>& vertices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

        /*! \brief Create the ArrayBuffer from a Vertex vector
         *
         * \param vertices Vertices in the ArrayBuffer
         * \param usage    The usage (static, dynamic, stream) of the ArrayBuffer
         *
         * \return True if the ArrayBuffer was created successfully
         *
         */
        bool create(const std::vector<Vertex>& vertices, HardwareBufferUsage usage = HardwareBufferUsage_StaticDraw);

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
        VertexBuffer& setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride = 0, std::size_t start = 0);
    };
}

#endif // BULL_RENDER_BUFFER_VERTEXBUFFER_HPP
