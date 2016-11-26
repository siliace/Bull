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
             * \param size   The size of the rendering target
             * \param target The rendering target
             *
             * \return Return true if the RenderTextureImpl was created successfully, false otherwise
             *
             */
            bool create(const Vector2UI& size, unsigned int target) override;

            /*! \brief Display what has been rendered so far into the target texture
             *
             */
            void updateTarget() override;

        private:

            unsigned int m_target;
            Vector2UI    m_size;
        };
    }
}

#endif // Bull_RenderTextureImplDefault_hpp
