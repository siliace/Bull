#include <Bull/Render/Context/TextureStateShader.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    TextureStateSaver::TextureStateSaver()
    {
        gl::getIntegerv(GL_TEXTURE_BINDING_2D, &m_texture);
    }

    /*! \brief Destructor
     *
     */
    TextureStateSaver::~TextureStateSaver()
    {
        gl::bindTexture(GL_TEXTURE_2D, m_texture);
    }
}
