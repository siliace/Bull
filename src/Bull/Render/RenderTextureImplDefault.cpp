#include <Bull/Render/Context/TextureStateShader.hpp>
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
            m_width(0),
            m_height(0)
        {
            /// Nothing
        }

        /*! \brief Create the RenderTextureImpl
         *
         * \param width          The width of the RenderTextureImpl
         * \param height         The height of the RenderTextureImpl
         * \param target         The target to use to render
         * \param useDepthBuffer True if a depth buffer is need, false otherwise
         *
         * \return Return true if the RenderTextureImpl was created successfully, false otherwise
         *
         */
        bool RenderTextureImplDefault::create(unsigned int width, unsigned int height, unsigned int target, bool useDepthBuffer)
        {
            ContextSettings settings = ContextSettings::Worst;

            m_width  = width;
            m_height = height;
            m_target = target;

            settings.depths = useDepthBuffer ? 32 : 0;

            createInternalContext(VideoMode(m_width, m_height), settings);

            return true;
        }

        /*! \brief Display what has been rendered so far into the target texture
         *
         */
        void RenderTextureImplDefault::updateTarget()
        {
            TextureStateSaver saver;

            gl::bindTexture(GL_TEXTURE_2D, m_target);
            gl::copyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, m_width, m_height);
        }
    }
}
