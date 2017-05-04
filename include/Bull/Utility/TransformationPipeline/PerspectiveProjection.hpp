#ifndef BULL_PERSPECTIVEPROJECTION_HPP
#define BULL_PERSPECTIVEPROJECTION_HPP

#include <Bull/Utility/TransformationPipeline/Projection.hpp>

namespace Bull
{
    struct BULL_UTILITY_API PerspectiveProjection : public Projection
    {
        /*! \brief Default constructor
         *
         */
        PerspectiveProjection();

        /*! \brief Constructor
         *
         * \param angle
         * \param ratio
         * \param zBounds
         *
         */
        PerspectiveProjection(const AngleF& angle, float ratio, const Vector2F& zBounds);

        /*! \brief Convert the PerspectiveProjection to a Matrix4F
         *
         * \return The Matrix4F representing the projection
         *
         */
        Matrix4F toMatrix() const override;

        AngleF angle;
        float  ratio;
    };
}

#endif //BULL_PERSPECTIVEPROJECTION_HPP
