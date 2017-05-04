#ifndef BULL_ORTHOGRAPHICPROJECTION_HPP
#define BULL_ORTHOGRAPHICPROJECTION_HPP

#include <Bull/Math/Polygon/Rectangle.hpp>

#include <Bull/Utility/TransformationPipeline/Projection.hpp>

namespace Bull
{
    struct BULL_UTILITY_API OrthographicProjection : public Projection
    {
        /*! \brief Default constructor
         *
         */
        OrthographicProjection() = default;

        /*! \brief
         *
         * \param plan
         * \param zBounds
         *
         */
        OrthographicProjection(const RectangleF& plan, const Vector2F& zBounds);

        /*! \brief Convert the PerspectiveProjection to a Matrix4F
         *
         * \return The Matrix4F representing the projection
         *
         */
        Matrix4F toMatrix() const;

        RectangleF plan;
    };
}

#endif //BULL_ORTHOGRAPHICPROJECTION_HPP
