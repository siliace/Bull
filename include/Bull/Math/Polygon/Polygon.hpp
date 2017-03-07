#ifndef BULL_POLYGON_HPP
#define BULL_POLYGON_HPP

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    class Rectangle;

    template<typename T>
    struct BULL_API Polygon
    {
        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        virtual Vector2<T> getVertex(std::size_t index) const = 0;

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        virtual std::size_t getVertexCount() const = 0;

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
