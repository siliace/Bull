#ifndef BULL_PROJECTION_HPP
#define BULL_PROJECTION_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Utility/Export.hpp>

namespace Bull
{
    struct BULL_UTILITY_API Projection
    {
        /*! \brief Convert the Projection to a Matrix4F
         *
         * \return The Matrix4F representing the projection
         *
         */
        virtual Matrix4F toMatrix() const = 0;

        Vector2F zBounds;
    };
}

#endif //BULL_PROJECTION_HPP
