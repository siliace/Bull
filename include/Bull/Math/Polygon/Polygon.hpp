#ifndef BULL_POLYGON_HPP
#define BULL_POLYGON_HPP

#include <algorithm>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    class Rectangle;

    template<typename T>
    struct Polygon
    {
        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        virtual Vector2<T> getVertex(Index index) const = 0;

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        virtual Index getVertexCount() const = 0;

        /*! \brief Get a rectangle representing bounds of the polygon
         *
         * \return Bounds of the polygon
         *
         */
        Rectangle<T> getBounds() const;
    };
}

#include <Bull/Math/Polygon/Polygon.inl>

#endif // BULL_POLYGON_HPP
