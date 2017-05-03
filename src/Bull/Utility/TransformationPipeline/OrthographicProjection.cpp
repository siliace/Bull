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

        float top    = plan.y;
        float left   = plan.x;
        float right  = plan.x + plan.width;
        float bottom = plan.y + plan.height;

        orthographic(0, 0) = 2.f / (right - left);

        orthographic(1, 1) = 2.f / (top - bottom);

        orthographic(2, 2) = 1.f / (zBounds.x - zBounds.y);

        orthographic(3, 0) = (left + right) / (left - right);
        orthographic(3, 1) = (top + bottom) / (bottom - top);
        orthographic(3, 2) = zBounds.x / (zBounds.x - zBounds.y);
        orthographic(3, 3) = 1.f;

        return orthographic;
    }
}