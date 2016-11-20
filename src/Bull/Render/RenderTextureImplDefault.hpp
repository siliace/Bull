#ifndef Bull_RenderTextureImplDefault_hpp
#define Bull_RenderTextureImplDefault_hpp

#include <Bull/Render/RenderTextureImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class RenderTextureImplDefault : public RenderTextureImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            RenderTextureImplDefault();

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
            bool create(unsigned int width, unsigned int height, unsigned int target, bool useDepthBuffer = false) override;

            /*! \brief Display what has been rendered so far into the target texture
             *
             */
            void updateTarget() override;

        private:

            unsigned int m_width, m_height;
        };
    }
}

#endif // Bull_RenderTextureImplDefault_hpp
