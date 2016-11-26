#include <Bull/Render/RenderTextureImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Destructor
         *
         */
        RenderTextureImpl::~RenderTextureImpl()
        {
            /// Nothing
        }

        /*! \brief Create the RenderTextureImpl
         *
         * \param size           The size of the RenderTextureImpl
         * \param target         The target to use to render
         * \param useDepthBuffer True if a depth buffer is need, false otherwise
         *
         * \return Return true if the RenderTextureImpl was created successfully, false otherwise
         *
         */
        bool RenderTextureImpl::create(const Vector2UI& size, unsigned int target, bool useDepthBuffer)
        {
            return create(size.x, size.y, target, useDepthBuffer);
        }

        /*! \brief Default constructor
         *
         */
        RenderTextureImpl::RenderTextureImpl() :
            m_target(0)
        {
            /// Nothing
        }
    }
}
