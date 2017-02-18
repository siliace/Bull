#ifndef BULL_POLYGON_HPP
#define BULL_POLYGON_HPP

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Polygon
    {
        virtual Vector2<T> getVertex(unsigned int index) const = 0;

        virtual unsigned int getVertexCount() const = 0;
    };
}

#endif // BULL_POLYGON_HPP
