#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Target/RenderTextureImplDefault.hpp>

namespace Bull
{
    namespace prv
    {
        RenderTextureImplDefault::RenderTextureImplDefault() :
            m_target(0)
        {
            /// Nothing
        }

        bool RenderTextureImplDefault::create(const Vector2UI& size, unsigned int target)
        {
            if(target && size.x && size.y)
            {
                m_size   = size;
                m_target = target;

                return true;
            }

            return false;
        }

        void RenderTextureImplDefault::updateTarget()
        {
            gl::bindTexture(GL_TEXTURE_2D, m_target);
            gl::copyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, m_size.x, m_size.y);
        }
    }
}
