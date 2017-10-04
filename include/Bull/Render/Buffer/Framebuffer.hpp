#ifndef BULL_RENDER_BUFFER_FRAMEBUFFER_HPP
#define BULL_RENDER_BUFFER_FRAMEBUFFER_HPP

#include <Bull/Render/Export.hpp>

namespace Bull
{
    class BULL_RENDER_API Framebuffer : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Framebuffer();

        /*! \brief Destructor
         *
         */
        ~Framebuffer();

    private:

        unsigned int m_id;
    };
}

#endif // BULL_RENDER_BUFFER_FRAMEBUFFER_HPP
