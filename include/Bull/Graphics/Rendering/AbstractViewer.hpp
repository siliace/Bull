#ifndef BULL_GRAPHICS_RENDERING_ABSTRACTVIEWER_HPP
#define BULL_GRAPHICS_RENDERING_ABSTRACTVIEWER_HPP

#include <Bull/Graphics/Rendering/Transformable.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Render/Target/RenderTarget.hpp>

namespace Bull
{
    struct BULL_GRAPHICS_API AbstractViewer
    {
        /*! \brief Resize the AbstractViewer
         *
         * Resizing the abstract viewer will change the plan or the ratio of the projection
         *
         * \param size The new Size
         *
         */
        virtual void resize(const Size<unsigned int>& size) = 0;

        /*! \brief Get the product of the projection matrix with the view matrix held by the AbstractViewer
         *
         * \return The projection-view matrix
         *
         */
        virtual Matrix4F getViewProjectionMatrix() const = 0;

        /*! \brief Get the projection-view matrix of a Transformable as seen by the AbstractViewer
         *
         * \param transformable The Transformable
         *
         * \return The projection-view matrix
         *
         */
        virtual Matrix4F getModelViewProjectionMatrix(const Transformable& transformable) const = 0;
    };
}

#endif // BULL_GRAPHICS_RENDERING_ABSTRACTVIEWER_HPP
