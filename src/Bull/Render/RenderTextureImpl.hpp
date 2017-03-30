#ifndef Bull_RenderTextureImpl_hpp
#define Bull_RenderTextureImpl_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Window/Context.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderTextureImpl : public NonCopyable
        {
            /*! \brief Create the RenderTextureImpl
             *
             * \param size   The size of the rendering target
             * \param target The rendering target
             *
             * \return Return true if the RenderTextureImpl was created successfully, false otherwise
             *
             */
            virtual bool create(const Vector2UI& size, unsigned int target) = 0;

            /*! \brief Display what has been rendered so far into the target texture
             *
             */
            virtual void updateTarget() = 0;
        };
    }
}

#endif // Bull_RenderTextureImpl_hpp
