#ifndef BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP
#define BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP

#include <vector>

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
         * \param indices
         * \param usage
         *
         */
        ElementBuffer(const std::vector<unsigned int>& indices, Usage usage = StaticDraw);

        /*! \brief
         *
         * \param indices
         * \param usage
         *
         * \return
         *
         */
        bool create(const std::vector<unsigned int>& indices, Usage usage = StaticDraw);
    };
}

#endif // BULL_RENDER_BUFFER_ELEMENTBUFFER_HPP
