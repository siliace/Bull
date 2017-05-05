#include <Bull/Math/Constants.hpp>

#include <Bull/Utility/TransformationPipeline/PerspectiveProjection.hpp>

namespace Bull
{
    PerspectiveProjection::PerspectiveProjection() :
        ratio(0)
    {
        /// Nothing
    }

    PerspectiveProjection::PerspectiveProjection(const AngleF& angle, float ratio, const Vector2F& zBounds) :
        angle(angle),
        ratio(ratio)
    {
        this->zBounds = zBounds;
    }

    Matrix4F PerspectiveProjection::toMatrix() const
    {
        Matrix4F perspective;
        AngleF fov = AngleF::toRadian(angle) / 2.f;
        float yScale = std::tan(Pi2 - fov);

        perspective(0, 0) = yScale / ratio;
        perspective(1, 1) = yScale;
        perspective(2, 2) = -(zBounds.y + zBounds.x) / (zBounds.y - zBounds.x);
        perspective(2, 3) = -1.f;
        perspective(3, 2) = -2.f * (zBounds.x * zBounds.y) / (zBounds.y - zBounds.x);

        return perspective;
    }
}
