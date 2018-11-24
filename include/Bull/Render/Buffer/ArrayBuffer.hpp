#ifndef BULL_RENDER_BUFFER_ARRAYBUFFER_HPP
#define BULL_RENDER_BUFFER_ARRAYBUFFER_HPP

#include <vector>

#include <Bull/Render/Buffer/HardwareBuffer.hpp>
#include <Bull/Render/Vertex/Vertex.hpp>

namespace Bull
{
    struct BULL_RENDER_API ArrayBuffer : public HardwareBuffer
    {
        /*! \brief Default constructor
         *
         */
        ArrayBuffer();

        /*! \brief Constructor by movement semantic
         *
         * \param right The ArrayBuffer to move
         *
         */
        ArrayBuffer(ArrayBuffer&& right) noexcept = default;

        /*! \brief Basic assignment operator by movement semantic
         *
         * \param right The ArrayBuffer to move
         *
         * \return This
         *
         */
        ArrayBuffer& operator=(ArrayBuffer&& right) noexcept = default;

        /*! \brief Constructor
         *
         * \param vertices Vertices in the ArrayBuffer
         * \param usage    The usage (static, dynamic, stream) of the ArrayBuffer
         *
         */
        explicit ArrayBuffer(const std::vector<Vertex>& vertices, HardwareBufferUsage usage = HardwareBufferUsage::StaticDraw);

        /*! \brief Create the ArrayBuffer from a Vertex vector
         *
         * \param vertices Vertices in the ArrayBuffer
         * \param usage    The usage (static, dynamic, stream) of the ArrayBuffer
         *
         */
        void create(const std::vector<Vertex>& vertices, HardwareBufferUsage usage = HardwareBufferUsage::StaticDraw);

        /*! \brief Set a buffer array attribute pointer
         *
         * \param attrib The attribute's index
         * \param size   The size of the attribute
         * \param stride The stride of the buffer
         * \param start  The beginning of the attribute in the stride
         *
         */
        void setAttribPointer(unsigned int attrib, std::size_t size, std::size_t stride = 0, std::size_t start = 0) const;

        /*! \brief Set a buffer array attribute divisor
         *
         * \param attrib  The attribute's index
         * \param divisor The divisor
         *
         */
        void setAttribDivisor(unsigned int attrib, unsigned int divisor) const;
    };
}

#endif // BULL_RENDER_BUFFER_ARRAYBUFFER_HPP
