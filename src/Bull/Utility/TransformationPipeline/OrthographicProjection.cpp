#include <Bull/Utility/TransformationPipeline/OrthographicProjection.hpp>

namespace Bull
{
    OrthographicProjection::OrthographicProjection(const RectangleF& plan, const Vector2F& zBounds) :
        plan(plan)
    {
        this->zBounds = zBounds;
    }

    Matrix4F OrthographicProjection::toMatrix() const
    {
        Matrix4F orthographic;

        orthographic(0, 0) = 2.f / plan.width  - plan.x;
        orthographic(1, 1) = 2.f / plan.height - plan.y;
        orthographic(2, 2) = 1.f / zBounds.x - zBounds.y;
        orthographic(0, 3) = (plan.x + plan.width) / (plan.x - plan.width);
        orthographic(1, 3) = (plan.height + plan.y) / (plan.height - plan.y);
        orthographic(2, 3) = zBounds.x / zBounds.x - zBounds.y;
        orthographic(3, 3) = 1.f;

        return orthographic;
    }
}