#ifndef BULL_MATH_POLYGON_POLYGON_HPP
#define BULL_MATH_POLYGON_POLYGON_HPP

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
        Rectangle<T> getBounds() const
        {
            T xMin, xMax, yMin, yMax;

            xMin = yMin = std::numeric_limits<T>::max();
            xMax = yMax = std::numeric_limits<T>::min();

            for(unsigned int i = 0; i < getVertexCount(); i++)
            {
                Vector2<T> vertex = getVertex(i);

                xMin = std::min(xMin, vertex.x);
                yMin = std::min(yMin, vertex.y);
                xMax = std::max(xMax, vertex.x);
                yMax = std::max(yMax, vertex.y);
            }

            return Rectangle<T>(xMin, yMin, xMax - xMin, yMax - yMin);
        }
    };
}

#endif // BULL_MATH_POLYGON_POLYGON_HPP
