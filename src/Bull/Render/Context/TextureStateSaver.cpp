#include <Bull/Render/Context/TextureStateSaver.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    TextureStateSaver::TextureStateSaver()
    {
        gl::getIntegerv(GL_TEXTURE_BINDING_2D, &m_texture);
    }

    TextureStateSaver::~TextureStateSaver()
    {
        gl::bindTexture(GL_TEXTURE_2D, m_texture);
    }
}
