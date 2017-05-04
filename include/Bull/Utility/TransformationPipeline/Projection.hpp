#ifndef BULL_PROJECTION_HPP
#define BULL_PROJECTION_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Utility/TransformationPipeline/Matrixable.hpp>

namespace Bull
{
    struct BULL_UTILITY_API Projection : public Matrixable
    {
        Vector2F zBounds;
    };
}

#endif //BULL_PROJECTION_HPP
