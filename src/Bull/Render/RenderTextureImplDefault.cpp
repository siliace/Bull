#include <Bull/Render/Context/TextureStateSaver.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/RenderTextureImplDefault.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        RenderTextureImplDefault::RenderTextureImplDefault() :
            m_target(0)
        {
            /// Nothing
        }

        /*! \brief Create the RenderTextureImpl
         *
         * \param target The target to use to render
         *
         * \return Return true if the RenderTextureImpl was created successfully, false otherwise
         *
         */
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

        /*! \brief Display what has been rendered so far into the target texture
         *
         */
        void RenderTextureImplDefault::updateTarget()
        {
            TextureStateSaver saver;

            gl::bindTexture(GL_TEXTURE_2D, m_target);
            gl::copyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, m_size.x, m_size.y);
        }
    }
}
