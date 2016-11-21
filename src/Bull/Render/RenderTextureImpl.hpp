#ifndef Bull_RenderTextureImpl_hpp
#define Bull_RenderTextureImpl_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/Context.hpp>

namespace Bull
{
    namespace prv
    {
        class RenderTextureImpl : public NonCopyable
        {
        public:

            /*! \brief Destructor
             *
             */
            virtual ~RenderTextureImpl();

            /*! \brief Create the RenderTextureImpl
             *
             * \param size           The size of the RenderTextureImpl
             * \param target         The target to use to render
             * \param useDepthBuffer True if a depth buffer is need, false otherwise
             *
             * \return Return true if the RenderTextureImpl was created successfully, false otherwise
             *
             */
            bool create(const Vector2UI& size, unsigned int target, bool useDepthBuffer = false);

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
            virtual bool create(unsigned int width, unsigned int height, unsigned int target, bool useDepthBuffer = false) = 0;

            /*! \brief Activate or deactivate the context
             *
             * \param active True to activate, false to deactivate the context
             *
             * \return Return true if the context's status changed successfully, false otherwise
             *
             */
            bool setActive(bool active);

            /*! \brief Display what has been rendered so far into the target texture
             *
             */
            virtual void updateTarget() = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            RenderTextureImpl();

            /*! \brief Create the internal context
             *
             */
            void createInternalContext();

            /*! \brief Create the internal context
             *
             * \param mode     The VideoMode to use to create the context
             * \param settings Settings to use to create the context
             *
             */
            void createInternalContext(const VideoMode& mode, const ContextSettings& settings);

            unsigned int m_target;

        private:

            std::unique_ptr<Context> m_context;
        };
    }
}

#endif // Bull_RenderTextureImpl_hpp
