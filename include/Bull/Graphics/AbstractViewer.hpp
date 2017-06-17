#ifndef BULL_ABSTRACTVIEWER_HPP
#define BULL_ABSTRACTVIEWER_HPP

#include <Bull/Graphics/Export.hpp>
#include <Bull/Graphics/ProjectionType.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

#include <Bull/Render/Target/RenderTarget.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API AbstractViewer
    {
        /*! \brief Get the eye's position
         *
         * \return The eye's position
         *
         */
        virtual Vector3F getEyePosition() const = 0;

        /*! \brief Get the target
         *
         * \return The target
         *
         */
        virtual Vector3F getTarget() const = 0;

        /*! \brief Get the ration of the projection
         *
         * \return The ratio
         *
         */
        virtual float getAspectRatio() const = 0;

        /*! \brief Get the up vector
         *
         * \return The up vector
         *
         */
        virtual Vector3F getUp() const = 0;

        /*! \brief Get the right vector
         *
         * \return The right vector
         *
         */
        virtual Vector3F getRight() const = 0;

        /*! \brief Get the forward vector
         *
         * \return The forward vector
         *
         */
        virtual Vector3F getForward() const = 0;

        /*! \brief Get the projection type
         *
         * \return The projection type
         *
         */
        virtual ProjectionType getProjectionType() const = 0;

        /*! \brief Get the view matrix
         *
         * \return The matrix
         *
         */
        virtual const Matrix4F& getViewMatrix() const = 0;

        /*! \brief Get the projection matrix
         *
         * \return The matrix
         *
         */
        virtual const Matrix4F& getProjectionMatrix() const = 0;

        /*! \brief Get the viewport
         *
         * \return The viewport
         *
         */
        virtual const RectangleUI& getViewport() const = 0;

        /*! \brief Get the projection's Z Far
         *
         * \return The Z Far
         *
         */
        virtual float getZFar() const = 0;

        /*! \brief Get the projection's Z Near
         *
         * \return The Z Near
         *
         */
        virtual float getZNear() const = 0;

        /*! \brief Get the RenderTarget where the Viwer is looking
         *
         * \return The RenderTarget
         *
         */
        virtual const RenderTarget* getTarget() const = 0;
    };
}

#endif //BULL_ABSTRACTVIEWER_HPP
