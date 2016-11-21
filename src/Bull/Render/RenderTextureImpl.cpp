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

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool RenderTextureImpl::setActive(bool active)
        {
            if(m_context)
            {
                return m_context->setActive(active);
            }

            return false;
        }

        /*! \brief Default constructor
         *
         */
        RenderTextureImpl::RenderTextureImpl() :
            m_target(0)
        {
            /// Nothing
        }

        /*! \brief Create the internal context
         *
         */
        void RenderTextureImpl::createInternalContext()
        {
            if(!m_context)
            {
                m_context = std::make_unique<Context>();
            }
        }

        /*! \brief Create the internal context
         *
         * \param mode     The VideoMode to use to create the context
         * \param settings Settings to use to create the context
         *
         */
        void RenderTextureImpl::createInternalContext(const VideoMode& mode, const ContextSettings& settings)
        {
            if(!m_context)
            {
                m_context = std::make_unique<Context>(mode, settings);
            }
        }
    }
}
